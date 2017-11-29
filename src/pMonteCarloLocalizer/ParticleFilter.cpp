#include <cmath>   // for trigonometry
#include <random>  // for probability distributions

#include "ParticleFilter.h"
//#include "flan/flan.hpp"
#include "range_libc/includes/RangeLib.h" // for sensor model, if we use raycasting method

// Utility function to sample from the normal dist.
// This might be more efficient by implementing the normal distribution from scratch, without std::sqrt
double MCL::sample(const double& variance){
  // function sample(variance) generates a random sample from a zero-centered distribution
  std::random_device rd;
  std::mt19937 gen(rd());
  double standard_deviation = std::sqrt(variance);
  std::normal_distribution<> dist(0, standard_deviation);
  return dist(gen);
}


  // TODO: This motion model is specifically for your torpedo-style AUV.
  /*
    Samples the motion model, as in Probabilistic Robotics ch5.
  
    inputs:
    control: denoted by uₜ in text. Probably thrust and rudder or ω from compass.
    state_previous: xₜ₋₁ in text = (x, y, z, θ).
    We're assuming roll and pitch are always zero.
    z is distance from ocean floor, probably average of sonar measurments.
    θ heading in radians from the compass.

    outputs:
    xₜ = a sample from the motion model. 

  */
// Motion model is based off of pHelmIvP's subscriptions, NAV_SPEED, NAV_HEADING, and NAV_DEPTH, to be as general as is possible. 
std::vector<double> MCL::sample_from_motion_model(const std::vector<double>& control, const std::vector<double>& state_previous, double apptick){
  // TODO: These are unused parameters that model the accuracy of the actuators. They decrease as accuracy increases. I don't know how I would extract them for a physical vehicle. 
  double a1 = 0.1, a2 = 0.1, a3 = 0.1, a4 = 0.1, a5 = 0.1, a6 = 0.1;


  // We aren't following the circular model as in the PR book, but using a simpler model
  double thrust = control[0];
  double rudder = control[1];        // TODO: consider using heading to obtain angular velocity ω
  double desired_depth = control[2]; //       and add depth to the motion model 

  double x = state_previous[0];
  double y = state_previous[1];
  double z = state_previous[2];
  double h = state_previous[3]; // heading in radians

  // We perturb the controls.
  // This lets us draw from the distribution of possible controls, taking actuator noise into account
  double pv = thrust + sample(a1*thrust + a2*rudder); // perturbed velocity
  double pw = thrust + sample(a3*thrust + a4*rudder); // perturbed angualr velocity
  double pg = sample(a5*thrust + a6*rudder); // this just keeps the system from being degenerate

  // calculate deltas.
  // TODO: these are crude calculations better suited for an ackerman model. Rethink this with subersibles in mind.
  double dt, dx, dy, dz, dh;
  dt = apptick;
  dx = pw == 0 ? 0: (pv/pw) * (-std::sin(h) + std::sin(h + pw*dt)); // avoid divide by zero error
  dy = pw == 0 ? 0: (pv/pw) *  (std::cos(h) - std::cos(h + pw*dt));
  dz = 0; // TODO: handle the third dimension
  dh = pw * dt + pg * dt;

  std::vector<double> sampled_state = {x + dx, y + dy, z + dz, h + pg};
  return sampled_state;
}

/* Compute likelihood of a range scan "sonar", assuming conditional independence between the individual range measurements in the scan.  */
// Assuming the plane of the sonar points towards "forward" in the auv. It 
double MCL::measurement_model(const std::vector<double>& sonar, const std::vector<double> state, MCL& carlito){
  // TODO: ¿ pass in file descriptor or path as map instead of a vector?

  // To include vehicle roll into model, bearing_beam += roll_veh. Yaw will require more trig. 

  // measurement x, y, and depth
  double vx, vy, vd, h, mx, my, md, b;
  vx = state[0];
  vy = state[1];
  vd = state[2];
  h = state[3]; // heading in radians
  b; // idk how to get beam bearing from measurement index; sonar specific. 

  // declare q = 1, which is what we return, but what is it? 
  for(double r : sonar){ // r = range detected by this sonar beam
    if( r < carlito.get_max_range()){ 
      my = vy + r * std::cos(b) * std::sin(h);
      mx = vx + r * std::cos(b) * std::cos(h);
      md = vd + r * std::sin(b);
      
      // then use flann to approximate the object nearest the detected point (my, mx, md)
      carlito.map_index();
      
      // finally do something with probability and q
    }    
  }

  //return q, whatever it is. 
  
}

std::vector<double> MCL::localize(const std::vector<double>& state_previous, const std::vector<double>& control, MCL& carlito){
  return std::vector<double> {};
}

//---------------------------------------------------------
// Utility methods

//double MCL::max_sonar_range(){ }
void MCL::map_index(){
  int foo = 42;
}

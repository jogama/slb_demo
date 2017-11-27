#include <cmath>   // for trigonometry
#include <random>  // for probability distributions
#include "ParticleFilter.h"
#include "range_libc/includes/RangeLib.h" // for sensor model

// Utility function to sample from the normal dist.
// This might be more efficient by implementing the normal distribution from scratch, without std::sqrt
double mcl::sample(const double& variance){
  // function sample(variance) generates a random sample from a zero-centered distribution
  std::random_device rd;
  std::mt19937 gen(rd());
  double standard_deviation = std::sqrt(variance);
  std::normal_distribution<> dist(0, standard_deviation);
  return dist(gen);
}

// Motion model is based off of pHelmIvP's subscriptions, NAV_SPEED, NAV_HEADING, and NAV_DEPTH, to be as general as is possible. 
std::vector<double> mcl::sample_from_motion_model(const std::vector<double>& control, const std::vector<double>& state_previous, double apptick){
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


double mcl::measurement_model(const std::vector<double>& sonar, const double& compass, const std::vector<double> state,
			 const std::vector< std::vector<int> >& map){
  // Set weights with which to mix the distribution.
  // Respectively, these are the probabliity of a beam
  //    landing on an expected object, landing on an unexpected object,
  //    multipath / missing obstacles, and random measurements.
  // TODO: implement algorithm to learn the weights (?).
  double w_correct = .25, w_short = .25, w_max = .25, w_rand = .25;
  
  std::random_device rd;
  std::mt19937 gen(rd());
  std::exponential_distribution<> d_hit(1); // lambda for P(x|l) = l*exp(-l*x)
  std::uniform_real_distribution<> d_short(1.0, 2.0); // uniform over [a, b) = [1, 2)
  std::uniform_real_distribution<> d_max(1.0, 2.0);
  std::normal_distribution<> d_rand(5,2); // mean = 5, standard dev = 2

  return 0.0;
}

std::vector<double> mcl::MCL(const std::vector<double>& state_previous, const std::vector<double>& control,
			const std::vector< std::vector<int> > map);

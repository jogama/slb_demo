#ifndef PartcilceFilter_HEADER
#define PartcilceFilter_HEADER

#include <vector>

namespace mcl{

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
  std::vector<double> sample_from_motion_model(const std::vector<double>& control, const std::vector<double>& state_previous, double apptick);

  // I'll probably use Corey's raycasting code for this one. I also don't understand how the map works here. 
  double measurement_model(const std::vector<double>& sonar, const double& heading, const std::vector<double> state,
			   const std::vector< std::vector<int> >& map);

  // Again, don't yet understand what to do with the map.
  // This is the particle filter. MCL = Monte Carlo Localization. 
  std::vector<double> MCL(const std::vector<double>& state_previous, const std::vector<double>& control,
			  const std::vector< std::vector<int> > map);

  // Utility function 
  double sample(const double& variance);
  // double sample(const& variance, std::function distribution);


#endif // PartcilceFilter_HEADER
}

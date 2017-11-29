#ifndef PartcilceFilter_HEADER
#define PartcilceFilter_HEADER

#include <vector>

/* I strongly resited making a class, but I really want a constructor. */
class MCL{
 public:
  MCL();
  ~MCL();
  static std::vector<double> sample_from_motion_model(const std::vector<double>& control, const std::vector<double>& state_previous, double apptick);
  static double measurement_model(const std::vector<double>& sonar, const std::vector<double> state, MCL& carlito);
  static std::vector<double> localize(const std::vector<double>& state_previous, const std::vector<double>& control, MCL& carlito);
      // Again, don't yet understand what to do with the map. This is the particle filter. 
  static double sample(const double& variance);
      // this doesn't need to be static, save for the other methods needing to access it.

  // Getters
  double max_sensor_range();
  
 protected:
  double max_sonar_range;
  double get_max_range(){ return max_sonar_range; };

};

#endif // PartcilceFilter_HEADER

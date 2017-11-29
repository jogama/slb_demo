/* Tests ParticleFilter.cpp */
#include <vector>
#include <iostream>
#include <random> 
#include "../ParticleFilter.h"

using namespace std;

int main(int argc, char** argv){
  if(argc != 9) {
    cout << "EXITING. Need exactly eight inputs.";
  }

  vector< double > state_previous;
  vector< double > control;
  double apptick;

  for(int i=1; i<argc; i++){
    if(i<=4)     state_previous.push_back(stod(argv[i]));
    if(i>4 && i<argc-1) control.push_back(stod(argv[i]));
    if(i == argc - 1) apptick = stod(argv[i]);
  }

  cout << "Testing function: sample_from_motion_model" << endl;
  auto state = mcl::sample_from_motion_model(control, state_previous, apptick);
  cout << "state = {" ;
  for(auto d : state) cout << d << ", ";
  cout << "}" << endl;

  cout << endl << "Testing function: measurement_model" << endl;
  vector<double> sonar_data = {};
  vector< std::vector<int> > map_i_think = {{}};
  auto w = mcl::measurement_model(sonar_data,
				      state_previous,
				      map_i_think);
  cout << "w = " << w << endl;

  return 0;
}

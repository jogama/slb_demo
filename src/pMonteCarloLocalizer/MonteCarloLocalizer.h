/************************************************************/
/*    NAME:                                                 */
/*    ORGN: MIT                                             */
/*    FILE: MonteCarloLocalizer.h                           */
/*    DATE:                                                 */
/************************************************************/

#ifndef MonteCarloLocalizer_HEADER
#define MonteCarloLocalizer_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class MonteCarloLocalizer : public CMOOSApp
{
 public:
   MonteCarloLocalizer();
   ~MonteCarloLocalizer();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected:
   void RegisterVariables();

 private: // Configuration variables

 private: // State variables
};

#endif 

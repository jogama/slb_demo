/****************************************************************/
/*   AUTH: Jonathan Garcia-Mallen                               */
/*   FILE: MonteCarloLocalizer_Info.cpp                         */
/****************************************************************/

#include <cstdlib>
#include <iostream>
#include "MonteCarloLocalizer_Info.h"
#include "ColorParse.h"
#include "ReleaseInfo.h"

using namespace std;

//----------------------------------------------------------------
// Procedure: showSynopsis

void showSynopsis()
{
  blk("SYNOPSIS:                                                       ");
  blk("------------------------------------                            ");
  blk("  The pMonteCarloLocalizer application is used for               ");
  blk("                                                                ");
  blk("                                                                ");
  blk("                                                                ");
  blk("                                                                ");
}

//----------------------------------------------------------------
// Procedure: showHelpAndExit

void showHelpAndExit()
{
  blk("                                                                ");
  blu("=============================================================== ");
  blu("Usage: pMonteCarloLocalizer file.moos [OPTIONS]                   ");
  blu("=============================================================== ");
  blk("                                                                ");
  showSynopsis();
  blk("                                                                ");
  blk("Options:                                                        ");
  mag("  --alias","=<ProcessName>                                      ");
  blk("      Launch pMonteCarloLocalizer with the given process name         ");
  blk("      rather than pMonteCarloLocalizer.                           ");
  mag("  --example, -e                                                 ");
  blk("      Display example MOOS configuration block.                 ");
  mag("  --help, -h                                                    ");
  blk("      Display this help message.                                ");
  mag("  --interface, -i                                               ");
  blk("      Display MOOS publications and subscriptions.              ");
  mag("  --version,-v                                                  ");
  blk("      Display the release version of pMonteCarloLocalizer.        ");
  blk("                                                                ");
  blk("Note: If argv[2] does not otherwise match a known option,       ");
  blk("      then it will be interpreted as a run alias. This is       ");
  blk("      to support pAntler launching conventions.                 ");
  blk("                                                                ");
  exit(0);
}

//----------------------------------------------------------------
// Procedure: showExampleConfigAndExit

void showExampleConfigAndExit()
{
  blk("                                                                ");
  blu("=============================================================== ");
  blu("pMonteCarloLocalizer Example MOOS Configuration                   ");
  blu("=============================================================== ");
  blk("                                                                ");
  blk("ProcessConfig = pMonteCarloLocalizer                              ");
  blk("{                                                               ");
  blk("  AppTick   = 4                                                 ");
  blk("  CommsTick = 4                                                 ");
  blk("                                                                ");
  blk("}                                                               ");
  blk("                                                                ");
  exit(0);
}


//----------------------------------------------------------------
// Procedure: showInterfaceAndExit

void showInterfaceAndExit()
{
  blk("                                                                ");
  blu("=============================================================== ");
  blu("pMonteCarloLocalizer INTERFACE                                    ");
  blu("=============================================================== ");
  blk("                                                                ");
  showSynopsis();
  blk("                                                                ");
  blk("SUBSCRIPTIONS:                                                  ");
  blk("------------------------------------                            ");
  blk("COMPASS_HEADING    double  [0.0, 360.0) heading reported by the compass     ");
  blk("SONAR_DATA                                                      ");  
  blk("  NODE_MESSAGE = src_node=alpha,dest_node=bravo,var_name=FOO,   ");
  blk("                 string_val=BAR                                 ");
  blk("                                                                ");
  blk("PUBLICATIONS:                                                   ");
  blk("------------------------------------                            ");
  blk("  Publications are determined by the node message content.      ");
  // copied from moos-ivp-kfish's GPSDeviceInfo
  blk("------------------------------------                                        ");
  blk("[prefix]_LATITUDE  double  Latitude parsed from recent NMEA sentence        ");
  blk("[prefix]_LAT       double  Copy of _LATITUDE");
  blk("[prefix]_LONGITUDE double  Longitude parsed from recent NMEA sentence       ");
  blk("[prefix]_LONG      double  Copy of _LONGITUDE");
  blk("[prefix]_X         double  X position in meters relative to the local origin");
  blk("[prefix]_Y         double  Y position in meters relative to the local origin");
  blk("[prefix]_SPEED     double  Speed in meters per second, provided by GPS      ");
  blk("                                                                ");
  exit(0);
}

//----------------------------------------------------------------
// Procedure: showReleaseInfoAndExit

void showReleaseInfoAndExit()
{
  showReleaseInfo("pMonteCarloLocalizer", "gpl");
  exit(0);
}


#include "CricketApp.h"
//Moose Includes
#include "MooseInit.h"
#include "Moose.h"
#include "MooseApp.h"
#include "AppFactory.h"

PerfLog Moose::perf_log("cricket");

int main(int argc, char *argv[])
{
  // Initialize MPI, solvers and MOOSE
  MooseInit init(argc, argv);
  CricketApp::registerApps();

  MooseApp * app = AppFactory::createApp("CricketApp", argc, argv);
  app->run();
  delete app;

  return 0;
}

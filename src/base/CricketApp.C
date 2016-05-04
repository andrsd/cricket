#include "CricketApp.h"
#include "Factory.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include <unistd.h>

template<>
InputParameters validParams<CricketApp>()
{
  InputParameters params = validParams<MooseApp>();
  params.set<bool>("use_legacy_output_syntax") = false;
  return params;
}

CricketApp::CricketApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  CricketApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);

  // turn off the legacy modes
  legacyUoAuxComputationDefault() = false;
  legacyUoInitializationDefault() = false;
}

CricketApp::~CricketApp()
{
}

// External entry point for dynamic application loading
extern "C" void CricketApp__registerApps() { CricketApp::registerApps(); }
void
CricketApp::registerApps()
{
  registerApp(CricketApp);
}

// External entry point for dynamic object registration
extern "C" void CricketApp__registerObjects(Factory & factory) { CricketApp::registerObjects(factory); }
void
CricketApp::registerObjects(Factory & factory)
{
}

void
CricketApp::run()
{
  // yes! no reproducibility
  srand (time(NULL));

  while (true)
  {
    int n = rand() % 3 + 1;
    std::cerr << "*chirp*";
    for (unsigned int i = 1; i < n; i++)
      std::cerr << " *chirp*";
    std::cout << std::endl;

    // 7 is a lucky number
    unsigned int ms = (rand() % 7 + 1) * 1000000;
    usleep(ms);
  }
}

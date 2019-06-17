#include "FrogApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<FrogApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

FrogApp::FrogApp(InputParameters parameters) : MooseApp(parameters)
{
  FrogApp::registerAll(_factory, _action_factory, _syntax);
}

FrogApp::~FrogApp() {}

void
FrogApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"FrogApp"});
  Registry::registerActionsTo(af, {"FrogApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
FrogApp::registerApps()
{
  registerApp(FrogApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
FrogApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FrogApp::registerAll(f, af, s);
}
extern "C" void
FrogApp__registerApps()
{
  FrogApp::registerApps();
}

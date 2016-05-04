#ifndef CRICKETAPP_H
#define CRICKETAPP_H

#include "MooseApp.h"

class Factory;
class CricketApp;

template<>
InputParameters validParams<CricketApp>();

class CricketApp : public MooseApp
{
public:
  CricketApp(InputParameters parameters);
  virtual ~CricketApp();

  virtual void run();

  static void registerApps();
  static void registerObjects(Factory & factory);
};

#endif /* CRICKETAPP_H */

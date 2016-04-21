#include <iostream>
#include <string>
#include "nodeType.h"
#include "nodeArrType.h"

using namespace std;


nodeType::nodeType(double active,double primingval,double primesettingval,double activesettingval)
{
  setActivation(active);
  setPriming(val);
  setProbability();
}

//================================================================================================
void nodeType::setActivation(double active)
{
  if(active >= 0 and active <= 1)
    activation=active;
  else
    cerr << "Error: invalid value for activation - expects double between 0 and 1";
}

//================================================================================================
void nodeType::setPriming(double val)
{
  if(val>=0 and val<=1)
    priming=val;
  else
    cerr << "Error: invalid value for priming - expects double between 0 and 1";
}

//================================================================================================
void nodeType::setProbabilty()
{
  probability=(activation+probability)/2;    //if weird values occur, CHECK
                                             //AND MODIFY THIS FUNCTION
}

//================================================================================================
void nodeType::setPrimeSetting(int val)
{
  if(val>0 and val<1)
    primeSetting=val;
  else cerr << "Error: invalid value for primeSetting - expects double between 0 and 1";
}

//================================================================================================
void nodeType::setActivationSetting(int val)
{
  if(val>0 and val<1)
    activationSetting=val;
  else cerr << "Error: invalid value for activationSetting - expects double between 0 and 1";
}

//================================================================================================
double nodeType::getActivation()
{
  return activation;
}

//================================================================================================
double nodeType::getPriming()
{
  return priming;
}

//================================================================================================
double nodeType::getProbability()
{
  return probability;
}

//================================================================================================
double nodeType::getPrimeSetting()
{
  return primeSetting;
}

//================================================================================================
double nodeType::getActivationSetting()
{
  return activationSetting;
}

//================================================================================================
void prime()
{
  if(priming<.9)
    priming+=priming;        //to increase or decrease priming rate, mess with this.
  else priming=1;

  if(activation<.9)
    activation+=activationSetting;     //to increase or decrease activation rate, mess with this.
  else activation=1;

  setProbability();
}

//================================================================================================
void deactivate()
{
  activation=0;        //maybe activation-=.1, and then nodeArrType has deactivate
                       //function to call through in a loop and deactivate
		       //gradually in that manner? Like wherever a node is active,
		       //deactivate it a little.
}

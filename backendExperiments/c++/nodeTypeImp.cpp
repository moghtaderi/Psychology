#include <iostream>
#include <string>
#include "nodeType.h"
#include "nodeArrType.h"

using namespace std;


nodeType::nodeType(double active,double weightval,double primesettingval,double activesettingval)
{
  setMultiplier(active);
  setWeight(val);
  setProbability();
}

//================================================================================================
void nodeType::setMultiplier(double active)
{
  if(active >= 0 and active <= 1)
    multiplier=active;
  else
    cerr << "Error: invalid value for multiplier - expects double between 0 and 1";
}

//================================================================================================
void nodeType::setWeight(double val)
{
  if(val>=0 and val<=1)
    weight=val;
  else
    cerr << "Error: invalid value for weight - expects double between 0 and 1";
}

//================================================================================================
void nodeType::setProbabilty()
{
  probability=(multiplier+probability)/2;    //if weird values occur, CHECK
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
void nodeType::setMultiplierSetting(int val)
{
  if(val>0 and val<1)
    multiplierSetting=val;
  else cerr << "Error: invalid value for multiplierSetting - expects double between 0 and 1";
}

//================================================================================================
double nodeType::getMultiplier()
{
  return multiplier;
}

//================================================================================================
double nodeType::getWeight()
{
  return weight;
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
double nodeType::getMultiplierSetting()
{
  return multiplierSetting;
}

//================================================================================================
void prime()
{
  if(weight<.9)
    weight+=primeSetting;        //to increase or decrease weight rate, mess with this.
  else weight=1;

  if(multiplier<.9)
    multiplier+=multiplierSetting;     //to increase or decrease multiplier rate, mess with this.
  else multiplier=1;

  setProbability();
}

//================================================================================================
void deactivate()
{
  if(multiplier>(1+multiplierSetting))
    multiplier-=multiplierSetting;
  else multiplier=1;
}

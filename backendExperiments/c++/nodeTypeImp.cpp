#include <iostream>
#include <string>
#include "nodeType.h"

using namespace std;


nodeType::nodeType(double active,double weightval,double weightsettingval,double multipliersettingval)
{
  setMultiplier(active);
  setWeight(weightval);
  setWeightSetting(weightsettingval);
  setMultiplierSetting(multipliersettingval);
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
void nodeType::setProbability()
{
  probability=multiplier*weight;         //if weird values occur, CHECK
                                         //AND MODIFY THIS FUNCTION
}

//================================================================================================
void nodeType::setWeightSetting(double val)
{
  if(val>0 and val<1)
    primeSetting=val;
  else cerr << "Error: invalid value for primeSetting - expects double between 0 and 1";
}

//================================================================================================
void nodeType::setMultiplierSetting(double val)
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
void nodeType::prime()
{
  if(weight<1-primeSetting)
    weight+=primeSetting;        //to increase or decrease weight rate, mess with this.
  else weight=1;

  if(multiplier<1-multiplierSetting)
    multiplier+=multiplierSetting;     //to increase or decrease multiplier rate, mess with this.
  else multiplier=1;

  setProbability();
}

//================================================================================================
void nodeType::deactivate()
{
  if(multiplier>(1+multiplierSetting))
    multiplier-=multiplierSetting;
  else multiplier=1;
}

#include <iostream>
#include <string>
#include "nodeObjArr.h"
#include "nodeObj.h"

using namespace std;


/*****************************nodeType*******************************/
nodeType::nodeType(double active,double val)
{
  setActivation(active);
  setPriming(val);
  setProbability();
}

void nodeType::setActivation(double active)
{
  
}

void nodeType::setPriming(int val)
{
  priming=val;
}

void nodeType::setProbabilty()
{
  probability=(activation+probability)/2;    //if weird values occur, CHECK
                                             //AND MODIFY THIS FUNCTION
}

double nodeType::getActivation()
{
  return activation;
}

double nodeType::getPriming()
{
  return priming;
}

double nodeType::getProbability()
{
  return probability;
}


/*****************************nodeArrType****************************/
nodeArrType::nodeArrType(int nodeNum)
{

}

#include <iostream>
#include <string>
#include "nodeObjArr.h"
#include "nodeObj.h"

using namespace std;


nodeArrType::nodeArrType(int nodeNum)
{

}

void nodeArrType::setNumOfNodes(int num)
{
  if(!(num%2)) {
    numOfNodes=num;
  } else cerr << "Error: must have an even number of nodes";
}

int nodeArrType::getNumOfNodes()
{
  return numOfNodes;
}

void setNodeArray()
{

}

nodeType* nodeArrType::getNodeArray()
{
  //don't know what should go here, since it's a pointer
  //instead of a copiable value
}

nodeArrType::prime()
{

}

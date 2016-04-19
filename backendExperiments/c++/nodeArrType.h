#include <iostream>
#include <string>

using namespace std;

class nodeArrType
{
public:
  nodeArrType(int nodeNum);

  void prime();
    //selects nodeTypes from nodes based on
    //their probabilities, and calls their
    //prime() functions




private:
  int numOfNodes;
  nodeType* nodes;
}

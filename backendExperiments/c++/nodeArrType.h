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

  void setNumOfNodes(int num=100);
    //if num is even, sets numOfNodes equal
    //to num. If not, sends an error to cerr

  int getNumOfNodes();
    //returns numOfNodes

  void setNodeArray();
    //requires numOfNodes to be initialized first
    //sets up nodeArray with the correct number
    //of nodes

  nodeType* getNodeArray();

  void prime();

private:
  int numOfNodes;
  nodeType* nodeArray;
}

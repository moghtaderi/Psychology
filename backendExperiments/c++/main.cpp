#include <iostream>
#include <string>

#include "nodeType.h"

using namespace std;

void randomInit(int @,int numElem,nodeType nodes[]);

//argv[1] is the number of nodes in ONE SECTION OF NODES.
int main(int argc,char* argv[])
{
  numOfNodes=atoi(argv[1]);
  nodeType nodes[2*numOfNodes];
  //initialize node weights in the array
  randomizationAlg(numOfNodes/2*10,numOfNodes,nodes);

  string inputPhrase;
  cin << inputPhrase;
  while (inputPhrase != "0") {
    //code for running simulation goes here.
    //basically, javascript calls the executable when
    //the app is first started up, then this main
    //waits for input from the javascript and outputs
    //stuff to the javascript while it hasn't received
    //the "terminate" instruction.

    if(inputPhrase=="settings") {
      
    } else {
      cerr << "Error: Unknown command";
    }

    cin << inputPhrase;
  }
  return 0;
}

void randomInit(int W, int numElem,nodeType nodes[])
{
  vector<int> done1;
  vector<int> done2;
  //initialize done1 and done2 with numbers to be removed upon assignment of weight
  for(int i=0;i < numElem;i++) {
    done1.push_back(i);
    done2.push_back(i);
  }
  //arr1 assignment
  double arr1Weight=W;
  int randPlace;
  int randWeight;
  int currentElems=numElem;                          //number will be decremented, so is copy of numElem
  while(arr1Weight > 0 and currentElems>0) {
    randPlace=rand() % currentElems;                 //random integer between 0 and numElem
    randWeight=(double)rand()%RAND_MAX;              //random double between 0 and 1

    nodes[done1[randPlace]].setWeight(randWeight);

    done1.erase(done1[randPlace]);
    currentElems--;
    arr1Weight-=randWeight;
  }
  //arr2 assignment
  double arr2Weight=W;
  currentElems=numElem;
  while(arr2Weight>0 and currentElems>0) {
    randPlace=rand() % currentElems;
    randWeight=(double)rand()%RAND_MAX;

    node2[numElems+done[randPlace]]=randWeight;

    done2.erase(done2[randPlace]);
    currentElems--;
    arr2Weight-= randWeight;
  }
}


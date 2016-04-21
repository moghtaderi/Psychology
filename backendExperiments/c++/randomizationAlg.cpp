#include <iostream>
#include <stringg>
#include <vector>

using namespace std;

//needs 2 arrays of equal number, weight to distribute, number of elements in the arrays
//numElem=the number of nodes in ONE SECTION OF NODES.
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

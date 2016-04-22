#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

#include "nodeType.h"


using namespace std;

void randomInit(double ratio,int numElem,nodeType nodes[]);

int main()
{
  nodeType nodes[40];
  for(int i=0;i < 20;i++) {
    cout << nodes[i].getWeight() << ':' << nodes[i+20].getWeight() << endl;
  }
  cout << "\n\n\n";
  randomInit(.74,20,nodes);
  cout << "\n\n\n";
  for(int i=0;i < 20;i++) {
    cout << nodes[i].getWeight() << ':' << nodes[i+20].getWeight() << endl;
  }
  return 0;
}

//=======================================================================================
void randomInit(double ratio, int numElem,nodeType nodes[])
{
  srand(time(NULL));
  vector<int> done1;
  vector<int> done2;
  //initialize done1 and done2 with numbers to be removed upon assignment of weight
  for(int i=0;i < numElem;i++) {
    done1.push_back(i);
    done2.push_back(i);
  }
  //arr1 assignment
  double arr1Weight=(double)numElem/2;
  int randPlace;
  double randWeight1;
  double randWeight2;
  int currentElems=numElem;                      //number will be decremented, so is copy of numElem

  while(currentElems>0) {
    cout << "CURRENT ELEMS: " << currentElems << endl;
    randPlace=rand() % currentElems;             //random integer between 0 and numElem
    cout << "randPlace: " << randPlace << endl;
    randWeight1=(double)rand()/RAND_MAX;         //random double between 0 and 1
    cout << "randWeight1: " << randWeight1 << endl;

    if((randWeight1/ratio)<=1)
      randWeight2=randWeight1/ratio;
    else randWeight2=randWeight1*ratio;
    cout << "randWeight2: " << randWeight2 << endl;

    if(randWeight1>randWeight2) {
      nodes[done1[randPlace]].setWeight(randWeight1);
      nodes[numElem+done1[randPlace]].setWeight(randWeight2);
      done1.erase(done1.begin()+randPlace);
      currentElems--;
    } else {
      nodes[done1[randPlace]].setWeight(randWeight2);
      nodes[numElem+done1[randPlace]].setWeight(randWeight1);
      done1.erase(done1.begin()+randPlace);
      currentElems--;
    }
  }
}

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

#include "nodeType.h"

using namespace std;

void randomInit(int ratio,int numElem,nodeType nodes[]);
void changeSettings(nodeType nodes[],int* numNodes,int newNumNodes,double weightSetting,double multiplierSetting);
void primeDominant(nodeType nodes[],int numNodes);
void primeSecondary(nodeType nodes[],int numNodes);

int probabilitySkew=4;  //passed to primeDominant and primeSecondary to make sure
                        //one side is favored above the other

//argv[1] is the number of nodes in ONE SECTION OF NODES.
int main(int argc,char* argv[])
{
  int numOfNodes=atoi(argv[1]);
  double ratio=atoi(argv[2]);
  nodeType nodes[2*numOfNodes];
  //initialize node weights in the array
  randomInit(ratio,numOfNodes,nodes);

  string inputPhrase;
  cin >> inputPhrase;
  string outString;
  while (inputPhrase != "0") {
    //code for running simulation goes here.
    //basically, javascript calls the executable when
    //the app is first started up, then this main
    //waits for input from the javascript and outputs
    //stuff to the javascript while it hasn't received
    //the "terminate" instruction.

    int newNumNodes;        //for changeSettings - new number of nodes in array
    int weightSetting;      //for changeSettings - new weight change factor
    int multiplierSetting;  //for changeSettings - new multiplier change factor
    outString="";  //output at the end of each loop to update the js nodes
    if(inputPhrase=="settings") {
      cin >> newNumNodes;
      cin >> weightSetting;
      cin >> multiplierSetting;
      changeSettings(nodes,&numOfNodes,newNumNodes,weightSetting,multiplierSetting);
      randomInit(ratio,numOfNodes,nodes);
    } else if(inputPhrase=="primeDominant") {
      primeDominant(nodes,numOfNodes);
      outString+="{";
      for(int i=0;i < 2*numOfNodes;i++) {
        outString+=nodes[i].getWeight();
        outString+=",";
      }
      outString+="}";
    } else if(inputPhrase=="primeSecondary") {
      primeSecondary(nodes,numOfNodes);
      outString+="{";
      for(int i=0;i < 2*numOfNodes;i++) {
        outString+=nodes[i].getWeight();
        outString+=",";
      }
      outString+="}";
    } else {
      cerr << "Error: Unknown command";
    }

    cout << outString;
    cin >> inputPhrase;
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
    randPlace=rand() % currentElems;             //random integer between 0 and numElem
    randWeight1=(double)rand()/RAND_MAX;         //random double between 0 and 1

    if((randWeight1/ratio)<=1)
      randWeight2=randWeight1/ratio;
    else randWeight2=randWeight1*ratio;

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

void changeSettings(nodeType nodes[],int* numNodes,int newNumNodes,int weightSetting,int multiplierSetting)
{
  *numNodes=newNumNodes;
  nodes=new nodeType[2 * newNumNodes];
  for (int i=0;i < 2*newNumNodes;i++) {
    nodes[i].setWeightSetting(weightSetting);
    nodes[i].setMultiplierSetting(multiplierSetting);
  }
}
//=======================================================================================
void primeDominant(nodeType nodes[],int numNodes)
{
  srand(time(NULL));
  int nodesToActivate=numNodes/5;  //we will activate 1/5 the number of nodes.
  int randPlace;
  int prob;  //probability of selection
  while(nodesToActivate>0) {
    randPlace=rand()%(2*numNodes);
    if(randPlace<numNodes) {
      nodes[randPlace].prime();
    } else {
      
    }
  }
}

//=======================================================================================
void primeSecondary(nodeType nodes[],int numNodes)
{

}

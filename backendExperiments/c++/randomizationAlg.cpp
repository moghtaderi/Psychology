#include <iostream>
#include <stringg>
#include <vector>

using namespace std;

//needs 2 arrays of equal number, weight to distribute, number of elements in the arrays
void randomInit(int W, int numElem,int arr1[],int arr2[])
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

    arr1[done1[randPlace]]=randWeight;

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

    arr2[done[randPlace]]=randWeight;

    done2.erase(done2[randPlace]);
    currentElems--;
    arr2Weight-= randWeight;
  }

}

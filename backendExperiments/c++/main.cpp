#include <iostream>
#include <string>

#include "nodeType.h"
#include "nodeArrType.h"

using namespace std;

int main(int argc,char* argv[])
{
  nodeArrType Nodes(atoi(argv[1]));
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

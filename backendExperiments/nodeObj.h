#include <iostream>
#include <string>

using namespace std;

class nodeType
{
public:
  nodeType(double active=0,double priming=.5);
    //constructor

  void setActivation(double active);
    //sets activation to a value between 0 and 1:
    //0 is inactive, 1 is completely active

  void setPriming(double val);
    //sets priming to a value between 0 and 1:
    //this is the number that gets displayed
    //in the circles on the page.

  void setProbability();
    //sets probability based on priming and activation

  double getActivation();

  double getPriming();

  double getProbability();



private:
  int activation;        //increases probability when higher
  double priming;        //increased when primed
  double probability;    //determined by activation and priming together
}

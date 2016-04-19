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
    //probability's function will need to be adjusted
    //based on testing that happens

  double getActivation();
    //returns activation variable

  double getPriming();
    //returns priming variable

  double getProbability();
    //returns probability variable
  
  void prime();
    //primes node, increasing activation and priming
    //called by nodeArrType's prime() function

  void deactivate();
    //decreases activation when called
    //don't know how this one will work yet
    //maybe pass values for border color to the JS...?



private:
  //all values should be between 0 and 1 in simulation
  double activation;        //increases probability when higher
  double priming;        //increases when primed; affects probability
  double probability;    //determined by activation and priming together
}

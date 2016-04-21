#include <iostream>
#include <string>

using namespace std;

class nodeType
{
public:
  nodeType(double active=0,double primingval=.5,double primesettingval=.1,double activesettingval=.1);
    //constructor

  void setActivation(double active);
    //sets activation to a value between 0 and 1:
    //0 is inactive, 1 is completely active

  void setPriming(double val);
    //sets priming to a value between 0 and 1:
    //this is the number that gets displayed
    //in the circles on the front end page.

  void setProbability();
    //sets probability based on priming and activation
    //probability's function will need to be adjusted
    //based on testing that happens

  void setPrimeSetting(double val);
    //sets primeSetting

  void setActivationSetting(double val);
    //sets primeActivation

  double getActivation();
    //returns activation variable

  double getPriming();
    //returns priming variable

  double getProbability();
    //returns probability variable

  double getPrimeSetting();
    //returns primeSetting variable

  double getActivationSetting();
    //returns activationSetting variable
  
  void prime();
    //primes node, increasing activation and priming
    //called by nodeArrType's prime() function
    //due to the nature of prime(), setProbability has to
    //be called either directly after or within this.

  void deactivate();
    //decreases activation when called
    //don't know how this one will work yet
    //maybe pass values for border color to the JS...?



private:
  //all values should be between 0 and 1 in simulation
  double activation;        //increases probability when higher
  double priming;           //increases when primed; affects probability
  double probability;       //determined by activation and priming together
  double primeSetting;      //how much priming increases when prime() is called
  double activationSetting; //how much activation increases when prime() is called
}

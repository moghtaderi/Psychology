#include <iostream>
#include <string>

using namespace std;

class nodeType
{
public:
  nodeType(double active=1,double weightval=.5,double primesettingval=.1,double activesettingval=.1);
    //constructor

  void setMultiplier(double active);
    //sets multiplier to a value between 0 and 1:
    //0 is inactive, 1 is completely active

  void setWeight(double val);
    //sets weight to a value between 0 and 1:
    //this is the number that gets displayed
    //in the circles on the front end page.

  void setProbability();
    //sets probability based on weight and multiplier
    //probability's function will need to be adjusted
    //based on testing that happens

  void setWeightSetting(double val);
    //sets primeSetting

  void setMultiplierSetting(double val);
    //sets primeMultiplier

  double getMultiplier();
    //returns multiplier variable

  double getWeight();
    //returns weight variable

  double getProbability();
    //returns probability variable

  double getPrimeSetting();
    //returns primeSetting variable

  double getMultiplierSetting();
    //returns multiplierSetting variable
  
  void prime();
    //primes node, increasing multiplier and weight
    //called by nodeArrType's prime() function
    //due to the nature of prime(), setProbability has to
    //be called either directly after or within this.

  void deactivate();
    //decreases multiplier when called
    //don't know how this one will work yet
    //maybe pass values for border color to the JS...?



private:
  double multiplier;        //increases probability when higher - minimum is 1
  double weight;           //increases when primed; affects probability
  double probability;       //determined by multiplier and weight together
  double primeSetting;      //how much weight increases when prime() is called
  double multiplierSetting; //how much multiplier increases when prime() is called
};

#include <iostream>
#include <stringg>

using namespace std;

//needs 2 arrays of equal number, weight to distribute
void randomInit(mass,arr1,arr2)
{

}



// Allocates probability mass W randomly to n  variables a1, a2, ... , an
// subject to constraints that, a1+ a2 + ... + an = W and for all 0<= i <= n, 0.0 <= ai <= 1.0
// Input:  total probability mass 0 <= W  <= n to distribute to n variables
// Output: updated values of the ai variables
U ← {}; J ← {1,2,...,n}   // set of variable indices used so far, and to be used/to draw from

// repeat while still some weight to allocate and more than a left to set
while |J| >1 and 0 <  W and W <  |J| 
// prevents low indices from always being ones that have more freedom 
  choose index j from set J at random  
  remove index j from set J and add to set U
  do 
    set aj to random decimal value between 0.0 and 1.0
  while W - aj > |J|  // prevents choosing too small a value for aj 
        // reduce weight left to be distributed
  W ←W - aj
  divide remaining weight W among remaining variables whose index is still in J 

Note: Consider using small fudge factor g to subtract and add to bound for outer while loop, i.e.
while |J| >1 and 0 <  W - g and W + g <  |J| ?

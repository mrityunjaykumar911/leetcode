//
// Created by mrityunjaykumar on 2019-09-20.
//

# include "../../common.h"

#include <cmath>

class Solution{
 public:
  short find_MSB_position(unsigned long long int x) {
    short k = short(log2 (x));
	return k;
  }
  
  short find_LSB_position(unsigned long long int x) {
  
  }
  
  short doCountParity(unsigned long long int x) {
    short result=0;
    while (x){
      result ^= 1;
      x = x&(x-1);
    }
	return result;
  }
};

void solve_CountParity (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  
  auto answer = s->doCountParity (177);
  /*
   answer == 0 => Even parity
   answer == 1 => Odd parity
   
   * */
  assert (answer == 0);
}
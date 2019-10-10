//
// Created by mrityunjaykumar on 2019-08-21.
//

# include "../../common.h"

class Solution {
 public:
  int mySqrt (int x) {
	if (x <= 4) {
	  if (x < 1) return 0;
	  if (x == 1) return 1;
	  if (x <= 3) return 1;
	  if (x <= 4) return 2;
	}
	int last_sq = 0;
	for (int i = 2; i <= (x / 2 + 1); i++) {
	  long long int this_sq = i;
	  this_sq *= i;
	  if (x < this_sq) return i - 1;
	}
	return -1;
  }
};

void solve_MySqrtimpl (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  
  auto answer = s->mySqrt (0);
  assert (answer == 0);
}
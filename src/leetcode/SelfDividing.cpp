//
// Created by mrityunjaykumar on 2019-08-08.
//

# include "../../common.h"

class Solution {
 public:
  bool divides (int k) {
    int num=k;
	bool ans = true;
	int digit;
	if(k % 10 == 0)
	  return false;
	while (k) {
	  digit = k % 10;
	  if (digit == 0) return false;
	  ans &= (num % digit == 0);
	  if(!ans)
		return false;
	  k /= 10;
	}
	return ans;
  }
  vector<int> selfDividingNumbers (int left, int right) {
	vector<int> ans;
	for (int i = left; i <= right; i++) {
	  if (divides (i))
	  {
	    ans.emplace_back (i);
	  }
	}
	return ans;
  }
};

void solve_SelfDividing (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  
  auto answer = s->selfDividingNumbers (101,112);
  std::cout << answer.size () << std::endl;
//  assert (answer == 0);
}
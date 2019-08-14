//
// Created by mrityunjaykumar on 2019-08-14.
//

# include "../../common.h"

class Solution {
 public:
  
  int rob (vector<int> &nums) {
      if(nums.size ()<=0)
          return 0;
	vector<int> DP (nums.size (), 0);
	int x=INT_MIN;
	for (int start=nums.size ()-1;start>=0;start--){
	  DP[start] += nums[start];
	  int temp=INT_MIN;
	  for (int i = start+2; i < nums.size (); ++i) {
		temp=max(DP[i],temp);
	  }
	  if(temp!=INT_MIN)
	  	DP[start]+=temp;
	  
	  x= max(DP[start],x);
	}
      if(x==INT_MIN)
          return 0;
	return x;
  }
};

void solve_RObNOw (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  vector<int> nums={2,1,1,3};
  vector<int> nums2={2,7,9,3,1};
  vector<int> nums3={1,2,1,1};
  
  
  auto answer = s->rob (nums);
  cout << answer << endl;
}
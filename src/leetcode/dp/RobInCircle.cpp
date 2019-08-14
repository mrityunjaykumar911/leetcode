//
// Created by mrityunjaykumar on 2019-08-14.
//

# include "../../common.h"

/*
 * Explain
 *
 * Now the question is how to rob a circular row of houses.
 * It is a bit complicated to solve like the simpler question.
 * It is because in the simpler question whether to rob num[lo] is entirely our choice.
 * But, it is now constrained by whether num[hi] is robbed.
 * However, since we already have a nice solution to the simpler problem. We do not want to throw it away.
 * Then, it becomes how can we reduce this problem to the simpler one.
 *
 * Actually, extending from the logic that if house i is not robbed,
 * then you are free to choose whether to rob house i + 1, you can break the circle by assuming a house is not robbed.
 * For example, 1 -> 2 -> 3 -> 1 becomes 2 -> 3 if 1 is not robbed.
 * Since every house is either robbed or not robbed and at least half of the houses are not robbed,
 * the solution is simply the larger of two cases with consecutive houses, i.e. house i not robbed,
 * break the circle, solve it, or house i + 1 not robbed. Hence, the following solution.
 *
 *
 */

class Solution1 {
public:
   int rob_simple (vector<int> &nums, int start,int end) {
      if(nums.size ()<=0)
          return 0;
	vector<int> DP (nums.size (), 0);
	int x=INT_MIN;
	for (int st=end;st>=start;st--){
	  DP[st] += nums[st];
	  int temp=INT_MIN;
	  for (int i = st+2; i < nums.size (); ++i) {
		temp=max(DP[i],temp);
	  }
	  if(temp!=INT_MIN)
	  	DP[st]+=temp;
	  
	  x= max(DP[st],x);
	}
      if(x==INT_MIN)
          return 0;
	return x;
  }
  int rob(vector<int> &nums){
   	if(nums.size ()<=0)
          return 0;
   	if(nums.size ()<=1)
          return nums[0];
	return max(rob_simple (nums,0,nums.size ()-2),rob_simple (nums,1,nums.size ()-1));
   }
};

void solve_RobInCircle (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution1 *s = new Solution1 ();
  
  vector<int> nums={2,1,1,3};
  vector<int> nums2={2,7,9,3,1};
  vector<int> nums3={2,7,9,3,4,1};
  
  
  auto answer = s->rob (nums3);
  cout << answer << endl;
}
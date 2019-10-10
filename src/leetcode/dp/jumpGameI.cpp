//
// Created by mrityunjaykumar on 2019-10-10.
//

# include "../../common.h"

int mini(int x,int y){
  return x<y?x:y;
}

class Solution {
 public:
  bool canJumpLast (int pos, vector<int> &nums) {
	if(pos >= nums.size()-1)
	  return true;
	
	int maxJumpFromHere = mini(pos+nums[pos], nums.size()-1);
	
	for(int p=pos+1;p<=maxJumpFromHere;p++){
	  if(canJumpLast (p,nums)){
		return true;
	  }
	}
    return false;
  }
  bool canJump1 (vector<int> &nums) {
	return canJumpLast(0,nums);
  }
};

void solve_jumpGameI (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  vector<int> nums = {2,3,1,1,4};
  auto answer = s->canJump1 (nums);
  assert (answer == true);
}
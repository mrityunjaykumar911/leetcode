//
// Created by mrityunjaykumar on 2019-08-21.
//

# include "../../common.h"

class Solution {
 public:
  void rotate_right_by_one (vector<int> &nums, int size) {
	int last = nums[size - 1];
	for (int i = size - 1; i > 0; i--) { nums[i] = nums[i - 1]; }
	nums[0] = last;
  }
  void rotate_non_optimal (vector<int> &nums, int k) {
	k = k % nums.size ();
	for (int i = 0; i < k; i++) { rotate_right_by_one (nums, nums.size ()); }
  }
  void swap (int &a, int &b) {
	int t = b;
	b = a;
	a = t;
  }
  void reverse (vector<int> &nums, int start, int endgr) {
	int L = start;
	int R = endgr - 1;
	while (L < R) {
	  swap (nums[L], nums[R]);
	  L++;
	  R--;
	}
  }
  void rotate (vector<int> &nums, int k) {
	int size = nums.size ();
	if (size == 0) return;
	k = k % size;
	reverse (nums, 0, size);
	reverse (nums, 0, k);
	reverse (nums, k, size);
  }
};

void solve_RotateArray (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  vector<int> nums = {1,2,3,4,5,6};
  s->rotate (nums,1);
}
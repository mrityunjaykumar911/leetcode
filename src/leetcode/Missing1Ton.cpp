//
// Created by mrityunjaykumar on 2019-07-24.
//

# include "../../common.h"


class Solution {
public:
    int missingNumber (vector<int> &nums) {
        int n = nums.size ();
        int ans = 1;
        int ans2 = 1;
        for (int i = 0; i <= n; i++) { ans2 ^= i; }
        for (auto &a:nums) { ans ^= a; }
        return ans2 ^ ans;
    }
};

void solve_Missing1Ton (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    auto answer = s->missingNumber (nums);
    assert (answer==8);
}
//
// Created by mrityunjaykumar on 2019-08-03.
//

# include "../../common.h"


class Solution {
public:
    int lengthOfLIS (vector<int> &nums) {
//        int *dp = new int[nums.size()];
        int n = nums.size ();
        if(nums.empty()){
            return 0;
        }
        if(n==1){
            return 1;
        }

        vector<int> dp(n);
        for (int j = 0; j < n; ++j) {
            dp[j] = 1;
        }
        int ans;

        for (int i = 1; i < n; ++i) {
            int this_value = nums[i];
            int max_now = INT_MIN;
            for (int j = 0; j < i; ++j) {
                if(this_value>nums[j]){
                    max_now=  max(max_now,dp[j]+1);
                }
            }
            if(max_now!=INT_MIN)
                dp[i]=max_now;
        }

        ans = *std::max_element (dp.begin (),dp.end());
//        delete[] dp;
        return ans;
    }
};

void solve_LISSolve (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();
    vector<int> numbers = {2,2};
    auto answer = s->lengthOfLIS (numbers);
    assert (answer==1);
}
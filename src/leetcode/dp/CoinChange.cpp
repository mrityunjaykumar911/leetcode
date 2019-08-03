//
// Created by mrityunjaykumar on 2019-07-24.
//

# include "../../common.h"

class Solution {
public:
    int dpUtilExponential(vector<int>& coins,int amount)
    {
        if(amount<0) return 0;
        if(amount==0) {
//            cout<<"yes"<<endl;
            return 0;
        }

        int res_min=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(coins[i] <= amount)
            {
                auto ans = dpUtilExponential (coins, amount - coins[i]);
                if (ans!=INT_MAX && ans+1 < res_min) {
                    res_min = ans+1;
                }
            }
        }
        return res_min;
    }

    int dpOnUtil (int *dp, vector<int> &coins, int amount) {
        for (int i = 1; i <= amount; ++i) {
            int min_now = INT_MAX;
            for (int v : coins) {
                if(i-v >=0 && i-v <=amount && dp[i-v]!=INT_MAX){
                    int temp = 1+dp[i-v];
                    if(temp < min_now && temp > 0){
                        min_now = temp;
                    }
                }
            }
            if (min_now <= 0) {
                dp[i]=0;
            }else{
                dp[i] = min_now;
            }
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        for (int i = 0; i <= amount; ++i) {
            dp[i]=INT_MAX;
        }
//        sort (coins.begin (),coins.end ());

        dp[0]=0;
//        auto ans= dpUtilExponential(coins, amount);
        auto ans = dpOnUtil(dp,coins,amount);
        return ans==INT_MAX?-1:ans;
    }
};

void solve_CoinChange (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();

    vector<int> nums={3,5,11,50};

    auto answer = s->coinChange (nums,7);
    cout<<answer<<endl;
    assert (answer==-1);
}
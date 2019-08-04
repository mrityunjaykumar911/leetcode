//
// Created by mrityunjaykumar on 2019-08-03.
//

# include "../../common.h"


class Solution {
public:
    bool wordBreakUtil (string &basicString, int start, int end_index,vector<bool> &dp, vector<string> &Dict,
            map<int,int> & processed) {
        if(end_index < start)
            return false;
        if(start == end_index)
            return true;
        for(auto &a:Dict){
            //cout << basicString.substr(start,a.size())<<endl;
            if (a[0]==basicString[start] && a==basicString.substr(start,a.size())) {
                //std::cout << start << " : " << a << std::endl;
                if(dp[start]==0){
                    if (processed.empty() || processed.find(start + a.size ())==processed.end ())
                        dp[start] = dp[start] || wordBreakUtil (basicString, start + a.size (), end_index, dp, Dict,processed);
                }
                processed[start]=end_index-start;
            }
        }
        return dp[start];
    }

    bool wordBreak (string s, vector <string> &wordDict) {
        int size = s.size();
        if(size==0){
            return false;
        }
        vector<bool> dp(size);
        map<int,int> processed;
        for (int i = 0; i < size; ++i) {
            dp[i] = false;
        }
        bool ans = wordBreakUtil (s,0,size,dp, wordDict,processed);
        return ans;
    }
};

void solve_WordBreakDPCpp () {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();
    string inp = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaba";//"applepenapppenapple";//"sandog";
    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};//{"cats","cat","dog","sand"};
//    string inp="cars";
//    vector<string> wordDict = {"car","ca","rs"};
    auto answer = s->wordBreak (inp, wordDict);
    cout << answer << endl;
}
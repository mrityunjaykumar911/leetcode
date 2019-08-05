//
// Created by mrityunjay kumar on 2019-08-05.
//
# include "../../common.h"


class Solution {
public:
    string toLowerCase(string str) {
        string ans;
        int x;
        for(char a:str){
            if(int('A')<=int(a) && int(a)<=int('Z')){
                x=int(a)-int('A')+int('a');
                ans+=char(x);
            }
            else{
                ans+=a;
            }
        }
        return ans;
    }
};

void solve_lowercase (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();
//    vector<int> numbers = {2,2};
    auto answer = s->toLowerCase ("Hello");
    assert (answer=="hello");
}
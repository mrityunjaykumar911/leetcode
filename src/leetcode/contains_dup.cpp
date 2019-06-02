//
// Created by mrityunjay kumar on 2019-06-01.
//

#include "../../common.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool answer = false;
        vector<int> prices(nums.begin (), nums.end ());

        vector<int>::iterator it;

        set<int> s;
        unsigned size = nums.size();
        for( unsigned i = 0; i < size; ++i ) s.insert( nums[i] );

        answer = nums.size() != s.size ();

        return answer;
    }
};

void solve_dup_problem(void)
{
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution();
    vector <int> numbers = {7,1,5,3,6,4,1};

    bool ans = s->containsDuplicate (numbers);
    cout << "Array contains Duplicate? : " << (ans?"True":"False") << endl;

}
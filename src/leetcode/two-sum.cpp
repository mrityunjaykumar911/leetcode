//
// Created by mrityunjay kumar on 2019-06-01.
//
#include "../../common.h"

bool comparator ( const pair<int,int>& l, const pair<int,int>& r) {
    return l.first < r.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        vector<pair <int, int>> nums_copy;

        for (vector<int>::iterator it = nums.begin(); it!=nums.end (); ++it) {
            int index = distance(nums.begin (),it);
            nums_copy.push_back (make_pair(*it, index));
        }
        // sort the input array
        sort(nums_copy.begin (), nums_copy.begin () + nums_copy.size (), comparator);
        int leftPtr = 0;
        int rightPtr = nums_copy.size ()-1;
        bool found = false;

        while (leftPtr < rightPtr) {
            int curr_sum = nums_copy[leftPtr].first + nums_copy[rightPtr].first;
            if (curr_sum > target)
                rightPtr--;
            else if (curr_sum < target)
                leftPtr++;
            else {
                found = true;
                v.push_back (nums_copy[leftPtr].second);
                v.push_back (nums_copy[rightPtr].second);
                break;
            }
        }
        if(!found) {
            v.clear ();
            v.push_back (-1);
            v.push_back (-1);
        }
        return v;
    }
};

void solve_two_sum_problem(void) {
    Solution *s = new Solution();
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> answer;

    answer = s->twoSum (numbers, target);

    cout << "First Index " << answer.at (0) << endl;
    cout << "Second Index " << answer.at (1) << endl;
}
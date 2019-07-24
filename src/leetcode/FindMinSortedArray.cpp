//
// Created by mrityunjaykumar on 2019-07-18.
//

# include "../../common.h"


class Solution {
public:
    int findMinUtil (int *arr, int start, int end, int target) {
        int mid = (start+end)/2;

        return -1;
    }

    int search (vector<int> &nums, int target) {
        int n = nums.size();
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i];
        }
        auto x = findMinUtil(arr,0,n-1,target);
        delete []arr;
        return x;
    }
};

void solve_FindMinSortedArray (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    cout << strlen ("7b0a000$7f66f20f4e20$0\n7b0a000$7f66f20f4e20$0") << endl;
    Solution *s = new Solution ();
    vector<int> array = {4,5,6,7,0,1,2};
    auto answer = s->search (array, 7);

}
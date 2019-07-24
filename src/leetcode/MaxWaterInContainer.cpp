//
// Created by mrityunjaykumar on 2019-07-24.
//

# include "../../common.h"


class Solution {
public:
    int maxArea (vector<int> &height) {
        int n = height.size ();
        int l = 0;
        int r = n - 1;
        int area = 0;
        while (l < r) {
            area = max (area, min (height[l], height[r]) * (r - l));
            if (height[l] < height[r]) { l++; } else { r--; }
        }
        return area;
    }
};

void solve_MaxWaterInContainer (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();
    vector<int> water={1,8,6,2,5,4,8,3,7};
    auto answer = s->maxArea (water);

    cout << answer;
}
//
// Created by mrityunjaykumar on 2019-07-24.
//

# include "../../common.h"


class Solution {
public:
    int hammingWeight (uint32_t n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
};

void solve_CountOnesUint (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();

    auto answer = s->hammingWeight (4);
    assert (answer==2);
}
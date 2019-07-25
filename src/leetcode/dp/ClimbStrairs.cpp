//
// Created by mrityunjaykumar on 2019-07-24.
//

# include "../../common.h"


class Solution {
public:
    int climbStairs (int n) {
        int *arr = new int[n + 1];
        int x;
        if (n <= 2) {
            switch (n) {
                case 2:
                    x = 2;
                    goto error;
                case 1:
                    x = 1;
                    goto error;
                default:
                    x = 0;
                    goto error;
            }
        }
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        for (int i = 3; i <= n; i++) { arr[i] = arr[i - 1] + arr[i - 2]; }
        x = arr[n];
        error:
        delete[]arr;
        return x;
    }
};

void solve_ClimbStrairs (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();

    auto answer = s->climbStairs (6);
    assert (answer==13);

}
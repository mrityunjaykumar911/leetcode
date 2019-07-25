//
// Created by mrityunjaykumar on 2019-07-24.
//

# include "../../common.h"


class Solution {
public:
    uint32_t reverseBits (uint32_t num) {
        unsigned int count = sizeof (num) * 8 - 1;
        unsigned int reverse_num = num;
        num >>= 1;
        while (num) {
            reverse_num <<= 1;
            reverse_num |= num & 1;
            num >>= 1;
            count--;
        }
        reverse_num <<= count;
        return reverse_num;
    }
};

void solve_ReverseBits (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();

    auto answer = s->reverseBits (00000010100101000001111010011100);
    assert (answer==00111001011110000010100101000000);
}
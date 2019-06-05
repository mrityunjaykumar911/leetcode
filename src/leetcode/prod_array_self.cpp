//
// Created by mrityunjaykumar on 2019-06-05.
//

# include "../../common.h"


class Solution {
public:
    vector<int> productExceptSelf (vector<int> &nums) {
        vector<int> lProduct;
        vector<int> rProduct;
        vector<int> answer;

        int sum=1;
        // fill from left
        for (auto iter = nums.begin (); iter != nums.end (); ++iter) {
            sum = sum * (*iter);
            lProduct.push_back (sum);
        }
        sum = 1;
        for (auto iter = nums.rbegin (); iter != nums.rend (); ++iter) {
            sum = sum * (*iter);
            rProduct.push_back (sum);
        }
        // reverse
        reverse( rProduct.begin(), rProduct.end() );
        for (int i = 0; i < nums.size (); ++i) {
            if(i==0){
                // take from rProduct
                answer.push_back (rProduct[i+1]);
            }
            else if(i==nums.size ()-1) {
                // take from lProduct
                answer.push_back (lProduct[i-1]);
            }
            else {
                answer.push_back (lProduct[i-1] * rProduct[i+1]);
            }

        }
        return answer;
    }
};

void solve_prod_array_self (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();

    vector<int> numbers = {1, 2, 3, 4};

    auto answer = s->productExceptSelf (numbers);

    for (int & iter : answer) {
        cout << iter << " " ;
    }
    cout << endl;

}
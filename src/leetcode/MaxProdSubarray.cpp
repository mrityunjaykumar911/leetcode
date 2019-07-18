//
// Created by mrityunjaykumar on 2019-07-18.
//

# include "../../common.h"


class Solution {
public:
    int maxProduct_new(vector<int> &arr)
    {
        int a=INT_MIN;
        int b=INT_MIN;
        int c=INT_MIN;
        int ans = INT_MIN;
        int elem =0;

        for(auto &i:arr) {
            c = c*i;
            b = a*i;
            a = i;
        }
        return ans;
    }
    // Function to find maximum subarray product.
int maxProduct(vector<int> &arr)
{
        int n = arr.size ();
    int i;

    // As maximum product can be negative, so
    // initialize ans with minimum integer value.
    int ans = INT_MIN;

    // Variable to store maximum product until
    // current value.
    int maxval = 1;

    // Variable to store minimum product until
    // current value.
    int minval = 1;

    // Variable used during updation of maximum
    // product and minimum product.
    int prevMax;

    for (i = 0; i < n; i++) {

        // If current element is positive, update
        // maxval. Update minval if it is
        // negative.
        if (arr[i] > 0) {
            maxval = maxval * arr[i];
            minval = min(1, minval * arr[i]);
        }

        // If current element is zero, maximum
        // product cannot end at current element.
        // Update minval with 1 and maxval with 0.
        // maxval is updated to 0 as in case all
        // other elements are negative, then maxval
        // is 0.
        else if (arr[i] == 0) {
            minval = 1;
            maxval = 0;
        }

        // If current element is negative, then new
        // value of maxval is previous minval*arr[i]
        // and new value of minval is previous
        // maxval*arr[i]. Before updating maxval,
        // store its previous value in prevMax to
        // be used to update minval.
        else if (arr[i] < 0) {
            prevMax = maxval;
            maxval = minval * arr[i];
            minval = prevMax * arr[i];
        }

        // Update ans if necessary.
        ans = max(ans, maxval);

        // If maxval is zero, then to calculate
        // product for next iteration, it should
        // be set to 1 as maximum product
        // subarray does not include 0.
        // The minimum possible value
        // to be considered in maximum product
        // subarray is already stored in minval,
        // so when maxval is negative it is set to 1.
        if (maxval <= 0) {
            maxval = 1;
        }
    }

    return ans;
}
    int maxProduct888(vector<int> &a)
    {
        int max_so_far = INT_MIN, max_ending_here = 1;

        for (int i : a)
        {
            max_ending_here = max_ending_here * i;
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;

//            if (max_ending_here < 0)
//                max_ending_here = 0;
        }
        return max_so_far;
    }

    int maxProduct4 (vector<int> &nums) {
        int st1 = 1;
        int st2 = 1;
        int curr =1;
        int prev = 1;
        int global_max_yet = INT_MIN;

        for (auto &x:nums){
            if(!(st1==1 && st2==1))
                global_max_yet = max(st1>st2?st1:st2,global_max_yet);
            st1 = st1*x;
            st2 = x*prev;
            global_max_yet = max(st1,global_max_yet);
            global_max_yet = max(global_max_yet,st2);
            prev = x;
        }
        return global_max_yet;
    }
    int maxProduct2 (vector<int> &nums) {
        vector<vector<int> > vect;
        int m = nums.size (), n =  nums.size ();

        vector<vector<int>> vec(m, vector<int> (n, INT_MIN));
        int max_yet = INT_MIN;

        for (int i = 0; i < nums.size (); ++i) {
            auto prod_yet = nums[i];
            vec[i][i] = prod_yet;
            if(vec[i][i]>max_yet){
                max_yet = vec[i][i];
            }
            for (int j = i+1; j < nums.size () && i<j; ++j) {
                prod_yet *= nums[j];
                vec[i][j] = prod_yet;
                if(vec[i][j]>max_yet){
                    max_yet = vec[i][j];
                }
            }
        }
        return max_yet;
    }
};

void solve_MaxProdSubarray (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    auto *s = new Solution ();
    vector<int> arr = {-1,-2,-9,-6};//{2,3,-2,4};//{2,-5,-2,-4,3};//{2,3,-2,4};
    auto answer = s->maxProduct (arr);
    assert (answer==108);
    arr = {2,3,-2,4};//{2,-5,-2,-4,3};//{2,3,-2,4};
    answer = s->maxProduct (arr);
    assert (answer==6);
    arr = {2,-5,-2,1,20};
    answer = s->maxProduct (arr);
    assert (answer==400);

    cout << answer;
}
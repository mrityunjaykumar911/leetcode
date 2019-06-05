//
// Created by mrityunjaykumar on 2019-06-05.
//

# include "../../common.h"

bool positive(int x) {
    return x>0;
}

bool negative(int x) {
    return x<0;
}

bool zero(int x) {
    return x==0;
}

class Solution {
public:
    bool check_if_all_same_sign(vector<int> numbers, bool (*func)(int)){
        bool answer = true;
        for (auto wrapIter = numbers.begin (); wrapIter != numbers.end (); ++wrapIter) {
            if(!func(*wrapIter))
                answer = false;
        }
        return answer;
    }

    int handle_positive (vector<int> &vector) {
        int sum=0;
        for (auto wrapIter = vector.begin (); wrapIter != vector.end (); ++wrapIter) {
            sum += *wrapIter;
        }
        return sum;
    }

    int handle_negative (vector<int> &vector) {
        int max = INT_MIN;
        for (auto wrapIter = vector.begin (); wrapIter != vector.end (); ++wrapIter) {
            if(max < *wrapIter)
                max = *wrapIter;
        }
        return max;
    }

    int maxSubArray (vector<int> &nums) {
        int answer=0;


        // check all three precondition
        // 1. all are positive
        if(this->check_if_all_same_sign (nums, positive)) {
            return this->handle_positive(nums);
        }
        // 2. all are negative
        if(this->check_if_all_same_sign (nums, negative)) {
            return this->handle_negative(nums);
        }
        // 3. all are zeros
        if(this->check_if_all_same_sign (nums, zero)) {
            return 0;
        }

        int max_sum_till_now=0,sum_yet=0;
        int first_positive_index=-1;


        for (int i = 0; i < nums.size (); ++i) {
            if(nums[i]>0){
                first_positive_index = i;
                sum_yet = nums[i];
            }

            for (int j = i+1; first_positive_index !=-1 && j < nums.size (); ++j) {
                if(max_sum_till_now < sum_yet)
                        max_sum_till_now = sum_yet;

                sum_yet+= nums[j];
                if(sum_yet <= 0){


                    i = first_positive_index+1;
                    first_positive_index = -1;
                    break;
                }
            }
            if(max_sum_till_now < sum_yet)
                        max_sum_till_now = sum_yet;
            sum_yet = 0;
            first_positive_index = -1;
        }


        return max_sum_till_now;
    }
};

void solve_max_subarray_easy (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    Solution *s = new Solution ();

    vector<int> numbers = {-2,1};//,-3,4,-1,2,1,-5,4};

    auto answer = s->maxSubArray (numbers);
    cout << "Answer is : " << answer << endl;

    delete (s);
}
//
// Created by mrityunjay kumar on 2019-07-18.
//
# include "../../common.h"

class Solution {
public:
    int findMinUtil(const int* arr, int start, int end, int target)
    {
        int mid = (start+end)/2;
        int x=target;
        int s=arr[start];
        int e=arr[end];
        int m=arr[mid];
        if(start==end){
            return arr[start]==target?start:-1;
        }
        if(m==x){
            return mid;
        }
        if(x == s){
            return start;
        }
        if(x == e){
            return end;
        }

        if(x <= m && x <= e){
            // goto m,e
            return findMinUtil (arr, mid+1, end, target);
        }else if(s <= x && x <= m){
            // goto s,m
            return findMinUtil (arr, start, mid-1, target);
        }
        return -1;

    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<=0){
            return -1;
        }
        if(n==1){
            return nums[0]==target?0:-1;
        }
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i];
        }
        auto x = findMinUtil(arr,0,n-1,target);
        delete []arr;
        return x;
    }
};

void solve_search_minrotatedarray (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    auto *s = new Solution ();
    vector<int> arr = {4,5,6,7,0,1,2};
    auto answer = s->search (arr, -1);
    assert (answer==-1);
    answer = s->search (arr, 0);
    assert (answer==4);
    answer = s->search (arr, 1);
    assert (answer==5);
    answer = s->search (arr, 2);
    assert (answer==6);
    answer = s->search (arr, 3);
    assert (answer==-1);
    answer = s->search (arr, 4);
    assert (answer==0);
    answer = s->search (arr, 5);
    assert (answer==1);
    answer = s->search (arr, 6);
    assert (answer==2);
    answer = s->search (arr, 7);
    assert (answer==3);
    answer = s->search (arr, 8);
    assert (answer==-1);



    cout << answer;
}
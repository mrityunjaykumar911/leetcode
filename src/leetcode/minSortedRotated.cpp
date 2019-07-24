//
// Created by mrityunjay kumar on 2019-07-18.
//
# include "../../common.h"

class Solution {
public:
    int findMinUtil(int* arr, int start, int end)
    {
        int mid = (start+end)/2;
        //printf("mid=%d\n",mid);
        if(mid==start){
            return min(arr[start],arr[end]);
//            return arr[start]<arr[end]?start:end;//min(arr[start],arr[end]);
        }
        if(arr[mid-1]>arr[mid] && arr[mid]<arr[mid+1]){
            return arr[mid];
        }else{
            if(arr[mid]<arr[start]){
                return findMinUtil(arr,start,mid-1);
            }else if(arr[start]<arr[mid] && arr[start]<arr[end]){
                return arr[start];
            }
            else{
                return findMinUtil(arr,mid+1,end);
            }
        }
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i];
        }
        auto x = findMinUtil(arr,0,n-1);
        delete []arr;
        return x;
    }
};

void solve_minrotatedarray (void) {
    cout << endl << "Running the problem " << __func__ << endl;
    auto *s = new Solution ();
    vector<int> arr = {4, 5, 6,7,0};//{2,3,-2,4};//{2,-5,-2,-4,3};//{2,3,-2,4};
    auto answer = s->findMin (arr);
//    assert (answer==108);
//    arr = {2,3,-2,4};//{2,-5,-2,-4,3};//{2,3,-2,4};
//    answer = s->maxProduct (arr);
//    assert (answer==6);
//    arr = {2,-5,-2,1,20};
//    answer = s->maxProduct (arr);
//    assert (answer==400);

    cout << answer;
}
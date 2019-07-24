//
// Created by mrityunjaykumar on 2019-07-18.
//

# include "../../common.h"


class Solution {
public:
    int findPivot(vector<int>& arr,int start,int end)
    {
        if(start>end) return -1;
        if(start==end) return start;
        int mid = (end+start)/2;
        if(mid<end && arr[mid]>arr[mid+1])
            return mid;
        if(mid>start && arr[mid]<arr[mid-1])
            return mid-1;
        if(arr[start]>=arr[mid])
            return findPivot (arr, start, mid-1);
        else
            return findPivot (arr,mid+1,end);
    }

    int binarySearch (vector<int> &vector, int start, int end, int target) {
        if(end<start)
            return -1;
        int mid=(start+end)/2;
        if(vector[mid]==target)
            return mid;
        if(vector[mid]>target)
        {
            //left
            return binarySearch (vector,start,mid-1,target);
        }else{
            return binarySearch (vector,mid+1,end,target);
        }
    }

    int findMinUtil(vector<int>& nums,int target)
    {
        int n=nums.size ();
        int pivot=findPivot (nums,0,n-1);
        if(pivot==-1)
            return binarySearch(nums,0,n-1,target);
        if(nums[pivot]==target)
            return pivot;
        if(nums[0]<=target)
            return binarySearch(nums,0,pivot-1,target);
        else
            return binarySearch(nums,pivot+1,n-1,target);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<=0){
            return -1;
        }
        if(n==1){
            return nums[0]==target?0:-1;
        }
//        int *arr = new int[n];
//        for (int i = 0; i < n; ++i) {
//            arr[i] = nums[i];
//        }
        auto x = findMinUtil(nums,target);
//        delete []arr;
        return x;
    }
};

void solve_FindMinSortedArray (void) {
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
    arr = {1,2,3,4,5,6};
    assert (s->search (arr,4)==3);
    arr = {4,5,6,7,8,1,2,3};
    assert (s->search (arr,8)==4);

    cout << answer;

}
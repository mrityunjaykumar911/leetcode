//
// Created by mrityunjaykumar on 2019-08-24.
//

# include "../../common.h"

bool even_odd_com(int a,int b){
  bool aodd = a%2;
  bool bodd = b%2;
  
  if(aodd && bodd){
    // both odd
	return a<b;
  } else if(!aodd && !bodd){
    // both even
	return a<b;
  } else{
    // a --> 9 , b --> 10
    if(aodd)
	  return 0;
	if(bodd)
	  return 1;
  }
}

class Solution{
  public:
  void doEvenOddSort(vector<int>& nums){
  	sort(nums.begin(),nums.end (),even_odd_com);
  }
};

void solve_EvenOddSort (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  
  vector<int> nums={1,5,-12,2,3,5,9,0};
  // -12,0,2,1,3,5,5,9
  s->doEvenOddSort (nums);
  
  for(auto &a:nums){
    cout << a << " ";
  }
}
/*

 void swap_all_four(int &a,int &b,int &c,int &d){
    int t = a;
    a=d;
    d=c;
    c=b;
    b=a;
    d=t;
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n<=1)
            return;
        for(int start=0,end=4;start<end;start++,end--){
            for(i=0;i<(end-start);i++){
                swap_all_four(matrix[start][start+i],
                          matrix[start+i][end],
                          matrix[end][end-i],
                          matrix[end-i][start]);
            }
            // swap_all_four(matrix[start][start],
            //               matrix[start][end],
            //               matrix[end][end],
            //               matrix[end][start]);
            // swap_all_four(matrix[start][start+1],
            //               matrix[start+1][end],
            //               matrix[end][end-1],
            //               matrix[end-1][start]);
            // swap_all_four(matrix[start][start+2],
            //               matrix[start+2][end],
            //               matrix[end][end-2],
            //               matrix[end-2][start]);
            // swap_all_four(matrix[start][start+3],
            //               matrix[start+3][end],
            //               matrix[end][end-3],
            //               matrix[end-3][start]);
        }
    }
};
 */
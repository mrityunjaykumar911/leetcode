//
// Created by mrityunjaykumar on 2019-09-21.
//

# include "../../common.h"

class Solution{
 public:
  vector<vector<int>> doSortDiag(vector<vector<int>>&arr){
    int r = arr.size ();
    int c = arr[0].size();
    /*
     00 01 02 03 04
     10 11 12 13 14
     20 21 22 23 24
     30 31 32 33 34
     * */
    
    for(int col=0;col<c;col++){
      int prev = col;
      vector<int> temp;
      for(int x=0,y=prev;x<r&&y<c;x++,y++){
      	temp.emplace_back (arr[x][y]);
      }
      int start = 0;
      sort(temp.begin (),temp.end ());
      for(int x=0,y=prev;x<r&&y<c;x++,y++){
      	arr[x][y] = temp[start++];
      }
    }
    
    for(int row=1;row<r;row++){
      int prev = row;
      vector<int> temp;
      for(int x=0,y=prev;x<c&&y<r;x++,y++){
      	temp.emplace_back (arr[y][x]);
      
      }
      int start = 0;
      sort(temp.begin (),temp.end ());
      for(int x=0,y=prev;x<c&&y<r;x++,y++){
      	arr[y][x] = temp[start++];
      }
    }
    
    
	return arr;
  }
};

void solve_DiagonalSort (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  vector<vector<int>> vec(4, vector<int> (5, 0));
  vec[0] = {5,4,3,2,1};
  vec[1] = {1,2,3,4,5};
  vec[2] = {5,4,3,2,1};
  vec[3] = {1,2,3,4,5};
  

  auto answer = s->doSortDiag (vec);
  for(auto &a: vec){
    for(auto &b:a){
      cout << b << ":";
    }
    cout << std::endl;
  }
}
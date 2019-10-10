//
// Created by mrityunjaykumar on 2019-08-24.
//

# include "../../common.h"

void swap_all_four (int &a, int &b, int &c, int &d) {
  int t = a;
  a = d;
  d = c;
  c = b;
  b = t;
}
class Solution {
 public:
  void rotate (vector<vector<int>> &matrix) {
	int n = matrix.size ();
	if (n <= 1) return;
	for (int start = 0, end = n - 1; start < end; start++, end--) {
	  for (int i = 0; i < (end - start); i++) {
		
		// first
		// 00,04,44,40
		swap_all_four(matrix[start][start+i],
                          matrix[start+i][end],
                          matrix[end][end-i],
                          matrix[end-i][start]);
	  }
	}
  }
};

void solve_RotateBy90 (void) {
  cout << endl << "Running the problem " << __func__ << endl;
//  vector<vector<int>> DP (3, vector<int> (3, '\0'));
  vector<vector<int>> DP = {{1,2,3,4},
							{5,6,7,8},
							{9,10,11,12},
							{13,14,15,16}};
  Solution *s = new Solution ();
  
  s->rotate (DP);
  for(auto &row:DP){
    for(auto &c:row){
      cout << c << " ";
    }
    cout << endl;
  }
}
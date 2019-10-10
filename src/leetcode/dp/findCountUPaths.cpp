//
// Created by mrityunjaykumar on 2019-10-10.
//

# include "../../common.h"

class Solution{
 public:
  int uniquePaths (int m, int n) {
	vector<vector<int>> DP (m, vector<int> (n, 1));
	// move right
	// move right
	for(int i=1;i<m;i++) {
	  for(int j=1;j<n;j++) {
		DP[i][j] = DP[i-1][j]+DP[i][j-1];
	  }
	}
	return DP[m-1][n-1];
  }
};
  
  void solve_findCountUPaths (void) {
	cout << endl << "Running the problem " << __func__ << endl;
	Solution *s = new Solution ();
	
	auto answer = s->uniquePaths (2,2);
	assert (answer == 2);
  }
//
// Created by mrityunjaykumar on 2019-08-22.
//

# include "../../common.h"

class Solution {
 public:
  string convert (string s, int numRows) {
	int m = numRows;
	int n = s.length ();
	string ans = "";
	vector<vector<char>> DP (m, vector<char> (n, '\0'));
	int k = 0;
	for (int col = 0; col < n && k<n; col++) {
	  if (col % 2 == 0) {
		for (int row = 0; row < m && k<n; row++) {
		  DP[row][col] = s[k++];
		}
	  }
	  else {
	    if(m>2) {
		  int num_entries = m - 2;
		  for (int row = num_entries; row > 0 && k < n; row--) {
			DP[row][col] = s[k++];
		  }
		}else if(m<=2){
	      DP[0][col] = s[k++];
	    }
	  }
	}
	for (int r = 0; r < m; r++) {
	  for (int c = 0; c < n; c++) {
		if (DP[r][c] != '\0') {
//		  cout << DP[r][c] << ":";
		  ans+= DP[r][c];
		}
	  }
	}
	return ans;
  }
};

void solve_ZigZagPayPal (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  auto *s = new Solution ();
  
  auto answer = s->convert ("AB",1);
  assert (answer == "AB");
}
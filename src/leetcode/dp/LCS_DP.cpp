//
// Created by mrityunjaykumar on 2019-08-13.
//

# include "../../common.h"

class Solution {
 public:
  int longestCommonSubsequence (string text1, string text2) {
	vector<vector<int>> DP (text1.length () + 1, vector<int> (text2.length () + 1, 0));
	for (int i = 1; i <= text1.length (); i++) {
	  for (int j = 1; j <= text2.length (); j++) {
		if (text1[i - 1] == text2[j - 1]) { DP[i][j] = 1 + DP[i - 1][j - 1]; } else { DP[i][j] = max (DP[i - 1][j],
																									  DP[i][j - 1]);
		}
	  }
	}
	return DP[text1.length ()][text2.length ()];
  }
};

void solve_LCS_DP (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  
  auto answer = s->longestCommonSubsequence ("abc","def");
  assert (answer == 0);
}
//
// Created by mrityunjaykumar on 2019-08-19.
//

# include "../../common.h"
// MOTHER OF FIBONACCI :D

class Solution {
 public:
  int numDecodings (string s) {
	int n=s.length();
	double f[n+1];
	if(n==0) return 0;
	if(s[0]=='0') return 0;
	if(n==1) return 1;
	if(s[0]=='0' && s[1]>'2') return 0;
 
	std::function<int(int)> FUN = [&s](int i) {
            string t = s.substr(i,i+1);
             auto ans = ((s[i] - '0') * 10 + s[i + 1] - '0');
             return ans<=26;
        };
    f[0]=1;
	f[1] = FUN(0)?2:1;
	if(s[1]=='0'){
	  f[1]=1;
	  if(s[0]>'2')
	    f[1]=0;
	}
 
	for (int i = 2; i < n; ++i) {
	  if(s[i]=='0'){
	    if((s[i-1]>='3') || (s[i-1]=='0'))
            return 0;
	    f[i]=f[i-2];
	  }else{
	    f[i]=f[i-1];
	    if(s[i-1]>'0'){
	      if(FUN(i-1))
	        f[i]+=f[i-2];
	    }
	  }
	}
	return f[n-1];
  }
};
		
void solve_DocdeWays (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  
  auto answer = s->numDecodings ("17");
  cout << answer << endl;
  assert (answer == 2);
}
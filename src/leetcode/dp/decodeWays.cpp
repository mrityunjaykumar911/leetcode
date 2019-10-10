//
// Created by mrityunjaykumar on 2019-10-10.
//

# include "../../common.h"

class DecodeSolution {
 public:
  int numDecodings (string s) {
  	int Length = s.length();
  	if(Length == 0){
	  return 0;
  	}
  	vector<int> ways(Length+1,0);
  	int prev = 1;
  	ways[0] = 1;
  	ways[1] = s[0]=='0'?0:1;
  	for(int index=2;index<=Length;index++){
  	  int lastOneDigit = std::stoi(s.substr(index-1,1));
  	  int lastTwoDigit = std::stoi(s.substr(index-2,2));
  	  ways[index] = (lastOneDigit!=0?ways[index-1]:0)+((10<=lastTwoDigit && lastTwoDigit<=26)?ways[index-2]:0);
  	}
	return ways[Length];
  }
};

void solve_decodeWays2 (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  auto *s = new DecodeSolution ();
  
  auto answer = s->numDecodings ("1001");
  assert (answer == 0);
}
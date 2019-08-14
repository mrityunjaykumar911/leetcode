//
// Created by mrityunjaykumar on 2019-08-08.
//

# include "../../common.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int arr[A.size()];
        int brr[A.size()];
        memset(arr,-99,A.size());
        memset(brr,-99,A.size());
        
        int pos=-1;
        int neg=-1;
        int tpos=0;
        vector<int> ans;
        for(auto &a:A){
            if(a<=0){
                brr[++neg]=a*a;
            }else{
                arr[++pos]=a*a;
            }
        }
        tpos=0;
        while(neg>=0 && tpos<=pos){
            int final = 0;
            if(brr[neg]<arr[tpos]){
                final = brr[neg];
                neg--;
            }else{
                final = arr[tpos];
                tpos++;
            }
            add:
            ans.emplace_back(final);
        }
        
        
        while(neg>=0){
            ans.emplace_back(brr[neg]);
            neg--;
        }
        while(tpos<=pos){
            ans.emplace_back(arr[tpos]);
            tpos++;
        }
        
        
        return ans;
    }
};

void solve_SqSqaures (void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution ();
  vector<int> nums={-1};
  auto answer = s->sortedSquares (nums);
  assert (answer.size() == 1);
}
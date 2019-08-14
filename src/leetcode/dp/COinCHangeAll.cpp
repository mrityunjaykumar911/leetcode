//
// Created by mrityunjaykumar on 2019-08-03.
//

# include "../../common.h"

/*
 * https://leetcode.com/problems/combination-sum-iv/
 *
 * Beware of overflow, if logic is correct, check if it works for double or other similar data types
 * */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target<=0)
            return 0;
        
        vector<double> DP(target+1,0);
        
        DP[0]=1;
        
        sort(nums.begin(), nums.end());
        for(int i=1;i<=target;i++){
            int sum=0;
            for(int a:nums){
                if(i<a)
                    break;
                DP[i]+=DP[i-a];
            }
        }
        
        // for(int i=1;i<=target;i++){
        //     cout << DP[i] << ":";
        // }
        
        return DP[target] ;
    }
};

//Write CPP code here


void solve_COinCHangeAll(void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution();
//  vector<int> nums2={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
  vector<int> nums={3,33,333};
  vector<int> nums3={1,2,3};
  auto answer = s->combinationSum4(nums,10000);
  cout <<answer << endl;
//  assert(answer == 0);
}
//
// Created by mrityunjaykumar on 2019-08-03.
//

# include "../../common.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      int **arr;
      int n = nums.size();
      for (int i = 0; i<=n ; ++i) {
        arr[i] = new int[target+1];
        memset(arr[i],0,target+1);
      }
      // amount 0, whatever coin, ways 1 <-- base case
      for (int j = 0; j <=target  ; ++j) {
        arr[0][j] = 1;
      }
      // coin 0, whatever amount, ways 0 <-- base case
      for (int j = 1; j <=n  ; ++j) {
        arr[j][0] = 0;
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
          arr[i][j]=0;
        }
      }
      int final=0;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
           if(j-nums[i - 1])
           {
              int temp = arr[i - 1][j] + arr[i][j - nums[i - 1]];
              arr[i][j] = temp;
              final = temp;
           }
        }
      }
      int fans = final;
      for (int i = 0; i<=n ; ++i) {
        delete [] arr[i];
      }
      return fans;
    }
};

//Write CPP code here


void solve_COinCHangeAll(void) {
  cout << endl << "Running the problem " << __func__ << endl;
  Solution *s = new Solution();
//  vector<int> nums2={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
  vector<int> nums={3,33,333};
  vector<int> nums3={1,2,3};
  auto answer = s->combinationSum4(nums3,4);
  cout <<answer << endl;
//  assert(answer == 0);
}
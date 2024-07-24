#include <bits/stdc++.h>
using namespace std;

// this code looks less complex for interview
// Why dont we just calculate the answer of both pattern , increment first and then alternation
// or decrement first and then alternating ,
// after calculaating both we will return the ans;




int frec(int i , vector<int> const &nums  , int prevTaken , bool IncremFlag)
{
  //base case
  if(i < 0)
    return 0;

  if(prevTaken == -1)
  {
    int not_pick = frec( i-1 , nums , prevTaken , IncremFlag);

    int pick = 0;

    pick = 1 + frec( i-1 , nums , i , !IncremFlag);

    return max(pick  , not_pick);
  }

  // depending upon the flag we will go foward

  int not_pick = frec( i-1 , nums , prevTaken , IncremFlag);

  int pick = 0;

  if(IncremFlag == true && nums[i] > nums[prevTaken] || IncremFlag == false && nums[i] < nums[prevTaken])
  {
      pick = 1 + frec( i-1 , nums , i , !IncremFlag);
      // the negation of the flag  is must
  }


  return max(pick , not_pick);


}


int fmemo(int i , vector<int> const &nums  , int prevTaken , bool IncremFlag , vector<vector<vector<int>>>&dp)
{
  //base case
  if(i < 0)
    return 0;


    if(dp[i][prevTaken+1][IncremFlag] != -1)
      return dp[i][prevTaken+1][IncremFlag];

  if(prevTaken == -1)
  {
    int not_pick = fmemo( i-1 , nums , prevTaken , IncremFlag , dp);

    int pick = 0;

    pick = 1 + fmemo( i-1 , nums , i , !IncremFlag , dp);

    return dp[i][prevTaken+1][IncremFlag] = max(pick  , not_pick);
  }

  // depending upon the flag we will go foward

  int not_pick = fmemo( i-1 , nums , prevTaken , IncremFlag , dp);

  int pick = 0;

  if(IncremFlag == true && nums[i] > nums[prevTaken] || IncremFlag == false && nums[i] < nums[prevTaken])
  {
      pick = 1 + fmemo( i-1 , nums , i , !IncremFlag , dp);
      // the negation of the flag  is must
  }


  return dp[i][prevTaken+1][IncremFlag]  = max(pick , not_pick);


}


// Not correct
int Tabulation(vector<int> const &nums )
{

  int n = nums.size();
  // creacting the DS required
    // for base case we need to shift the indexes thats why n+1
  vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(n+1 , vector<int>(2 , 0)));

  // base case ,
  // for base case we need to shift the indexes
  // already filled with 0

  // LOOPING

  for(int i=1 ;i<=n;i++)
  {
    for(int prevTaken = -1; prevTaken < n ; prevTaken++)
    {
      for(int IncremFlag=0; IncremFlag<2 ;IncremFlag++)
      {
        // COpy the recurrence
        if(prevTaken == -1)
        {
          int not_pick = dp[i-1][prevTaken][IncremFlag];

          int pick = 0;

          pick = 1 + dp[i-1][i][!IncremFlag];

          dp[i][prevTaken+1][IncremFlag] = max(pick  , not_pick);
        }

        // depending upon the flag we will go foward

        else
        {
          int not_pick = dp[i-1][prevTaken][IncremFlag];

          int pick = 0;

          if(IncremFlag == true && nums[i-1] > nums[prevTaken] || IncremFlag == false && nums[i-1] < nums[prevTaken])
          {
              pick = 1 + dp[i-1][i][!IncremFlag];
              // the negation of the flag  is must
          }


          dp[i][prevTaken+1][IncremFlag]  = max(pick , not_pick);
        }


      }
    }
  }

  return max(dp[n][n][1] , dp[n][n][0]);


}


  int MemoisedCode(vector<int> const &nums)
  {
    // Write your code here...
    int n = nums.size();

    // int ans = max( frec( n-1 , nums , -1 , true) ,frec( n-1 , nums , -1 , false)) ;

    vector<vector<vector<int>>>dp(n , vector<vector<int>>(n+1 , vector<int>(2 , -1)));
    int ans = max( fmemo( n-1 , nums , -1 , true , dp) ,fmemo( n-1 , nums , -1 , false , dp)) ;


    return ans;
  }

int main()
{
  vector<int>nums2 = {7, 3, 2, 5, 8};

  int ans = MemoisedCode(nums2);

  // int ans2 = Tabulation(nums2);

  cout<<ans;
}

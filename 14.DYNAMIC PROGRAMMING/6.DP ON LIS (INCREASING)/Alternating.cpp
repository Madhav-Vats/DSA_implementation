#include <bits/stdc++.h>
using namespace std;

/*

The longest alternating subsequence is a problem of finding a subsequence of a given sequence in which the elements are in alternating order and in which the sequence is as long as possible. In order words, we need to find the length of the longest subsequence with alternate low and high elements.

Input: [8, 9, 6, 4, 5, 7, 3, 2, 4]
Output: 6
Explanation: The longest alternating subsequence length is 6, and the subsequence is [8, 9, 6, 7, 3, 4] as (8 < 9 > 6 < 7 > 3 < 4).

Note that the longest alternating subsequence is not unique. Following are a few more subsequences of length 6:

(8, 9, 6, 7, 2, 4)
(8, 9, 4, 7, 3, 4)
(8, 9, 4, 7, 2, 4)

*/

	int frec(int i , vector<int> const &nums  , int prevTaken , bool IncremFlag)
	{
		//base case
		if(i < 0)
			return 0;

		// take it into our alt sunsequence

		if( prevTaken ==   -1)
		{
			// that means we havent taken any element yet

			int not_pick = frec( i-1 ,  nums , prevTaken , IncremFlag);

			int pick = 1 + max( frec(i-1 , nums , i , true) , frec(i-1 , nums , i , false));

			return max( pick , not_pick);
		}

		// else case

		int not_pick = frec( i-1 , nums , prevTaken , IncremFlag);

		int pick = 0;

		if(IncremFlag == true && nums[i] > nums[prevTaken])
		{
			// that means we need a larger value , and we are taking a larger value

				pick = 1 + frec( i-1 , nums , i , !IncremFlag);
				// this time we will pass the negation of the flag

		}

		else if(IncremFlag == false && nums[i] < nums[prevTaken])
		{
			//we needed a lower value and we got it
			pick = 1 + frec( i-1 , nums , i , !IncremFlag);
		}


		return max(pick , not_pick);


	}

  int fmemo(int i , vector<int> const &nums  , int prevTaken , bool IncremFlag , vector<vector<vector<int>>>&dp)
  {
    //base case
    if(i < 0)
      return 0;

    // take it into our alt sunsequence

    if(dp[i][prevTaken+1][IncremFlag] != -1)
      return dp[i][prevTaken+1][IncremFlag];

    if( prevTaken ==   -1)
    {
      // that means we havent taken any element yet

      int not_pick = fmemo( i-1 ,  nums , prevTaken , IncremFlag , dp);

      int pick = 1 + max( fmemo(i-1 , nums , i , true ,dp ) , fmemo(i-1 , nums , i , false , dp));

      return dp[i][prevTaken+1][IncremFlag] = max( pick , not_pick);
    }

    // else case

    int not_pick = fmemo( i-1 , nums , prevTaken , IncremFlag , dp);

    int pick = 0;

    if(IncremFlag == true && nums[i] > nums[prevTaken])
    {
      // that means we need a larger value , and we are taking a larger value

        pick = 1 + fmemo( i-1 , nums , i , !IncremFlag , dp);
        // this time we will pass the negation of the flag

    }

    else if(IncremFlag == false && nums[i] < nums[prevTaken])
    {
      //we needed a lower value and we got it
      pick = 1 + fmemo( i-1 , nums , i , !IncremFlag , dp);
    }


    return dp[i][prevTaken+1][IncremFlag] = max(pick , not_pick);


  }


	int findLongestAlternatingSequence(vector<int> const &nums)
	{
		// Write your code here...
		int n = nums.size();

		int ans = frec( n-1 , nums , -1 , true);

		return ans;
	}

  int MemoisedCode(vector<int> const &nums)
  {
    // Write your code here...
    int n = nums.size();

    vector<vector<vector<int>>>dp(n , vector<vector<int>>(n+1 , vector<int>(2 , -1)));

    int ans = fmemo( n-1 , nums , -1 , true , dp);

    return ans;
  }


  int main()
  {
    vector<int>nums = {8, 9, 6, 4, 5, 7, 3, 2, 4};

    vector<int>nums2 = {1, 5, 7, 3, 2, 4, 8};

    int ans = MemoisedCode(nums2);

    cout<<ans;
  }

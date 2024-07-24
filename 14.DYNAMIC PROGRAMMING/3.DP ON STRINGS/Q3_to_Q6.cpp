#include <bits/stdc++.h>
using namespace std;


//************************LONGEST COMMON SUB-STRING***************************//

//---------------------------SIMPLE RECURSION---------------------------------//

// for recursive code we will create a counter
// when matching we add 1 to counter each time
// and if no match we make it as again 0 , and call for next elements
// at the base condion it returns with overall count value

int LcSubStr(int count , int i , int j , string &s1 , string &s2)
{
  // base cases
  if(i < 0 || j < 0)
    return count;   // at the end the recursion should return the count value

  if(s1[i] == s2[j])
    count  = LcSubStr( count+1 , i-1 , j-1 , s1 , s2 );

  else //( no need to write)
    count  = max( LcSubStr( 0, i-1, j, s1, s2) , LcSubStr(0, i, j-1, s1, s2) );
  // at this call the recursion takes out the max after slitting the options

  // for those case when else condn was ran
  return count ;
}

int LcSubString(string &s1 , string &s2)
{
  int n = s1.length();
  int m = s2.length();

  int count  = 0;
  return LcSubStr(0 , n-1 , m-1 , s1 , s2);
}

// its memoization required 3d array , [m*n*count] and i dont know wehter possible or not

int LcSubStrMemoized(int i , int j , int count,  int& maxCount, string &s1 ,string &s2 , vector<vector<int>>&dp)
{
  // base case
  if(i<0 || j<0)
    return count;

  if(dp[i][j] != -1)
    return dp[i][j];

  maxCount = max(count , maxCount);

  int ans = 0;

  if(s1[i] == s2[j])
    ans = LcSubStrMemoized(i-1, j-1 , count+1 , maxCount , s1 , s2 , dp);

  else
  {
    // if this index values are not same
    // then we have to go deep with a count value of 0
    ans = max( LcSubStrMemoized(i-1 , j , 0 , maxCount, s1 , s2, dp) , LcSubStrMemoized(i , j-1 , 0  , maxCount, s1 , s2, dp));
  }


  return dp[i][j] = ans;


}


int MemoizedLcSubString(string &s1 , string &s2)
{
  int n = s1.length();
  int m = s2.length();

  int count  = 0;

  vector<vector<int>>dp(n , vector<int>(m , -1));
  int maxCount = 0;

  int ansii = LcSubStrMemoized(n-1 , m-1 , 0 , maxCount, s1 , s2 , dp);

  return maxCount;
}



//---------------------------------TABULATION---------------------------------//


int LcSubStr_Tablulation(string &s1 , string &s2)
{

  int n = s1.length();
  int m = s2.length();

  vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));

  // BASE CASES
  for(int i=0;i<=n;i++)
  {
    dp[i][0] = 0;
  }
  for(int j=0;j<=m;j++)
  {
    dp[0][j] = 0;
  }


  int count = 0;

  for(int i =0;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s1[i-1] == s2[j-1])
      {
        dp[i][j] = dp[i-1][j-1] + 1;
        count =  max(count  , dp[i][j]);
      }

      else
        dp[i][j] = 0;
    }
  }

  return count;
}



//********************** LONGEST PALINDROME SUBSEQUENCE ***********************//

int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Create a 2D DP array to store the length of the LCS
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP array
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    // The value at dp[n][m] contains the length of the LCS
    return dp[n][m];
}


int longestCommonPalindrome(string &s1)
{

  // create a new string copy of s1
  string s2  = s1;

  // reverse s1 string
  reverse(s1.begin() , s1.end());

  return lcs(s1 , s2);

}



//************* MINIMUM INSERTIONS TO MAKE A STRING PALINDROME ***************//
int minInsertions(string &s1)
{
  int n = s1.size();

  // create a new string copy of s1
  string s2  = s1;

  // reverse s1 string
  reverse(s1.begin() , s1.end());

  return n - lcs(s1 , s2);

}

//********************** DELETION AND INSERTIONS  ****************************//

int minDistance(string &word1, string &word2) {

    int lengthLCS = lcs(word1 , word2);

    int n = word1.size();
    int m = word2.size();

    // if(anything is left over in word1 , it needs to be deleted)
    // and if any element is not present after all this it needs to be inserted

    // return deletion + insertion
    return (n- lengthLCS) + (m - lengthLCS);

}


//------------------------------MAIN FUNCTION---------------------------------//

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  #endif

  string s1;
  cin>>s1;
  string s2;
  cin>>s2;


  int ans = MemoizedLcSubString(s1 , s2);
  cout<<ans;

  // return 0;
}

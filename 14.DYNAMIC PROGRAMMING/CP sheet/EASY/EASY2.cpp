#include<bits/stdc++.h>
using namespace std;

// find the number of Subsequences forming "QAQ" are present in the
// Num of Subsequences that can be formed from this string which are "QAQ"

// example: QAAQAQ   -> output = 6


int frec( int i , int j , string &s1 , string &s2 )
{
  //base case
  if(j<0)
    return 1;

  if(i<0)
    return 0;

  if(s1[i] ==s2[j])
  {
    return frec(i-1 ,j-1 , s1 ,s2) + frec(i-1 , j , s1 , s2);
  }

  //if not or even if u want to check out the next element of s1 which is like this

  return frec(i-1 , j , s1 , s2);
}

int fmemo( int i , int j , string &s1 , string &s2  , vector<vector<int>>&dp)
{
  //base case
  if(j<0)
    return 1;

  if(i<0)
    return 0;

  if(dp[i][j] != -1)
    return dp[i][j];

  if(s1[i] ==s2[j])
  {
    return dp[i][j] = frec(i-1 ,j-1 , s1 ,s2) + frec(i-1 , j , s1 , s2);
  }

  //if not or even if u want to check out the next element of s1 which is like this

  return dp[i][j] = frec(i-1 , j , s1 , s2);
}

int tabulation(string &s1 , string &s2 )
{
  int n1 = s1.length();
  int n2 = s2.length();

  //dp array
  // we need to handle the neg indices , therfore we willl use shifting of indices

  vector<vector<int>>dp(n1+1 , vector<int>(n2+1 , 0));

  //base case initialization
  //all j==0 , are 1
  //all i==0 , are 0

  for(int i=0;i<=n1;i++)
  {
    dp[i][0] = 1;
  }

  for(int i=1; i<=n1;i++)
  {
    for(int j =1 ;j<=n2;j++)
    {
      //copy the recurrence

      if(s1[i-1] == s2[j-1])
      {
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
      }

      else
        dp[i][j] = dp[i-1][j];
    }
  }

  return dp[n1][n2];

}

int main()
{
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    #endif
  }

  string s1;
  cin>>s1;

  // QAAQAQ


  int n1 = s1.length();

  string s2 ="QAQ";
  int n2 = s2.length();

  int ans = frec( n1-1 , n2-1 , s1 , s2);
  cout<<ans<<endl;

  vector<vector<int>>dp(n1 , vector<int>(n2 , -1));

  int memoAns = fmemo(n1-1 , n2-1 , s1 , s2 , dp);
  cout<<memoAns<<endl;

  int TabulationAns = tabulation(s1 , s2);
  cout<<TabulationAns<<endl;
  return 0;
}

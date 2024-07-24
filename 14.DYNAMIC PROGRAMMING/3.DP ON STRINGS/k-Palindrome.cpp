///Check if a string is k–palindrome or not
// Write an efficient algorithm to check if a given string is k–palindrome or not.
// A string is k–palindrome if it becomes a palindrome on removing at most k characters from it.


#include<bits/stdc++.h>
using namespace std;

int frec(int i , int j ,string s1 , string s2)
{
  //base case
  if(i<0 || j<0)
    return 0;


  if(s1[i] == s2[j])
  {
    return 1+ frec(i-1 , j-1 , s1 , s2);
  }

  //now you got two choices , either reduce i and check or reduce j and check

  return max(frec(i-1 , j , s1 ,s2) , frec(i , j-1 , s1 , s2));
}

string LCS(string s1 , string s2)
{
  //Tabulation
  int n = s1.length();
  int m = n;

  //shifiting of index
  vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));

  //base case initialization
  //all i=0 are 0
  //all j = 0 re 0;

  //Looping
  for(int i=1;i<=n;i++)
  {
    for(int j =1 ;j<=m;j++)
    {
      //copy the recurrence
      if(s1[i-1] == s2[j-1])
        dp[i][j] =  1+ dp[i-1][j-1];

      else
        dp[i][j] = max(dp[i-1][j]  , dp[i][j-1]);
    }
  }

  //Logic For Printing of the LCS

  int length =  dp[n][m];
  string ans = "";
  int index = length-1;

  for(int i=0;i<length;i++)
  {
    ans += "$";
  }

  int i = n;
  int j = m;
  while(i>0 &&j>0)
  {
    if(s1[i-1] == s2[j-1])
    {
      //they must have came from the diagonal
      ans[index] = s1[i-1];
      i--;
      j--;
      index--;
    }

    else if(dp[i-1][j] > dp[i][j-1])
    {
      i--;
    }
    else
    {
      j--;
    }
  }

  return ans;

}

string kPalind(int k , string s)
{
  string rev = s;
  reverse(rev.begin() , rev.end());
  int len = s.length();

  //find the longest common subsequence btw s and revS
  int PalindSub = frec( len-1 , len-1 , s , rev);
  string ansii = LCS(s , rev);

  return ansii;

}

int main()
{
  string s = "mdhhdaadm";

  int k =1;
  // bool ans  = kPalind( s , k);

  string ans = kPalind( k , s );

  cout<<ans;
}

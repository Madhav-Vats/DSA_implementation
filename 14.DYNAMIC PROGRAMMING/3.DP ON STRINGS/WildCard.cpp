#include<bits/stdc++.h>
using namespace std;

bool WildCard(int i , int j , string s1 , string s2 )
{
  //base cases
  if(i<0 && j<0)
      return true;
  if(i>=0 && j<0)
      return false;

  if(j==0 && s2[j]=='*')
    return true;

  if(i<0)
  {
    for(int k = j;k>=0 ;k--)
    {
      if(s2[k] != '*')
        return false;
    }

    return true;
  }



  if(s1[i]==s2[j] || s2[j] == '?')
  {
    return WildCard(i-1 , j-1 , s1 , s2);
  }

  else if(s2[j] =='*')
  {
    // decrease i one by one , and dont decrease the j ,
    //with an or condition of i-1 and j
    // to check whether if we consider this much size of i , can we get a true
    return (WildCard(i-1 , j , s1 , s2) | WildCard(i-1 , j-1 , s1 , s2));
  }

  else
   return false;

}


bool WildCardMemo(int i , int j , string s1 , string s2 ,vector<vector<int>> &dp )
{
//base cases
if(i<0 && j<0)
    return true;
if(i>=0 && j<0)
    return false;

// if(j==0 && s2[j]=='*')
//     return true;

if(i<0 && j>=0)
{
    for(int k = j;k>=0 ;k--)
    {
    if(s2[k] != '*')
        return false;
    }

    return true;
}



if(s1[i]==s2[j] || s2[j] == '?')
{
    return dp[i][j] =  WildCardMemo(i-1 , j-1 , s1 , s2 , dp );
}

else if(s2[j] =='*')
{
    // decrease i one by one , and dont decrease the j ,
    //with an or condition of i-1 and j
    // to check whether if we consider this much size of i , can we get a true
    return dp[i][j] =  (WildCardMemo(i-1 , j , s1 , s2 , dp) | WildCardMemo(i , j-1 , s1 , s2 , dp));
}

else
return dp[i][j] =  false;

}


bool tabul( string s1 , string s2)
{
    int n =  s1.length() ;
    int m = s2.length() ;

    vector<vector<bool>>dp( n+1 , vector<bool>(m+1 , 0));

    //base case
    dp[0][0] =  1;

    // when i = 0  and the remining all j are = *
    int k = 0;
    while(s2[k] == '*')
    {
        dp[0][k+1] = 1;
        k++;
    }


    //Looping

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]== s2[j-1] || s2[j-1] =='?')
                dp[i][j] = dp[i-1][j-1];


            else if(s2[j-1]=='*')
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }

            else
                dp[i][j] = 0;
        }
    }

    return dp[n][m];


}




int main()
{

  string s1 = "abdefcd";
  string s2 = "ab**cd";

  int n =  s1.length();
  int m = s2.length();

  bool ans  = WildCard(n-1, m-1 , s1 , s2);
  cout<<ans;
}

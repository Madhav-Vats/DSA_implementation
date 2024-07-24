#include <bits/stdc++.h>
#include <string>
using namespace std;


//*******************SHORTEST COMMON SUPER SEQUENCE **************************//

//---------------------------SIMPLE RECURSION---------------------------------//

// comment: - its about the lcs dp , and its traversal , how u use it , matters

class SUPER
{
public:
void SuperSequence( string &s1 , string &s2 )
{
  int n = s1.length();
  int m = s2.length();

    //MAKING OF DP ARRAY
vector<vector<int>> dp( n+1 , vector<int>(m+1 , -1));

for(int i=0;i<=n;i++)
{
  dp[i][0] = 0;
}

for(int j=0;j<=m;j++)
{
  dp[0][j] = 0;
}

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if( s1[i-1] == s2[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];

      else
        dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
    }
  }


    // PRINTING THE SUPER SEQUENCE

// now the length of super sequence cant be determined directly from the dp array
string ans ="";

int i = n;
int j = m;

while(i>0 && j >0)
{
  if(s1[i-1] == s2[j-1])
  {
    ans += s1[i-1];
    i--;
    j--;
  }

  else if( dp[i-1][j] > dp[i][j-1])
  {
    ans += s2[j-1];    // jis direction me nhi gye , jise ghata diya , uski wali string ka element
    j--;
  }
  else
  {
    ans += s1[i-1];  // is baar , upper cell bda hai , to s1 , wale ko insert krlo , and i--
    i--;
  }

}
while(i>0) // s2 is exhauted
{
  ans += s1[i-1];
  i--;
}
while(j>0) // s1 is exhausted
{
  ans += s2[j-1];
  j--;
}



reverse(ans.begin(), ans.end());
cout<<ans;
}

};

//*************************DISTINCT SUB-SEQUENCE *****************************//

class DISTINCT
{
public:
int frec(int i,int j, string &s1, string &s2) {

  if(j<0)
    return 1;
  if(i<0)
    return 0;

  if(s1[i] == s2[j])
  {
    return frec(i-1 , j-1, s1 , s2) + frec(i-1 , j , s1 , s2);
  }
  return frec(i-1 , j , s1 , s2);
}
// MEMOIZATION
int fmemo(int i,int j, string &s1, string &s2 , vector<vector<int>>&dp) {

  if(j<0)
    return 1;
  if(i<0)
    return 0;

  if(dp[i][j] != -1)
    return dp[i][j];

  if(s1[i] == s2[j])
  {
    return dp[i][j] = frec(i-1 , j-1, s1 , s2) + frec(i-1 , j , s1 , s2);
  }
  return dp[i][j] = frec(i-1 , j , s1 , s2);
}


 // TABULATION
 int numDistinct(string s1, string s2) {

     int n = s1.length();
     int m = s2.length();

     // SHIFTING OF INDEX
     vector<vector<double>>dp(n+1 , vector<double>(m+1, 0));

     for(int i=0;i<=n;i++)
     {
     dp[i][0] = 1;
     }




     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=m;j++)
         {
             if(s1[i-1] == s2[j-1])
             {
                 dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
             }
             else
                 dp[i][j] = dp[i-1][j];
         }
     }

 return (int)dp[n][m];

 }

};

//---------------------------SIMPLE RECURSION---------------------------------//



//***************************** EDIT DISTANCE ********************************//

//---------------------------SIMPLE RECURSION---------------------------------//




int main()
{
  SUPER S1;
  string s1 = "broot";
  string s2 = "groot";
  S1.SuperSequence(s1 , s2);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;




//************************LONGEST COMMON SUBSEQUENCE****************************





//---------------------------SIMPLE RECURSION---------------------------------//

// SOLN WITH ZERO BASED INDEXING
int frec( int i , int j , string &s1 , string &s2)
{
  // Base case
  // exhaustion case
  if(i<0 || j<0)
    return 0;

  if(s1[i] == s2[j])
    return 1 + frec(i-1 , j-1 , s1 , s2);

  else if(s1[i] != s2[j])
  {
    // if you neglect both , there is a chance that the next one might match with the current
    // so get max from both the ways of reducing 1 index
    // and dont go via reducing both at same time

    return 0 + max(frec(i-1 , j , s1 , s2) , frec(i , j-1 , s1 , s2));
  }
}


int LcsRec( string &s1 , string &s2)
{
  int n = s1.length();
  int m = s2.length();
  return frec(n-1 , m-1 , s1 , s2);

}








//---------------------------------MEMOIZATION--------------------------------//

// SOLN WITH ONE BASED INDEXING
int fmemo( int i , int j , string &s1 , string &s2 ,vector<vector<int>> &dp )
{
  // Base case
  // exhaustion case
  if(i==0 || j==0)
    return 0;

  if(dp[i][j]!=-1)
    return dp[i][j];

  if(s1[i-1] == s2[j-1]) // here n , m  were passed so n-1 and m-1 are valid for the string
    return dp[i][j] =  1 + fmemo(i-1 , j-1 , s1 , s2 , dp);

  // no need to write (else)

  // if you neglect both , there is a chance that the next one might match with the current
  // so get max from both the ways of reducing 1 index
  // and dont go via reducing both at same time

  return dp[i][j] = 0 + max(fmemo(i-1 , j , s1 , s2 , dp) , fmemo(i , j-1 , s1 , s2 , dp));


}

int LcsMemo( string &s1 , string &s2)
{
  int n = s1.length();
  int m = s2.length();

  // FOR ONE BASED INDEXING SHIFTING ALL THE INDICES BY 1 UNIT
  // therefore zeroth index would represent negative index for the string
  vector<vector<int>>dp( n+1 , vector<int>(m+1 , -1));


    // and in actual string are from 0 to n-1 and 0 to m-1
    // but in the function we are passing n  and m
  return fmemo( n , m ,s1 , s2 , dp);

}



//---------------------------------TABULATION---------------------------------//

int Tabulation(string &s1 , string &s2)
{

  int n = s1.length();
  int m = s2.length();

  vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));

  //base case
    // exhaustion wale case ki initialization
  for(int i=0;i<=n;i++)
  {
    dp[i][0] = 0;
  }

  for(int j=0;j<=m;j++)
  {
    dp[0][j]=0;
  }

  // loops
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      //copy the recurrence
      if(s1[i-1] == s2[j-1])
         dp[i][j] =  1 + dp[i-1][j-1];

      else // here we have added else which was not needed in case of recursion
         dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
    }
  }

  return dp[n][m];   // bcoz it was 1 based index thts why no [n-1][m-1]
}


int LcsTab( string &s1 , string &s2)
{
  return Tabulation(s1,s2);
}


//-------------------TABULATION WITH SPACE OPTIMIZATION-----------------------//


int TablulationSpOpt(string &s1 , string &s2)
{

  int n = s1.length();
  int m = s2.length();

  vector<int>prev(m+1 , 0);
  vector<int>curr(m+1 , 0);

  // base case filling
    // already filled as 0

  // Looping

  for(int i=1;i<=n;i++)
  {
    for(int j=1; j<=m ;j++)
    {
      //copy the recurrence

      // so basically we just need this curr Row and the Prev Row for everystep
      if(s1[i-1] == s2[j-1])
        curr[j] = 1 + prev[j-1];

      else // here we have added else which was not needed in case of recursion
         curr[j] = max( prev[j], curr[j-1] );
    }

    prev = curr;
  }

  return curr[m];

}


//----------------------------- PRINTING LCS ----------------------------------//

  // DEVELOP DP MATRIX

void print_LCS(string &s1 , string &s2)
{
  int n = s1.length();
  int m = s2.length();
  vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));

  for(int i=0;i<=n;i++)
    dp[i][0] = 0;

  for(int j=0;j<=m;j++)
    dp[0][j]=0;

  // loops
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      //copy the recurrence
      if(s1[i-1] == s2[j-1])
         dp[i][j] =  1 + dp[i-1][j-1];

      else
         dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
    }
  }

  // DP matrix completed

  //  PRINTING BEGINS

  //for current example s1 = adebc  , s2= dcadb DP matrix lokks like this :-

  //          d c a d b

//          0 0 0 0 0 0
//    a     0 0 0 1 1 1
//    d     0 1 1 1 2 2
//    e     0 1 1 1 2 2
//    b     0 1 1 1 2 3
//    c     0 1 2 2 2 3

// now we start from the corner most index and as we know that
// if matched then we would have came from i-1,j-1
// if not matched we would have came from max( (i-1 ,j)  , (i,j-1) )

// now the length of the LCS is the vlue at this cell
int length = dp[n][m];
string ans = "";

for(int i=0;i<length;i++)
{
  ans += "$";
}
// ans  = "$$$"  bcoz lenght was 3

int index = length-1; // for pushing element at this index of ans

int i = n;
int j = m;
while(i>0 && j>0)  // as they represent neg index
{
  if(s1[i-1] == s2[j-1])
  {
    ans[index] = s1[i-1];
    index--;

    // move diagonally to i-1 , j-1
    i -=1;
    j -=1;
  }

  // now all remaining cases will lie in these 2 condn
  else if(dp[i-1][j] > dp[i][j-1])  // then left cell is the max
  {
    i-=1;
  }
  else if(dp[i-1][j] <= dp[i][j-1]) // then upper cell is the max
  {
    j-=1;
  }
}

cout<<ans;

}


//------------------------------MAIN FUNCTION----------------------------------//

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


  int  ans = TablulationSpOpt(s1,s2);
  cout<<ans<<endl;
  // print_LCS(s1,s2);
}

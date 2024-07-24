#include<bits/stdc++.h>
using namespace std;

//max increasing subarray length
//Using dynamic programming

// at every index ind we will chech the size of increasing subarray
//whose end index is ind , which is increasing

//so we start from ind= n ,  its prev should have stored something in it;
// if arr[ind-1] < arr[ind] , dp[ind] = dp[ind-1];


//Normal recursion
int frec( int ind , vector<int>& arr ,vector<int>&dp , vector<int>&endingAtthis)
{
  if(ind == 0)
    return 1;

  //check for prevMaximum subarray
  int prevMaxi = frec(ind-1 , arr  , dp , endingAtthis);

  //check what if i include this element
  if(arr[ind] > arr[ind-1])
  {
    endingAtthis[ind] += endingAtthis[ind-1];
  }

  return dp[ind] = max(prevMaxi , endingAtthis[ind]);
}

//using Tabulation or u can say simple array technique
int Tabulation(vector<int>&arr , int n) // using a dp array
{
  vector<int>dp(n , 1);

  for(int i = 1; i<n;i++)
  {
    if(arr[i] > arr[i-1])
    {
      dp[i] = 1+dp[i-1];
    }
  }

  int maxi = *max_element(dp.begin() , dp.end());
  return maxi;
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
  int n;
  cin>>n;

  vector<int>arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  //------RECURSION AND MEMOIZATION----------------
  // vector<int>endingAtthis(n , 1);
  // vector<int>dp(n , -1);
  // int ans = frec(n-1 , arr , dp , endingAtthis);
  //-----------------------------------------------

  // simple Tabulation solution
  int ans2 = Tabulation(arr , n);

  cout<<ans2<<endl;
}

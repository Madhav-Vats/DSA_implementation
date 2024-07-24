#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>>dp;
int mod = 1e9+7;
int n;
int solve(int ind ,int target , vector<int>&arr)
{
  if(target == 0)
    return 0;
  if(ind == n)
  {
    if(target == 0)
      return 0;
    else
      return 1e7;
  }

  if(dp[ind][target] != -1)
    return dp[ind][target];

  long long ans = 1e7;

  //take case
  if(arr[ind] <=target)
    ans = min(ans , static_cast<long long>(1+solve(ind , target - arr[ind] , arr)));

  //not take case
  ans = min(ans , static_cast<long long>(solve(ind+1 , target ,arr)) );
  return dp[ind][target] = ans;
}
int main()
{
  int x;
  cin>>n>>x;

  dp = vector<vector<long long>>(n+1 , vector<long long>(x+1 , -1));

  vector<int>arr;

  for(int i=0;i<n;i++)
  {
    int el;
    cin>>el;
    arr.push_back(el);
  }


  long long ans = solve(0 , x , arr);
  ans %= mod;

  if(ans == 1e5)
    cout<<-1;
  else
    cout<<ans;
}

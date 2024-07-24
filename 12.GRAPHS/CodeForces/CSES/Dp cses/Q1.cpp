#include <bits/stdc++.h>
using namespace std;

long long dp[1000100];
int mod = 1e9+7;

long long solve(int target)
{
  if(target == 0)
  {
    return 1;
  }

  if(dp[target] != -1)
    return dp[target];
  long long ans = 0;

  for(int i=1;i<=6;i++)
  {
    if(i<=target)
      ans = (ans + solve(target - i))%mod;
  }

  return dp[target] = (ans+mod)%mod;
}
int main()
{
  int n;
  cin>>n;
  memset(dp , -1 , sizeof(dp));
  long long ans = solve(n);
  ans %= mod;
  cout<<ans;
}

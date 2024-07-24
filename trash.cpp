#include<bits/stdc++.h>
using namespace std;

vector<int>arr;

int solve(int ind  , int sum)
{
  if(ind == arr.size())
    return sum == 0;

  int ans = 0;
  //take

  if(arr[ind] <= sum)
    ans += solve(ind+1 , sum - arr[ind]);

  // not take
  ans += solve(ind+1 , sum);

  return ans;
}

int main() {


  arr = {5, 2, 3, 10, 6, 8};
  int sum = 10;
  int ans = solve(0 , sum);
  cout<<ans;

}

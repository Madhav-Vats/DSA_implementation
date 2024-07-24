#include<bits/stdc++.h>
using namespace std;

int frec( int ind , int target , vector<int>&arr)
{
  //base case
  if(target ==0)
    return 1;
  if(ind ==0 )
    return (arr[ind]==target);

  int pick  = 0;;
  if(arr[ind] <= target)
  pick = frec(ind , target -arr[ind] , arr);

  // u can skip it
  int notPick = frec(ind-1 , target , arr);

  return pick + notPick;
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

  int target;
  cin>>target;

  vector<int>arr = {1,2,3,4,5,6};

  int n =6;

  int ans = frec(n-1, target , arr );
  cout<<ans;

}

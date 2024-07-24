#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// ----------------------        IMPORTANT         -----------------------------
// -----------------------------------------------------------------------------

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


  int t;
  cin>>t;

  while(t--)
  {
    int r;
    cin>>r;
    vector<int>arr1(r);
    for(int i=0;i<r;i++)
    {
      cin>>arr1[i];
    }

    int b;
    cin>>b;
    vector<int>arr2(b);
    for(int i=0;i<b;i++)
    {
      cin>>arr2[i];
    }


    //calculating prefix sum of both the arrays
    int sum1 = 0;
    int maxPrefix1 = 0;
    for(int i = 0 ;i<r;i++)
    {
      sum1 += arr1[i];
      arr1[i] = sum1;
      maxPrefix1 = max(maxPrefix1 , sum1);
    }

    int sum2 = 0;
    int maxPrefix2 = 0;
    for(int i = 0 ;i<b;i++)
    {
      sum2 += arr2[i];
      arr2[i] = sum2;
      maxPrefix2 = max(maxPrefix2 , sum2);
    }

    int ans = maxPrefix1 + maxPrefix2;

    ans = max(0 , ans);

    cout<<ans<<endl;

  }

  return 0;
}

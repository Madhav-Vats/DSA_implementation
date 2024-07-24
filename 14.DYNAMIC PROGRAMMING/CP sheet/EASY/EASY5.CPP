#include <bits/stdc++.h>
using namespace std;

int slidingWind(vector<int>&arr , int k , int n)
{
  //First window Calculation

  int minSum = 0;
  for(int i =0;i<k;i++)
  {
    minSum+=arr[i];
  }

  int currSum = minSum;
  int j = 0;

  int AnsIndex = 0;

  //Calculation for other Windows

  for(int i = k ;i<n;i++)
  {
    //adding the next element
    currSum+=arr[i];

    //removing the prec one
    currSum-=arr[j];

    j++;

    if(minSum > currSum)
    {
      minSum = currSum;
      AnsIndex = j;
    }
  }


  return AnsIndex+1;
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
  int k;
  cin>>n>>k;

  vector<int>arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  int ans = slidingWind(arr , k , n);

  cout<<ans<<endl;
}

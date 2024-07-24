#include<bits/stdc++.h>
using namespace std;


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
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }

    //logic
    int currVal= 0;
    int j = n-1;

    while(j>=0)
    {
      currVal = arr[j];
      int i = j;
      if(currVal > 0)
      {
        while( i>=0 && i>j-currVal)
        {
          arr[i] = 1;
          i--;
        }

        j=i;
      }
      else
      {
        arr[j] = 0;
        j--;
      }
    }

    for(int i =0;i<n;i++)
      cout<<arr[i]<<" ";

    cout<<endl;
  }



  return 0;
}

//majority element
#include <bits/stdc++.h>
using namespace std;


// maximum subarray sum

//brute force

//better



//kadane algorith
// don't carry forward the negative sum

int kadane_maximum_subarray(vector<int> &arr)
{
  int n=arr.size();
int maximum=INT_MIN;
int sum=0;
for( int i=0;i<n;i++)
{
  sum=sum+arr[i];
  if(sum<0)
  {
    sum=0;
  }
  if(sum>maximum)
  {
    maximum=sum;
  }
}
return maximum;
}


int main()
{
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

vector<int> a={-2,-3,4,-1,-2,1,5,-3};
int ans= kadane_maximum_subarray(a);
cout<<ans;
return 0;
}

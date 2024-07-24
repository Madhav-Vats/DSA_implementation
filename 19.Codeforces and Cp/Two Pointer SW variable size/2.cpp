#include<bits/stdc++.h>
using namespace std;

int MaxBookTwoPointer( int t , int n , vector<int>&arr)
{
  int i =0;
  int j = 0;

  int maxRead = 0;

  long remTime = t;

  //we are going to reduce the rem time every time on j
  // then if it becomes negative we will move our i pointer
  // to make it positive

  while(j<n)
  {
    remTime -= arr[j];

    while(i<=j && remTime<0)
    {
      remTime += arr[i];
      i++;
    }

    //now the we have remTime >=0
    //checking the max number of books read
    maxRead = max( maxRead , j-i +1);

    j++;
  }

  return maxRead;
}

int main()
{
  int n , t;
  cin>>n>>t;

  vector<int>arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  int ans = MaxBookTwoPointer( t ,n , arr);
  cout<<ans;
}

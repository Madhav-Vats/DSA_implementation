#include <bits/stdc++.h>
using namespace std;

pair<int,int> maxSumSubarray(vector<int>&arr , int n)
{
  int maxSum =  INT_MIN;
  int start = 0;
  int end = 0;
  for(int i=0;i<n;i++)
  {
    int subArraySum = 0;
    for(int j=i;j<n;j++)
    {
      subArraySum += arr[j];
      if(subArraySum >= maxSum)
      {
        start = i;
        end = j;
        maxSum = subArraySum;
      }
    }
  }

  return {start , end};

}

int main()
{
  vector<int>arr = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};

  int n = arr.size();

  pair<int,int>indices =  maxSumSubarray(arr , n);

  int start = indices.first;
  int end = indices.second;

  for(int i=start;i<=end;i++)
  {
    cout<<arr[i]<<" ";
  }

  return 0;
}

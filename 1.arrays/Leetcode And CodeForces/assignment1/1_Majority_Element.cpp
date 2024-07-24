#include<bits/stdc++.h>
using namespace std;

int BruteWay(vector<int>&arr , int n)
{
  unordered_map<int,int>freq;

  for(int i=0;i<n;i++)
  {
    freq[arr[i]]++;
  }

  for(auto &it :freq)
  {
    if(it.second > (n/2))
      return it.first;
  }
  return -1;
}


int majElements(vector<int>&arr , int n )
{
  if(n==0)
    return -1;
  if(n==1)
    return arr[0];

  //we take curr Element as arr[0] , we go linearly and if we get the
  //same elements we make count++ else count-- , the moment we reach a point where
  //count is negative , that indicates our currElements count is not greater that
  // n/2 means it cant be a majority element so , we make the jth element as currElement
  // and make count =1 , and check whether this one is our maj Elment or not

  // at the end we cross check the count of our currElements count ,
  // which we get after whole arrays traversal

  int currElement = arr[0];
  int count = 1;

  int j=1;

  while(j<n)
  {
    if(arr[j] == currElement)
    {
      count++;
    }
    else if(arr[j] != currElement)
      count--;

    if(count < 0)
    {
      currElement = arr[j];
      count = 1;
    }

    j++;
  }

  int currCount = 0;

  for(int i = 0;i<n;i++)
  {
    if(arr[i] == currElement)
    {
      currCount++;
    }
  }

  if(currCount > (n/2))
    return currElement;

  return -1;

}
int main()
{
  // {
  //   ios_base::sync_with_stdio(false);
  //   cin.tie(NULL);
  //
  //   #ifndef ONLINE_JUDGE
  //   freopen("input.txt","r",stdin);
  //  //freopen("output.txt","w",stdout);
  //   #endif
  // }
  vector<int>arr = {2,2,1,1,1,2,2};

  int n = arr.size();

  int ans = majElements(arr , n);
  cout<<ans;
}

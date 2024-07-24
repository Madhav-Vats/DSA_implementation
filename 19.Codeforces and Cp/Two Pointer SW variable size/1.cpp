
//---------------------------------------------------------------
// find the max size of the subarray having all unique elements
//---------------------------------------------------------------
/*
Constraints
1  - n - 2.10^5
1 - k  - 10^9

Example
Input:
8
1 2 1 3 2 7 4 2
*/

#include<bits/stdc++.h>
using namespace std;

int TwoPointerMaxSize(int n , vector<int>&arr)
{
  int i =0;
  int j =0;

  unordered_map<int,int>freq;  //(element , )
  //the map will store , count of elements , element

  int maxSize = 1;

  // 1 - { 2 , 4 , 5}  // means elements 2 , 4 , 5 has freq = 1
  while(j<n)
  {
    //including this new element to our new subarray
    freq[arr[j]]++;

    // now the element that we have added could lead to duplcacy
    //only this element could do this , so till its freq >1
    // we increase i , and delete the ith element from map

    while(i<=j && freq[arr[j]] >1)
    {
      //reducing the count of them in the map
      freq[arr[i]]--;
      //erasing its entry if it becomes 0
      if(freq[arr[i]] == 0)
      {
        freq.erase(arr[i]);
      }

      i++;
    }

    maxSize = max( maxSize , j-i+1);
    j++;
  }


  return maxSize;
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
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  int ans = TwoPointerMaxSize( n , arr);
  cout<<ans;
}

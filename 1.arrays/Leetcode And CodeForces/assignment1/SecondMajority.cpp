#include <bits/stdc++.h>
using namespace std;

int secondLargest(vector<int>&arr , int n)
{
  //Making a frequency map , which stores the freq
  //of each element

  vector<int>temp = arr;


  sort(temp.begin() , temp.end());

  int largest = temp.back();
  int secondLargest = largest;

  //search until u find
  while(secondLargest == largest)
  {
    temp.pop_back();
    secondLargest = temp.back();
  }

  return secondLargest;
}

int main()
{
  vector<int>arr = {1,2,3,4,6,7,7,7,7,1,1};
  int n = arr.size();

  int ans = secondLargest(arr , n);

  cout<<ans;
}

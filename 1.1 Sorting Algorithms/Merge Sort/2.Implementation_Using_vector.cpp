#include<bits/stdc++.h>
#include<string>
using namespace std;


void merge(vector<int>&arr , int start , int end)
{
  // we can easily assign (start to mid)
  // as first array and (mid+1 to end) as second array

  int mid = (start+end)/2;

  int len1 = mid-start+1;
  int len2 = end-mid;

  // making the two arrays dynamically
  int *left = new int[len1];
  int *right = new int[len2];

  //------------- filling elements into them--------------------
  int k = start;
  // we will increment k , which is a pointer to the parent array
  for(int i = 0; i< len1 ;i++)
  {
    left[i] = arr[k];
    k++;
  }

  for(int i=0;i<len2;i++)
  {
    right[i] = arr[k];
    k++;
  }

  //------------------------------------------------------------

  //using the exhaustion technique and merging of both the arrays
  int i = 0;
  int j = 0;

  int mainIndex = start;   // for filling in main Array

  while(i<len1 && j<len2)
  {
    if(left[i] < right[j])
    {
      arr[mainIndex] = left[i];
      i++;
      mainIndex++;
    }
    else
    {
      arr[mainIndex] = right[j];
      j++;
      mainIndex++;
    }
  }

  //when left is exhausted
  while(i< len1)
  {
    arr[mainIndex] = left[i];
    i++;
    mainIndex++;
  }

  while(j<len2)
  {
    arr[mainIndex] = right[j];
    j++;
    mainIndex++;
  }


  //now th main array has the sorted elements

  //we can delete these dynamically created arrays
  delete[] left;
  delete[] right;
}


void mergeSort( vector<int>&arr , int start , int end )
{
  //base case
  if(start>=end)
    return;

  int mid = (end+start)/2;

  // sort the first half of the array
  mergeSort(arr , start , mid );

  //sort the second half of the array
  mergeSort(arr ,mid+1 , end);

  merge(arr , start , end);

}

int main()
{
  vector<int>arr = {1,9,2,7,5,11,0};
  int size = arr.size();

  mergeSort(arr , 0 , size-1);

  for(auto &it: arr)
  {
    cout<<it<<" ";
  }

  return 0;
}

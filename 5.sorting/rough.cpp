#include <bits/stdc++.h>
using namespace std;


//merge sort

//divide and merge - into half

// 3 2 4 1 3

////merging two hypothetical arrays
// void merge( vector<int> &arr ,int low ,int mid ,int high )
// {
//   int n=arr.size();
//   int left =low;
//   int right=mid+1;
//   int i,j;
//
//   vector<int> temp;
// //    2 3 4      1 3
// // do with for loof
// j=right;
// for ( i=left ;i<mid+1 && j<high+1;i++)
// {
//   if(arr[i]<arr[j])
//   {temp.push_back(arr[i]);
//   j++;}
//   else
//   {temp.push_back(arr[j]);
//   j++;}
// }
// while( i<mid+1)
// {temp.push_back(arr[i]);}
// while (j<high+1)
// {temp.push_back(arr[j]);}
// }

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while( left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged elements back to the original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}
//
 void merge_sort( vector<int>&arr , int low , int high)
 {
  if(low>=high)
  {  return;  }
  int mid= (low+high)/2;
  merge_sort(arr,low,mid);
  merge_sort(arr,mid+1, high);
  merge(arr,low,mid,high);

 }
//
//
//


















//quick sort

int main() {

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    merge_sort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}

#include<bits/stdc++.h>
using namespace std;

#include "implementation_Revised.cpp"



void Heapify(vector<int>&arr , int n , int i)
{
  int left = 2*i+1;
  int right = 2*i+2;

  int largest = i;

  // we will search the largest child first
  // if any present greater than the so far largest node itself

  if(left < n && arr[left] > arr[largest])
  {
    largest  = left;
  }

  if(right < n && arr[right] > arr[largest])
  {
    largest  = right;
  }

  if(largest != i)
  {
    swap( arr[i] , arr[largest]);

    Heapify(arr , n , largest);
  }
}


void HeapSort(vector<int>&arr)
{

  //now elements after n/2 are leaf nodes , in a complete tree
  // and leaf nodes are always heap
  // so wll will only put the other elements into their correct position

  int n = arr.size();

  // Build Max Heap
  for( int i= n/2-1; i>=0;i--)
  {
    Heapify(arr , n ,  i);
  }



  // There is One more thing
  //------------------------------- Most import Step in Heap Sort----------------

  // heap sort main funda
  // input heap data ke format me hona chaiye
  //  last element ko root bnao , size = size-1 kro , and heapify algo lgao ,
  // isse apne aap , largest element of that particular size , end me aate rhenge ,
  // so in this algo also , we put largest element to their position , while , decresing the size
  // of array in consideration

  int size = n;

  // now the data is in heap sort format
 // We extract elements from the heap and place them at the end of the array
  while(size>1)
  {
      swap(arr[size-1] , arr[0]);
      size -= 1;

      // always pass the updated size
      Heapify(arr , size , 0);
  }
}





int main()
{

  vector<int>arr = {5,2,9,1,6};
  HeapSort(arr);


  for(auto& it : arr)
  {
    cout<<it<<" ";
  }




  return 0;
}

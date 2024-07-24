#include<bits/stdc++.h>
using namespace std;


void swap( int &a , int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

class Heapi
{
public:
  vector<int>arr;
  int size = 0;

  void Heapify( int i )
  {
    int left = 2*i+1;
    int right = 2*i+2;

    int largest = i;

    // we will search the largest child first
    // if any present greater than the so far largest node itself

    if(left < size && arr[left] > arr[largest])
    {
      largest  = left;
    }

    if(right < size && arr[right] > arr[largest])
    {
      largest  = right;
    }

    if(largest != i)
    {
      swap( arr[i] , arr[largest]);

      Heapify(largest);
    }
  }

  void HeapifyParent(int i )
  {
    if(i == 0)
      return;

    int parent =  (i-1)/2;

    if(arr[i] > arr[parent])
    {
      swap(arr[i] , arr[parent]);

      // now we will again chech the position of it
      HeapifyParent(parent);
    }
  }

  void insert( int element)
  {
    arr.push_back(element);
    size += 1;
    int i = size-1;
    // int parent  = (i-1)/2;

    HeapifyParent( i );
  }

  void deleteElement()
  {
    if(size==0)
    {
      cout<<endl<<" no element is present"<<endl;
      return;
    }

    int LastElement =  arr[size-1];
    arr[0] =  LastElement;

    arr.pop_back();
    size--;

    int i = 0;

    Heapify(i);
  }


  void PrintArray()
  {
    for(auto &it : arr)
    {
      cout<<it<<" ";
    }
  }

};


// we will use this class in other files

// int main()
// {
//
//
//   Heapi heap;
//
//   heap.insert(12);
//   heap.insert(24);
//   heap.insert(46);
//   heap.insert(33);
//   heap.insert(21);
//
//   heap.PrintArray();
//   cout<<endl;
//
//   heap.deleteElement();
//
//   heap.PrintArray();
//
//
//
//
//   return 0;
// }

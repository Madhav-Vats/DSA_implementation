#include<bits/stdc++.h>
using namespace std;


void swap( int &a , int & b)
{
    int temp = a;
    a = b;
    b = temp;
}


void heapify(vector<int> &ans , int & element)
{
    ans.push_back(element);
    // parent element is always at i/2
    int i = ans.size() -1 ;
    while (i> 0)
    {
      while(ans[i] == ans[(i-1)/2])
      {
        swap(ans[i] , ans[(i-1)/2 ]);
        i = (i-1)/2;

      }
      while(ans[i] < ans[(i-1)/2])
       {
         swap(ans[i], ans[(i-1)/2]);
         i = (i-1)/2;
       }

     }
}

void heapify_insertt(vector<int> &ans , int & element)
{
    ans.push_back(element);
    // parent element is always at i/2
    int i = ans.size() -1 ;
    while (i> 0 && ans[i] < ans[(i-1) / 2])
       {
        swap(ans[i], ans[(i-1) / 2]);
        i = (i-1)/2;
       }
}


void heapify_cht_gpt(vector<int> &ans, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (ans[i] == ans[parent]) {
            swap(ans[i], ans[parent + 1]);  // Ensure consecutive duplicates
            i = parent;
        } else if (ans[i] < ans[parent]) {
            swap(ans[i], ans[parent]);
            i = parent;
        } else {
            break;
        }
    }
}


// void heapify(vector<int> &ans , int  i)
// {
//
//    int largest = i ;
//    int left = 2*i+1;
//    int right = 2*i+2;
//    int size = ans.size();
//
//    if(left<size && ans[i]> ans[left])
//     largest = left;
//
//    else if(right<size && ans[i]> ans[right])
//     largest = right;
//
//     if(largest != i)
//     {
//         swap(ans[i],ans[largest]);
//         heapify(ans,largest);
//     }
// }



void heapify_insert(vector<int> &ans, int &element) {
    ans.push_back(element);
    // parent element is always at i/2
    int i = ans.size() - 1;
    int priority = i;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (ans[i] > ans[parent] || (ans[i] == ans[parent] && priority > parent)) {
            swap(ans[i], ans[parent]);
            i = parent;
        } else {
            break;
        }
    }
}



vector<int> buildMinHeap_using_insertion(vector<int> &arr)
{
    // one base indexing

vector<int> ans;
int n = arr.size();
    // upto n/2 -1 indexing we have non leaf nodes
for (int i = 0; i < n; i++)
    heapify(ans,arr[i]);

    return ans;


    // 1 base indexing

    // Write your code here
}

vector<int> buildMinHeap_using_cht_insertion(vector<int> &arr)
{
    // one base indexing

vector<int> ans;
int n = arr.size();
for( int i =0; i< n ; i++)
  ans[i] = arr[i];

    // upto n/2 -1 indexing we have non leaf nodes
for (int i = n-1; i >= 0; i--)
    heapify_cht_gpt(ans,i);

    return ans;


    // 1 base indexing

    // Write your code here
}



vector<int> buildMinHeap(vector<int> &arr)
{
    // one base indexing
    vector<int> ans;
int n = arr.size();
    // upto n/2 -1 indexing we have non leaf nodes
for (int i = 0; i < n; i++)
    heapify_insert(ans,arr[i]);

    return ans;


    // 1 base indexing

    // Write your code here
}


void heapify_min( vector<int> & arr , int i , int size )
{
     int smallest = i ;
     int left = 2*i+1;
     int right = 2*i+2;

     if(left < size && arr[i] > arr[left])

      smallest = left;

     else if(right < size && arr[i] > arr[right])

      smallest = right;

      if(smallest != i)
      {
          swap(arr[i],arr[smallest]);
          heapify_min(arr, smallest , size);
      }

}

void heapify_max( vector<int> & arr , int i , int size )
{
     int largest = i ;
     int left = 2*i+1;
     int right = 2*i+2;

     if(left < size && arr[i] < arr[left])

      largest = left;

     else if(right < size && arr[i] < arr[right])

      largest = right;

      if(largest != i)
      {
          swap(arr[i],arr[largest]);
          heapify_max(arr, largest , size);
      }

}

class info
{
public:
};


int main() {

  priority_queue <pair<int ,pair<int,int>>> pq;

  pair<int,int> a = {2,5};
  pair<int,int> b = {7,11};
  pair<int,int> c = {1,11};
  pq.push({3,a});
  pq.push({4,b});
  pq.push({10,c});
  pair<int ,pair<int,int>> p = pq.top();
  cout<<p.first;
  return 0;
}

class Solution {
public:

    int b_s( vector<int> & arr , int  &element )
    {
        int size = arr.size();
        int low = 0;
        int high = size-1;
        int ans;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(arr[mid] == element)
            {
                ans = mid;
                break;
            }
            else if( arr[mid] > element)
            {
                low = mid+1;
            }
            else
                high = mid-1;
        }
        if (low > high) {
        ans = low;
    }

        return ans;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int size  = arr.size();
        set<int> s;

        int ind = b_s( arr, x);

        // two pointers
        int i=ind-1;
        int j = ind+1;

        s.insert(x);

        // as the given element can also be included
        while((k>=1 && i>=0) && j< size )
        {
            int left = abs(arr[i] - x);
            int right = abs(arr[j] - x);

            if( left<=right)
            {
                s.insert(arr[i]);
                k--;
                i--;
            }
            else
            {
                s.insert(arr[j]);
                k--;
                j++;
            }

        }
        while(k>=1 && i>=0)
        {
            s.insert(arr[i]);
            i--;
            k--;
        }

        while(k>=1 && j< size )
        {
            s.insert(arr[j]);
            j++;
            k--;
        }

        vector<int> ans;
        for( auto i : s)
        {
            ans.push_back(i);
        }

        return ans;


    }
};

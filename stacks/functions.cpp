#include <bits/stdc++.h>
using namespace std;
/*
// void sort_vector( vector<int> &arr)
// {
//   int size = arr.size();
//   int n=size;
//   for(int i=0;i<size-1;i++)
//   {
//     int mini=arr[i];
//     for(auto j=i+1;j<size;j++)
//     {
//       if(arr[j]>mini)
//       mini=arr[j];
//     }
//     swap_(arr[i],mini);
//
//   }
// }
*/
void sort_s(vector<int> &arr)
{int n= arr.size();   //size of the array

for(int i=0;i<=n-2;i++)
{
  int mini=i;
  for(int j=i+1;j<=n-1;j++)
  {
    if(arr[j]<arr[mini])
    { mini=j; }
  }
  if(mini!=i)
  {
    int temp=arr[i];
    arr[i] = arr[mini];
    arr[mini]=temp;
  }
}
}

class brute_sort_stack
{
public:

void empty_making( stack<int> &st)
{
  int size=st.size();
  for(int i=0;i<size;i++)
  {
    st.pop();
  }
}
void sort_stack(stack<int> &st , int size ,vector<int> &arr)
{
  //base
  if(st.empty())
  {
    sort_s(arr);
    empty_making(st);
    for(int i=size-1;i>=0;i--)
    {
      st.push(arr[i]);
    }
    return;
  }

  int temp= st.top();
  arr.push_back(temp);
  st.pop();
  sort_stack(st , size , arr);
}
};



  void sorted_insert( stack<int> &st , int element)
  {
    //base
    if(st.empty()|| st.top()<element)
      {st.push(element);
      return;}

    int t= st.top();
    st.pop();
    //recursive call
    sorted_insert(st,t);
    st.push(t);

  }
  void sort_stack( stack<int> &st)
  {
    if (st.empty())
      return;
    int temp= st.top();
    st.top();
    sort_stack(st);

    sorted_insert(st,temp);
  }

  void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    //recusrive call
    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack(stack<int> &stack)
{
		//base case
    	if(stack.empty()) {
            return ;
        }

    	int num = stack.top();
    	stack.pop();

    	//recursive call
    	sortStack(stack);

    	sortedInsert(stack, num);
}

int main() {
    stack<int> st;

    // Push some elements onto the stack
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  vector<int> arr;
  sortStack(st);
  for(int i=0;i<5;i++)
  {
    cout<<st.top()<<" ";
    st.pop();
  }
}

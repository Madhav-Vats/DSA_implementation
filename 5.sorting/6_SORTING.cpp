#include <bits/stdc++.h>
using namespace std;


void swap(int &elem1 ,int &elem2)
{
  int temp=elem1;
  elem1=elem2;
  elem2=temp;
}


void Selection_sort( vector<int> &arr)
{
  int n= arr.size();   //size of the array

  for(int i=0;i<=n-2;i++)
  {
  /*
  loop from 0 to n-1 only
  bcoz we need to find minimimums after arr[i]
  so that we ccaan swap these elements
*/

  // considering first element to be the minimimum
    int mini=i;

  /*
  loop from i+1 to the end of the array to find if there is
  any element less that arr[i]
*/
    for(int j=i+1;j<=n-1;j++)
    {
      if(arr[j]<arr[mini])
      { mini=j; }
    }

    // swap(arr[i],arr[mini]) if minimum is not arr[i]
    if(mini!=i)
    {
      int temp=arr[i];
      arr[i] = arr[mini];
      arr[mini]=temp;
    }
  }
}

void tBubble_sort( vector<int> &arr)
{
  int n=arr.size();
  for(int i=n-1;i>0;i--)
  {
    for(int j=0;j<i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
      }
    }
  }
}

void Bubble_sort( vector<int> &arr)
{
  int n=arr.size();
  for(int i=0;i<=n-2;i++)
  //go for 0 to second last element , bcoz j loop will check for j+1
  {
    for(int j=0;j<=n-i-2;j++)
    // goint from 0 to max value of ith loop , if n=5 , i->0 to 3 , j-> 0 to 2z
    // to put the largest element at the end of jth loop
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j],arr[j+1]);
      }
    }
  }
}


int main()
{
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  #endif
}
vector<int> v={1,7,1,5,3,4};
Selection_sort(v);

for( int i=0;i<6;i++)
{
  cout<<v[i]<<" ";
}
return 0;
}

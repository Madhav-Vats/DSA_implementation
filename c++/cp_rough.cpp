#include <bits/stdc++.h>
#include <vector>
using namespace std;
void Swap(int &elem1 ,int &elem2)
{
  int temp=elem1;
  elem1=elem2;
  elem2=temp;
}

void print(int *arr, int n)
{
  int i=0;
  cout<<"the array is --  ";
  while(i<n)
  {
    cout<<arr[i]<<" ";
    i++;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

int n=5;
int arr[5]={1,2,3,4,5};
Swap(arr[0],arr[4]);

print(arr,n);
}

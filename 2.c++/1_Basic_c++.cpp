#include <bits/stdc++.h>
using namespace std;

void nd(int n) {
    // Write your code here.
    for(int i=0;i<2*n;i++)
    {
        if(i<n)
        {
            //spaces
            for (int j=0;j<n-i-1;j++)
                cout<<" ";
            //stars
            for (int k=0;k<2*i+1;k++)
                cout<<"*";
            //spaces
            for (int j=0;j<n-i-1;j++)
                cout<<" ";
        }
        if(i>=n)
        {
            //spaces
            for(int j=0;j<i-n;j++)
            cout<<" ";
            //stars
            for(int k=0;k<4*n-2*i-1;k++)
            cout<<"*";
            //spaces
            for(int j=0;j<i-n;j++)
            cout<<" ";
        }
        cout<<endl;
    }
}


void nBinaryTriangle(int n) {
    // Write your code here.
    for (int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=0;j<i;j++)
            {
                int k=1;
                k=(k+j)%2;
                cout<<k<<" ";
            }
        }
        if(i%2==0)
        {
            for (int j = 0; j < i; j++)
            {
                int k = 0;
                k = (k + j)%2;
                cout << k<<" ";
            }
        }
        cout<<endl;
    }

}

void alphaHill(int n) {
    // Write your code here.
    for (int i=0;i<n;i++)
    {
        int ch=65;
        //spaces
        for (int j=0;j<n-i-1;j++)
        cout<<" ";
        //alpha
        for (int k=0;k<2*i+1;k++)
        {cout<<"*";
        }
        //spaces
        for (int j=0;j<n-i-1;j++)
        cout<<" ";

        cout<<endl;
    }
}
void reverse_array( int *arr , int n )
{
  int i=1;
  int j=n;
  while(i<=n && j>=1)
  {
    swap(arr[i],arr[j]);
    j--;
  }
}
void swap(int &elem1 ,int &elem2)
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


int sumof( int n)
{
  //base
  if(n==0)
  return 0;
  else
  return n+sumof(n-1);
}

void reverse(vector<int> &arr , int size , vector<int> &arr2, int n )
{
  // base condition
  if (n>=size)
    return;

  // recursive call
  reverse(arr, size , arr2 , n+1);

  //processing
  arr2.push_back(arr[n]);
}


void reverse_swap_array(int *arr , int size , int n)
{
  //base
  if(n>=size/2)
    return;

  //processing at first--> for tail recursion

//swap(arr[n],arr[size-1-n]);

  //recursive call
  reverse_swap_array(arr,size , n+1);

  //processing at last ---> head recursion
  swap(arr[n],arr[size-1-n]);
}


void palindrome( int *arr , int size , int n ,int &ans )
{
  //base
  if(n>=size/2)
    return;

  else if( arr[n]==arr[size-1-n])
    ans=1;
  else
    ans=0;

  //recursive call
  palindrome(arr,size , n+1, ans);
}



void max_min( int *arr ,int size , int n , int &maxi , int &mini )
{
  //base
  if(n>=size/2)
    return;

  //processing at first --> tail recursion
  maxi= max(arr[n],maxi);
  mini=min(arr[n],mini);

  //recursive call
  max_min( arr ,size , n+1 , maxi , mini);
}

  int main()
  {
    int size=8;
    int mini=INT_MAX;
    int maxi= INT_MIN;
    // int arr[8] = { -1,-33,0,-124,-13,-2,-6,-665};
    // int ans;
    cout<<min(-4,0);
    // max_min(arr,size ,0 ,maxi ,mini);
    // cout<<maxi<<endl<<mini;
    return 0;
  }

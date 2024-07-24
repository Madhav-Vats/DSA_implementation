#include <bits/stdc++.h>
#include <vector>
using namespace std;
#include <map>


// ********************************************************************
int size_array(int *arr)
{
  return sizeof(arr)/sizeof(*arr);
}
int max( int a , int b)
{
  if(a>b)
  return a;
  else
  return b;
}
int min( int a , int b)
{
  if(a<b)
  return a;
  else
  return b;
}

int min_arr(int *arr , int n )
{
  int min =INT_MAX;
  int i=0;
  while(i<n)
  {
    if (arr[i]<min)
    min=arr[i];
    i++;
  }
  return min;
}


// approach = if you are selling at a day the buying should be before that and should be minimum.
// in this approach we are finding the previoun min by using a loop , which is adding extra O(N) in the time complexity
void max_profit_stock_day(int *arr , int size )
{
  int maximum=INT_MIN;
  for ( int i=0;i<size;i++)
  {
    int m=min_arr(arr,i);
    maximum= max(arr[i]-m,maximum);
  }
  cout<<maximum;
}

// everytime one element is being added to the previous array , so why not to take the min( previous min , this new element ) so that we would not use any extra 4_Array
// but for that case you need to start the iteration from 2nd element , just observe thi thing

// now how to get the indexes of those elements
void BB_max_profit_stock_day_41(int *arr , int size )
{
  int maximum=INT_MIN;
  int minimum= INT_MAX;
  int ind_min=-1;
  int ind_max=-1;
  for ( int i=1;i<size;i++)
  {
    minimum= min( minimum , arr[i-1]);
    // if(minimum==arr[i-1])
    // {
    //   ind_min=i-1;
    // }
    maximum= max(arr[i]-minimum,maximum);
    // if(maximum==arr[i])
    // {
    //   ind_max=i;
    // }
  }
  cout<<maximum;
  // <<"buy on day="<<ind_min+1<<" sell on day = "<<ind_max+1;
}


vector<int> BB_leaders_in_array_41( vector<int> &arr)
{
  int n= arr.size();
  vector<int> ans;

  for(int i=0;i<n;i++)
  {
      bool leader= true;
    // making this leader so that whenever its condition is true
    // then add that element to the ans otherwise mot

    for(int j=i+1;j<n;j++)
        {
          if (arr[i]<arr[j])
          {
            leader=false;
            break;
          }}

    if(leader==true)
    ans.push_back(arr[i]);
}
return ans;
//iteratng the whole array , and  whenever you find an element greater than it ,
// after it, break the 2nd loop and go for checking the next element whether it is leader or not ,
// but what ot do when conditions are true , how to add only that element to the answer ..
// for that case make a bool , ( or you can specify an int also , evertime it is +1 ,
// if conditions are false make it -1)
// only when that bool or int is true or positive , then add that element in answer otherwise don't

}


vector<int> OP_leaders_in_array_41(vector<int> &arr)
{
  int n=arr.size();
  vector<int> ans;
  int maximum=INT_MIN;
  for(int i=n-1;i>0;i--)
  {

    if(arr[i]>maximum)
    {
      maximum=arr[i];
      ans.push_back(arr[i]);
    }
  }
  return ans;
}





void rearrange(int arr[], int n )
{


}
// C++ program to rearrange an array in minimum
// maximum form
// Prints max at first position, min at second position
// second max at third position, second min at fourth
// position and so on.
// 	Input: arr[] = {1, 2, 3, 4, 5, 6, 7}
// Output: arr[] = {7, 1, 6, 2, 5, 3, 4}
//
// Input: arr[] = {1, 2, 3, 4, 5, 6}
// Output: arr[] = {6, 1, 5, 2, 4, 3}


void assign(int a[], int n)
{
// C++ program to rearrange the elements in array such that
// even positioned are greater than odd positioned elements



}



void print3largest(int arr[], int arr_size)
{
//largest 3 unique numbers
}
int findNumberOfTriangles(int arr[], int n)
{
// Given an unsorted array of positive integers,
// find the number of triangles that can be formed with
// three different array elements as three sides of triangles.
// For a triangle to be possible from 3 values, the sum of any of the two values
// (or sides) must be greater than the third value (or third side).

}

void subArraySum(int arr[], int n, int sum)
{//Returns true if the there is a subarray of arr[] with a sum equal to
//'sum' otherwise returns false. Also, prints the result */
}







int main()
{
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}
int arr[6]={1,7,1,5,3,4};
BB_max_profit_stock_day_41(arr,6);
return 0;
}

#include <bits/stdc++.h>
using namespace std;


//----------------------------------------------------------
//---------------   NOT WORKING

//inputs
// 4 10
// 10
// 21
// 27
// 27

int frec(int ind , int remaining_gems , int l , vector<int>&arr)
{
  //everytime when we pickup a gem we make n--
  //and if n<0 that means no gems are left to be collected
  if(remaining_gems == 0)
    return 0;


  if(arr[ind] == 1)
  {
    return 1 + max(frec(ind+l , remaining_gems -1 , l , arr) , max(frec(ind+l-1 , remaining_gems -1 , l-1 , arr) , frec(ind+l+1 , remaining_gems -1 , l+1 , arr)));
  }

  return max(frec(ind+l , remaining_gems  , l , arr) , max(frec(ind+l-1 , remaining_gems  , l-1 , arr) , frec(ind+l+1 , remaining_gems  , l+1 , arr)));
}




int main()
{

  vector<int>arr(30001 , 0);

  int n,d;
  cin>>n>>d;

  for(int i =0;i<d;i++)
  {
    int val;
    cin>>val;
    arr[val] = 1;  // places having gem = 1
  }

  int ans = 0;

  ans = frec(d , n , d , arr); // we are passing the initial index as first jump position
  //first index = d , prevJump value =d;
  cout<<ans;
  return 0;
}

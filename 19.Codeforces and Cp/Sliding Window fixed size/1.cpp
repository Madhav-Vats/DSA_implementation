// int t testcases
// int n , array given of size n
// int d
//---------------------------------------------------------------------
// you need to find the subarray of size d having min distinct elements
//----------------------------------------------------------------------
//SLIDING WINDOW PROBLEM

//inputs
// 4
// 5 2 2
// 1 2 1 2 1                         o/p----> 2
// 9 3 3
// 3 3 3 2 2 2 1 1 1                 o/p----> 1
// 4 10 4
// 10 8 6 4                          o/p----> 4
// 16 9 8
// 3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3   o/p----> 5


#include<bits/stdc++.h>
using namespace std;

int SlidingWind( int d , int n , vector<int>&arr)
{

  // minimum shows to be subscribed
  int miniShows = INT_MAX;
  //
  // int currShows = 0;

  unordered_map<int,int> subscribed;   // element , count

  // first window
  for(int i=0;i<d;i++)
  {
    if(subscribed.find(arr[i]) == subscribed.end()) //wasnt present
    {
      subscribed[arr[i]] =1;
    }
    else if(subscribed.find(arr[i]) != subscribed.end())
    {
      subscribed[arr[i]]++;
    }
  }

  int currSize = subscribed.size();
  miniShows = min(currSize , miniShows);

  if(d==n)
    return subscribed.size();


  int j = d;
  //sliding the windows

  for(int i =1;i<=n-d;i++)
  {
    //removing the prev Element
    //decreasing the count of arr[i-1]
    subscribed[arr[i-1]]--;
    if(subscribed[arr[i-1]] == 0)
    {
      //removing its entry from the map
      subscribed.erase(arr[i-1]);
    }


    //adding the new element
    if(subscribed.find(arr[j]) != subscribed.end()) //means its present already
    {
      subscribed[arr[j]]++;
    }

    else if(subscribed.find(arr[j]) == subscribed.end()) // have to create new entry
    {
      subscribed[arr[j]] = 1;
    }

    int size = subscribed.size();

    miniShows = min(miniShows , size);

    j++;
  }

  return miniShows;
}



int main()
{
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    #endif
  }


  int t;
  cin>>t;

  while(t--)
  {
    int n , k ,d;
    cin>>n>>k>>d;


    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    //getting the sliding window minimum

    int ans = SlidingWind(d , n , arr);
    cout<<ans<<endl;
  }

  return 0;
}

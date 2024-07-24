// sort the arrays of 0s 1s ans 2s
// 3s 4s 5s

//brute force
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#include <map>



//optimal

void swap(int &elem1 ,int &elem2)
{
  int temp=elem1;
  elem1=elem2;
  elem2=temp;
}

vector<int> rearrange_consecutive3_deutsch_national_flag_algo(vector<int> &arr)
{
  int n=arr.size();
  int low=0;
  int mid=0;
  int high=n;

  while(mid<high)
  {
    if(arr[mid]==3)
    {
      swap(arr[mid],arr[low]);
      low++;
      mid++;
    }

    if(arr[mid]==4)
    {
      mid++;
    }
    if(arr[mid]==5)
    {
      swap(arr[high-1],arr[mid]);
      high--;
    }
  }
  return arr;
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

vector<int> a={3,4,4,3,4,5,4,5,3,3,3};
vector<int>ans= rearrange_consecutive3_deutsch_national_flag_algo(a);
for(auto it:ans)
{
  cout<<it<<" ";
}
return 0;
}

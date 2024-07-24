#include <bits/stdc++.h>
#include <vector>
using namespace std;

void print_vector( vector<int> & arr)
{
  int size = arr.size();
  for(int i=0;i<size; i++)
  {
    cout<<arr[i]<<" ";
  }
}
void print_F( vector<int> &arr , int ind , vector<int> &ds , int size)
{
  //base
  if(ind==size)
  { for(auto it : ds)
      cout<<it<<" ";
    cout<<endl;
    return;  }

  ds.push_back(arr[ind]);
  print_F(arr , ind+1 , ds ,size);

  ds.pop_back();
  print_F(arr, ind+1 ,ds ,size);

}



void sum_sequence(vector<int> &arr , int ind , vector<int> &ds , int size , int s,int sum ,int &counter)
{
  //base
  if(ind==size)
  { if(s==sum)
    {for(auto it: ds)
        {cout<<it<<" ";}
    counter++;
    cout<<endl;}

  return;  }

  //pick
ds.push_back(arr[ind]);
s+=arr[ind];
sum_sequence(arr,ind+1,ds,size,s,sum ,counter);
//jo add kiya pick krte time usko nikalna bhi to hai
ds.pop_back();
s-=arr[ind];
//not pick
sum_sequence(arr,ind+1,ds,size,s,sum ,counter);

}

int counter_0_and_1(vector<int> &arr , int ind , vector<int> &ds , int size , int s,int sum )
{
  //base
  if(ind==size)
  {
    if(s==sum)
    {return 1;}
    else
    {return 0;}
  }
  // take the element
  s+=arr[ind];
  int l= counter_0_and_1(arr,ind+1, ds, size , s , sum);
  //before not take remove it from the sum
  s-=arr[ind];
  //not take
  int r=counter_0_and_1(arr,ind+1,ds,size,s,sum);
  return l+r;
}


void sum__all_subsets(vector<int> &arr , int ind , vector<int> &ds , int size, int s )
{
  //base
  if(ind==size)
  {
    ds.push_back(s);
    return;
  }
  //pick
  // s+=arr[ind];
  sum__all_subsets(arr,ind+1,ds,size,s+arr[ind]);
  // s-arr[ind];
  //not pick
  sum__all_subsets(arr, ind+1,ds,size,s);
}

vector<int>all_subsets_sum(vector<int> &arr , vector<int> &ds)
{
  int size=arr.size();
  sum__all_subsets(arr,0,ds,size,0);
  return ds;
}


class subset_II
{
public:

void print_Fu( vector<int> &arr , int ind , vector<int> &ds , vector<vector<int>> &ans , int size)
{
  //base
  if(ind==size)
  { ans.push_back(ds);
    return;  }

  ds.push_back(arr[ind]);
  print_F(arr , ind+1 , ds ,size);

  ds.pop_back();
  print_F(arr, ind+1 ,ds ,size);

}
void sets(  vector<int> &arr , vector<vector<int>> &ans, set<vector<int>> &st)
{
  int size=arr.size();
  vector<int> ds;
  print_Fu(arr,0,ds , ans , size);
  for(auto it: ans)
  {
    st.insert(it);
  }
}};

int main()
{{
  ios_base::sync_with_stdio(false);
cin.tie(NULL);

#ifndef ONLINE_JUDGE
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
#endif
}
vector<int> arr={1,2,3,2};
int size=arr.size();
int sum=5;
int cnt=0;
set<vector<int>> st;
vector<vector<int>>ans;
sets(arr,ans,st);
for(auto it:st)
{
  for(auto iter:it)
  {
    cout<<iter<<" ";
  }
  cout<<endl;
}
return 0;
}

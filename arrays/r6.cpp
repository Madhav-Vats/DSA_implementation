
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#include <map>




//leader in an array optimal

int max( int a , int b)
{
  if(a>b)
  return a;
  else
  return b;
}

int presence(vector<int> &arr , int element)
{
  int n =arr.size();
  for(int i=0;i<n;i++)
  {
    if(arr[i]==element)
    {
      return 1;
    }
  }
  return -1;
}
int longest_consecutive_sequence( vector<int> &arr)
{
  int n =arr.size();
  int longest=1;
  int cnt;
  for(int i=0;i<n;i++)
  {
    int x=arr[i];
     cnt=1;
    while(presence(arr,x+1)==1)
      {
        x+=1;
        cnt++;
      }
    longest=max(longest,cnt);
  }
  return longest;
}


int BBB_gpt_longest_consecutive_sequence(std::vector<int> &arr)
{
    int n = arr.size();
    if (n == 0) return 0;  // Handle the case of an empty vector.

    sort(arr.begin(), arr.end());
    int longest = 1;
    int current = 1; // Current consecutive sequence length
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            current++; // Increment the consecutive sequence length
        }
        else if (arr[i] != arr[i - 1])
        {
            current = 1; // Reset the consecutive sequence length if not consecutive
        }
        longest = max(longest, current);
    }
    return longest;
}



int BBB_approach1_mine_longest_consecutive_sequence(vector<int> &arr)
{
  int n =arr.size();
  sort(arr.begin(), arr.end());
  int cnt=1;
  int longest=1;
  //1,1,1,2,3,4,100,101,102
    int j=0;
    for(int i=0;i<n;i++)
    {
      j=i+1;
      int x=arr[i];
      if(arr[j]==x+1)
      {
        cnt++;
        j++;
      }
      else if(arr[j]==x)
      {
        j++;
      }
      else if(arr[j]!=x+1)
      {
        cnt=0;
      }


      longest=max(longest,cnt);
    }
    return longest;

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

vector<int> a={102,100,4,1,101,3,1,2,1,104,105,107,5,6,7,8,9,108,107};
int ans=BETTER_longest_consecutive_sequence(a);
cout<<ans;
return 0;
}

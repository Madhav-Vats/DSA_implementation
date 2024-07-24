#include<bits/stdc++.h>
#include<string>
using namespace std;

  // pearl in a row (C)

int main()
{
  int n;
  cin>>n;

  vector<int>arr(n);

  for(int i=0;i<n;i++)
    cin>>arr[i];

  // splitting into good segments
  unordered_map<int,int>present;

  vector<pair<int,int>> ans;  // that stores the starting and end index
  // of the good segment , and we want maximum good segments

  int startingIndex = 0;

  for(int i=0;i<n;i++)
  {
    if(present.find(arr[i]) != present.end())
    {
      // mean this element is already present
      ans.push_back({startingIndex , i});
      startingIndex = i+1;
      present.clear();
    }

    else
    {
      present[arr[i]]++;
    }
  }

  if(ans.size() == 0)
  {
    cout<< -1;
    return;
  }

  else
  {
    cout<<ans.size()<<endl;
    for(auto &it : ans)
      cout<<it.first+1<<" "<<it.second+1<<endl;
  }
}

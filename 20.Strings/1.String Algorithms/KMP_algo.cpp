#include<bits/stdc++.h>
using namespace std;



vector<int> LPSarray(string &s)
{
  int size = s.length();

  vector<int>lps(size , 0);


  // by default t index 0 , we put value 0
  // and start traversing from index 1
  for(int i=1;i<size;i++)
  {
    int prev_val = lps[i-1];

    //if doesnt match then go back until prev_val becomes 0
    while(prev_val > 0 && s[i] != s[prev_val])
    {
      // we reducs the prevVal , bcoz we should not add
      // this to lps[i] if they are not even matching
      prev_val = lps[prev_val-1];
    }

    lps[i] = prev_val + (s[i] == s[prev_val]? 1:0);

  }

  return lps;
}


vector<int>MatchingFirstIndices(string &s1 , string &pattern)
{
  string combinedString = pattern + "#" + s1;

  vector<int>lps;
  int patternSize = pattern.size();

  //creating of LPS array
  lps = LPSarray(combinedString);


  for(auto &it : combinedString)
    cout<<it<<" ";

  cout<<endl;

  for(auto &it : lps)
    cout<<it<<" ";

  vector<int>ans;

  for(int i=0;i<lps.size();i++)
  {
    if(lps[i] == patternSize)
    {
      int ind = i - 2*patternSize;

      if(ind >=0)
        ans.push_back(ind);
    }
  }

  return ans;
}






int main()
{
  string s1 = "aabaacaabaad";
  string s2 = "aab";

  vector<int>Temp = MatchingFirstIndices(s1 , s2);



  cout<<endl;

  for(auto &it : Temp)
    cout<<it<<" ";


  return 0;
}

#include<bits/stdc++.h>
#include<string>
using namespace std;

// all possible strings
vector<string> AllStrings( int ind  , int length , string&s)
{
  //base case
  if(ind == length)
    return {""};

  string WordSoFar = "";

  vector<string>subproblem , completePack;

  for(int j=0 ;j<length; j++) // any one could come to this ind
  {
    WordSoFar += s[j];

    subproblem = AllStrings(ind+1 , length , s);

    for(int i = 0 ; i<subproblem.size(); i++)
    {
        subproblem[i] =  WordSoFar + subproblem[i];
    }

    for(auto &s : subproblem)
    {
      completePack.push_back(s);
    }

    WordSoFar.pop_back();   // for new elements to come in
  }

  return completePack;
}


int main()
{
  string s = "ABC";
  vector<string> ans = AllStrings(0 , 3 , s);

  // handling duplicacy
  set<string>st;
  for(auto &it: ans)
  {
    st.insert(it);
  }

  vector<string>arr;

  for(auto &it: st)
  {
    arr.push_back(it);
  }

  for(auto &it: arr)
  {
    cout<<it<<" ";
  }


  return 0;
}

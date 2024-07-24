#include<bits/stdc++.h>
#include<string>
using namespace std;



vector<string> allValidSent( int ind  , int length , string&s , unordered_map<string, bool> &dictionary)
{
  //base case
  if(ind == length)
    return {""};

  string WordSoFar ="";

  vector<string>subproblem , completePack;

  for(int j = ind ;j<length;j++)
  {
    WordSoFar += s[j];

    if(dictionary.find(WordSoFar) == dictionary.end())
    {
      continue;
    }

    subproblem = allValidSent(j+1 , length , s , dictionary);

    for(int i = 0 ; i<subproblem.size(); i++)
    {
      if(subproblem[i].size() > 0)
        subproblem[i] =  WordSoFar + " " + subproblem[i];

      else
        subproblem[i] = WordSoFar + "" + subproblem[i];
    }

    for(auto &s : subproblem)
    {
      completePack.push_back(s);
    }

    // WordSoFar.pop_back();   // for new elements to come in
  }

  return completePack;
}


vector<string> MemoizedCode( int ind  , int length , string&s , unordered_map<string, bool> &dictionary , unordered_map<int , vector<string>> &dp)
{
  //base case
  if(ind == length)
    return {""};

  if(dp.find(ind) != dp.end())
  {
    return dp[ind];
  }

  string WordSoFar ="";

  vector<string>subproblem , completePack;

  for(int j = ind ;j<length;j++)
  {
    WordSoFar += s[j];

    if(dictionary.find(WordSoFar) == dictionary.end())
    {
      continue;
    }

    subproblem = MemoizedCode(j+1 , length , s , dictionary , dp);

    for(int i = 0 ; i<subproblem.size(); i++)
    {
      if(subproblem[i].size() > 0)
        subproblem[i] =  WordSoFar + " " + subproblem[i];

      else
        subproblem[i] = WordSoFar + "" + subproblem[i];
    }

    for(auto &s : subproblem)
    {
      completePack.push_back(s);
    }

    // WordSoFar.pop_back();   // for new elements to come in
  }

  return dp[ind] = completePack;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    int length = s.length();
    unordered_map<string,bool> dict;
    int n = dictionary.size();

    for(int i=0;i<n;i++)
    {
        dict[dictionary[i]]++;
    }

    // return allValidSent(0 ,length ,s , dict); // normal Recursion

    unordered_map<int ,vector<string>>dp;

    return MemoizedCode(0 , length , s , dict , dp); // memoized code

}

int main()
{
  string s = "godisnowherenowhere";
  vector<string>givenDict  =  {"god","is","now","no","where","here"};
  vector<string> ans = wordBreak(s , givenDict);

  for(auto &it: ans)
  {
    cout<<it<<endl;
  }

  return 0;
}

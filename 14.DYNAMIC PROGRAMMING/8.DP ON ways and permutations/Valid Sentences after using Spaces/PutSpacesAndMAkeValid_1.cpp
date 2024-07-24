
#include<bits/stdc++.h>
#include<string>
using namespace std;

void frec( int ind,int end,vector<string>temp ,vector<vector<string>>&ans, string&s,string soFar,string empty, unordered_map<string,bool> &dictionary)
{
    soFar += s[ind];  // adding current jth element to the soFar

    //base case
    if(ind == end && dictionary[soFar] == true)
    {
      temp.push_back(soFar);
      ans.push_back(temp);
      return;
    }

    if(ind == end && dictionary[soFar] == false)
    {
      return;
    }

    // if string till now is a proper word , then you have two choices
    // ---- make space here
    if(dictionary[soFar] == true) // means string created is a word
    {
      temp.push_back(soFar); // adding it in temp
      frec(ind+1 , end , temp, ans , s ,empty, empty, dictionary);
      temp.pop_back(); // removing it , so that without putting space here
      //we can search further
    }
    //---- age dekenge space
    frec(ind+1 , end ,temp , ans , s , soFar ,empty, dictionary );
}

vector<vector<string>> getAll(string &s, vector<string> &dict)
{
    // searching in a vector will take O(n) everytime
    // So to avoid it , we will make a unordered_map
    unordered_map<string,bool> dictionary;
    int n = dict.size();

    //u should use trie DS , for this , bcoz it will help u to
    // identify whether , we have to take space here ,
    // or we can go further , bcoz string created till now is a part
    // another word as well

    for(int i=0;i<n;i++)
    {
        dictionary[dict[i]] = true;
    }// dictionary map created


    string soFar = "";
    string empty = "";

    int end = s.length()-1;
    int ind = 0;

    // int ans = frec(ind  , end , s ,soFar,  empty , dictionary);  NOrmal Recursion

    int size = s.size();
    vector<vector<int>>dp( size , vector<int>(size , -1));
    vector<vector<string>>ans;
    vector<string> temp;
    frec(ind  , end ,temp , ans, s ,soFar,  empty , dictionary);
    return ans;
}

vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
   vector<vector<string>> ans = getAll(s , dict);

   vector<string>arr;


for(auto &it: ans)
  {
    string temp ="";
    for(auto i:it)
    {
      temp +=i;
      temp+= " ";
    }
    arr.push_back(temp);
  }

  return arr;
}



int main()
{
  string s = "godisnowherenowhere";
  vector<string>dict  =  {"god","is","now","no","where","here"};

  vector<string> ans = getAllValidSentences(s , dict);
  for(auto &it: ans)
    cout<<it<<endl;

  return 0;
}

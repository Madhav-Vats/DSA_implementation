// if given dictionary , and a string with no spaces ,
//find the number of valid sentences that can be formed , from it , if you can give
//spaces anywhere in the string s , return all possible valid sentence

//    WORD BREAK ( counting the total number of valid Sentences possible)

#include<bits/stdc++.h>
#include<string>
using namespace std;

int frec( int ind  , int end , string&s , string soFar, string empty ,  unordered_map<string , bool> &dictionary)
{
    soFar += s[ind];  // adding current jth element to the soFar

    //base case
    if(ind == end && dictionary[soFar] == true)
    {
      return 1;
    }

    if(ind == end && dictionary[soFar] == false)
    {
      return 0;
    }

    // if string till now is a proper word , then you have two choices
    int yhiSpaceDaal = 0;

    if(dictionary[soFar] == true) // means string created is a word
      yhiSpaceDaal = frec(ind+1 , end , s ,empty, empty, dictionary);

    int aageDekhtehai = frec(ind+1 , end , s , soFar ,empty, dictionary );

    return  yhiSpaceDaal + aageDekhtehai;
}


// the way u have been solving things
int frec2(int ind , string soFar , string &s , int size ,unordered_map<string,bool>&dictionary)
{
    if(ind  == size && dictionary[soFar] == true)
        return 1;
    if(ind == size)
        return 0;

    soFar += s[ind];

    int yhiSpaceDaal = 0;

    if(dictionary[soFar]  == true)
    {
        yhiSpaceDaal = frec2(ind+1 , "" , s , size , dictionary);
    }

    //agge daalenge space
    int aageDekhenge  =  frec2(ind+1 , soFar , s ,  size , dictionary);

    return aageDekhenge + yhiSpaceDaal;

}


// ---------------------- MEMOIZED ------------------------------------

int fmemo( int ind  , int end , string&s , string soFar, string empty ,  unordered_map<string , bool> &dictionary , vector<vector<int>>&dp)
{
    soFar += s[ind];  // adding current jth element to the soFar

    //base case
    if(ind == end && dictionary[soFar] == true)
    {
      return 1;
    }

    if(ind == end && dictionary[soFar] == false)
    {
      return 0;
    }

    if(dp[ind][soFar.length()]!= -1)
      return dp[ind][soFar.length()];


    // if string till now is a proper word , then you have two choices
    int yhiSpaceDaal = 0;

    if(dictionary[soFar] == true) // means string created is a word
      yhiSpaceDaal = fmemo(ind+1 , end , s ,empty, empty, dictionary , dp);

    int aageDekhtehai = fmemo(ind+1 , end , s , soFar ,empty, dictionary , dp);

    return dp[ind][soFar.length()] = yhiSpaceDaal + aageDekhtehai;
}


//-------------------- function than calls Recursive functions ------------
int getAllValidSentences(string &s, vector<string> &dict)
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
    int ans = fmemo(ind  , end , s ,soFar,  empty , dictionary , dp);
    return ans;
}

int main()
{
  string s = "godisnowherenowhere";
  vector<string>dict  =  {"god","is","now","no","where","here"};
  int ans = getAllValidSentences(s , dict);
  cout<<ans;
  return 0;
}

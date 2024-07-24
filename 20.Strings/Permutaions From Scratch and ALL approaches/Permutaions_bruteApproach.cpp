#include<bits/stdc++.h>
#include<string>
using namespace std;

//---------------------------------------------------------------------------------
//-------------------             NOT WORKING          ----------------------------
//---------------------------------------------------------------------------------

void printArray(vector<string>&arr)
{
  for(auto&it:arr)
  {
    cout<<it<<endl;
  }
}

void permutations( int ind , int length ,string s, unordered_map<char , int>&freq , set<string>&st)
{
  //base case
  if(ind == length)
  {
    st.insert(s);
    return;
  }


  for(auto &pair: freq)
  {
    char currElement = pair.first;

    s += currElement;

    // if this element is used then for next recursive call
    // we need to decreace its count , ( reduce its availablity)
    freq[currElement]--;
    if(freq[currElement] == 0)
      freq.erase(currElement);

    permutations( ind+1 , length , s , freq , st);


    // Backtracking
    // putting that removed element back to the freq map
    //and returning the original string s , for next iteration
    freq[currElement]++;
    s.pop_back();
  }

}

int main()
{
  string s = "madhav";
  int length = s.length();
  unordered_map<char , int>freq;

  for(int i=0 ;i<length;i++)
  {
    freq[s[i]]++;
  }

  set<string>st;
  string temp = "";
  permutations(0 , length ,temp , freq , st);


  vector<string>ans;

  for(auto &it:st)
  {
    // ans.push_back(it);
    cout<<it;
  }

  for(auto&it:ans)
  {
    cout<<it<<endl;
  }

}

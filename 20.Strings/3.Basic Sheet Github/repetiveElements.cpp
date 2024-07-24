/*

Given a string, check if a repeated subsequence is present in it or not. The repeated subsequence should have a length of 2 or more.

Input: "XYBAXB"
Output: true
Explanation: String "XYBAXB" has XB(XBXB) as a repeated subsequence

Input: "XBXAXB"
Output: true
Explanation: String "XBXAXB" has XX(XXX) as a repeated subsequence

Input: "XYBYAXBY"
Output: true
Explanation: String "XYBYAXBY" has XB(XBXB), XY(XYXY), YY(YYY), YB(YBYB), and YBY(YBYBY) as repeated subsequences.

Input: "ABCA"
Output: false
Explanation: String "ABCA" doesn’t have any repeated subsequence

*/


#include<bits/stdc++.h>
#include<string>
using namespace std;


bool isPalindrome(string temp)
{
  int i = 0;
  int j = temp.length()-1;

  while(i<j)
  {
    if(temp[i] == temp[j])
    {
      i++;
      j--;
    }
    else
      return false;
  }

  return true;
}

bool hasRepeatedSubsequence(string s)
{
  int len = s.length();

  //the key is
  //if the  s consist of palindrome we should remove it
  // bcoz it doesnt consist of repeated elements
  //until or unless the count of any element is the palindrome
  // is greater than 2

  unordered_map<int,int>freq;
  for(int i=0;i<len;i++)
  {
    freq[s[i]]++;
  }


  for(auto &it: freq)
  {
    if(it.second >2)
    {
      return true;
    }
  }


  // now we know that in our string there is no element
  //having a count greater than 2
  // bcoz if those cases have already give TRUE answer

  //now for repetetive elements , means, we dont need the
  // char having count = 1;

  //making a temp string that stores a string having all elements
  //count >=2

  string temp ="";

  for (int i = 0; i < s.length(); i++)
     {
         if (freq[s[i]] >= 2) {
             temp += s[i];
         }
     }

  //now if this temp is a palindrome then
  // we cant have repetetive elements in the whole string

  if(isPalindrome(temp) == true)
    return false;

  return true;

}


int main()
{
  string s;
  cin>>s;

  int n = s.length();

    bool ans = hasRepeatedSubsequence(s);
    cout<<ans<<endl;
}

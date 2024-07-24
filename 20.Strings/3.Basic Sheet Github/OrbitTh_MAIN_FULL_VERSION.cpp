#include<bits/stdc++.h>
#include<string>
using namespace std;

string palindSubstr(string &s , int low , int high)
{
  //expanding the orbital
  while(low>=0 && high<s.length() &&(s[low] == s[high]))
  {
    low--;
    high++;
  }

  //bcoz we are consider the the case of even length
  // if we would have givien the main condn inside the boundary
  // then it will always remain true and infinite loop


  //the palind substring actually starts from low +1
  int len = high-low-1;

  return s.substr(low+1 , len);
}


string maxLenPalind(string &s , int n)
{
  string currAnsString ="";
  int currLen = 0;

  int maxLen =  0;
  string maxString = "";


  for(int i= 0 ;i<n;i++)
  {
    //finding the maxLen of odd size palindrome
    currAnsString = palindSubstr(s , i , i);
    currLen = currAnsString.length();

    if(currLen > maxLen)
    {
      maxLen = currLen;
      maxString = currAnsString;
    }

    //finding the maxLen of even size palindrome
    currAnsString = palindSubstr(s , i , i+1);
    currLen = currAnsString.length();

    if(currLen > maxLen)
    {
      maxLen = currLen;
      maxString = currAnsString;
    }
  }

  return maxString;
}


int main()
{
  string s = "abdcb";

  int n = s.length();

  string ans = maxLenPalind(s , n);
  cout<<ans;
}

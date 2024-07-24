#include<bits/stdc++.h>
#include<string>
using namespace std;

bool isPalindrome(string &s ,int start , int end)
{
  int i =start;
  int j = end;

  while(i<j)
  {
    if(s[i]==s[j])
    {
      i++;
      j--;
    }
    else
      return false;
  }

  return true;
}

bool nlenPalindrome(string &s2 , int n)
{
  int len = 2*n;
  //we can use sliding window problem

  //checking first window

  for(int i=0 ; i<n;i++) // number of sliding windows
  {
    if(isPalindrome(s2 , i , i+n-1))
      return true;
  }

  return false;
}

bool checkRotatedPalind(string &s)
{
  int n = s.length();

  //concatinating the same strings nd then searching for palindrome
  //of length n

  string s2 = s+s;

  return nlenPalindrome(s2 , n);
}



int main()
{
  string s = "BDAABCC";

  bool ans = checkRotatedPalind(s);
  cout<<ans;

  return 0;
}

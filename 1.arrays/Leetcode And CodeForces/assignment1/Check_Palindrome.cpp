#include <bits/stdc++.h>
using namespace std;

bool checkPalind(string &s , int length)
{
  int i =0;
  int j =length-1;

  while(i<j)
  {
    if(s[i] == s[j])
    {
      i++;
      j--;
    }
    else
      return false;
  }

  return true;
}

bool checkRecursively(string &s , int start , int end)
{
  if(start>=end)
    return true;

  if(s[start] != s[end])
    return false;

  bool ans = false;
  ans = checkRecursively(s , start+1 , end-1);

  return ans;
}

int main()
{
  string s;
  cin>>s;

  int length = s.length();


  //Approach 1
  bool ans1 = checkPalind(s , length);
  cout<<ans1<<endl;

  bool ans2 = checkRecursively( s , 0  , length-1);



}

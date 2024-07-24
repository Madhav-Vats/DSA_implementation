#include<bits/stdc++.h>
using namespace std;



void swap( char &a , char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void permutations(int l , int r ,  string &s , set<string>&ans)
{
    //base case
    if(l == r)
    {
        ans.insert(s);
        return;
    }

    //swapping the ith element will all possible

    for(int i=l;i<=r;i++)
    {
       // if(s[i] == s[l]) // dont swap if you find the same element
       //     continue;

        swap(s[l] , s[i]);

        //do this whole process for substring starting from l+1
        permutations(l+1 , r , s, ans);

        // while coming back , make sure that you return the original string
        //for next iteration processing

        swap(s[l] , s[i]);
    }
}

vector<string>find_permutation(string S)
{
  //base case
  int length = S.length();
  set<string>ans ;

  permutations(0 , length-1 , S  ,ans );

  vector<string>arr; // for handling the duplicate permutations

  for(auto &it: ans)
  {
      arr.push_back(it);
  }
  return arr;

}


int main()
{
  return 0;
}

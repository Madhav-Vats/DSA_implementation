#include <bits/stdc++.h>
using namespace std;

// int findNums(int l  , int r)
// {
//
// }

int firstii(int a)
{

  while(a/10 != 0)
  {
    a = a/10;
  }

  return a;

}

void nums(int l , int r)
{
  //find the first element of the l element
  int a = firstii(l);

  for(int i=l;i<=r;i++)
  {
    int b = i%10;
    cout<<"first - "<<a<<"second - "<<b<<endl;
  }
}


int main()
{
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    #endif
  }

  int l , r;
  cin>>l>>r;

  // nums(l ,r);

  int ans = firstii(0);
  cout<<ans;


  // int ans = findNums(l , r);
  // cout<<ans<<endl;
}

// leaders in an array

#include <bits/stdc++.h>
using namespace std;


int main()
{
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

vector<int> a={10, 22, 12, 3 ,0,6};
vector<int> ans= leaders(a);
for(auto it: ans)
{
  cout<<it<<endl;
}
return 0;
}

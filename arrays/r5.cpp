//arrange elements on the basis of thir signs
#include <bits/stdc++.h>
using namespace std;

#define push_back push_back
void sign_arranged_array(vector<int> &arr)
{
  vector<int> pos;
  vector<int> neg;
  vector<int> ans;
  int n=arr.size();
  for(int i=0;i<n;i++)
  {
    if(arr[i]>=0)
    {
      pos.push_back(arr[i]);
    }
    if(arr[i]<0)
    {
      neg.push_back(arr[i]);

    }

  }

int j=1;
int k=0;
  for(int i=0;i<n/2;i+=2)
  {
    ans[j]=neg[k];
    ans[i]=pos[k];
    j+=2;
    k++;
  }

  for(auto it: ans)
  {
    cout<<it<<endl;
  }

  cout<<"pos"<<endl;
  for(auto it: pos)
  {
    cout<<it<<endl;
  }
}


int main()
{
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//
//   #ifndef ONLINE_JUDGE
//   //freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
//   #endif
// }

vector<int> a={3,1,-2,-5,2,-4};
sign_arranged_array(a);

return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Disjoint_set{

public:

  // data members
  vector<int> parent , size;

  Disjoint_set(int n )
  {
    parent.resize(n+1);
    size.resize(n+1);

    for(int i=0;i<=n;i++)
    {
      size[i]=1;
      parent[i]=i;
    }
  }

  int findUrParent(int node)
  {
    if(node == parent[node])
      return node;               // kind of like a base condition

    return parent[node] = findUrParent(parent[node]);
  }

  void unionBySize(int u , int v)
  {

    int ult_u = findUrParent(u);
    int ult_v = findUrParent(v);

    if(ult_u == ult_v)
      return;

    if( size[ult_u] > size[ult_v] )
    {
      parent[ult_v] = ult_u;
      size[ult_u] += size[ult_v];
    }

    else
    {
      parent[ult_u] = ult_v;
      size[ult_v] += size[ult_u];
    }
  }


};


int main()
{
  int n , p;
  cin>>n>>p;

  //dependency
  vector<int>degree(n+1 ,0);

  Disjoint_set dsu(n);

  for(int i=0;i<p;i++)
  {
    int a,b;
    cin>>a>>b;

    degree[a]++;
    degree[b]++;
    dsu.unionBySize(a , b);
  }

  //every element should have a degree == parentSize-1

  bool flag = true;

  for(int i=1;i<=n;i++)
  {
    int pSize = dsu.size[dsu.findUrParent(i)];

    if(degree[i] != pSize-1)
    {
      flag = false;
      break;
    }
  }

  if(flag)
    cout<<"YES";
  else
    cout<<"NO";

}

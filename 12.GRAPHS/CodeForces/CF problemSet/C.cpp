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
  int n , g;
  cin>>n>>g;

  unordered_map<int,list<int>>adjList;

  Disjoint_set dsu(n);
  for(int i=0;i<g;i++)
  {
    int a;
    cin>>a;

    int first;

    if(a!= 0)
    {
      int f;
      cin>>f;
      first = f;
      a--;
    }

    while(a--)
    {
      int p;
      cin>>p;

      dsu.unionBySize(first , p);
    }
  }

  for(int i=1;i<=n;i++)
  {
    cout<<dsu.size[dsu.findUrParent(i)]<<" ";
  }


  //Dsu initialization


}

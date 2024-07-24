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
    int n,m;
    cin>>n>>m;
    Disjoint_set ds(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        ds.unionBySize(u,v);
    }

    //we are going to traverse the size array 
    // we will take 1 as the refernce
    // and if any others ult_parent != ultParent(1)
    // we need to build a road there 
    // we will do the union also 

    int reference = 1;

    vector<pair<int,int>>newRoads;
    int cnt = 0;

    for(int i=2;i<=n;i++)
    {
        if(ds.findUrParent(i)!= ds.findUrParent(reference))
        {
            ds.unionBySize(i,reference);
            cnt++;
            newRoads.push_back({reference,i});
        }
    }

    cout<<cnt<<endl;
    for(auto &p: newRoads)
        cout<<p.first<<" "<<p.second<<endl;
}
#include <bits/stdc++.h>
using namespace std;


using ll = long long;
class Disjoll_set{

public:

  // data members
  vector<ll> parent , size;

  Disjoll_set(ll n )
  {
    parent.resize(n+1);
    size.resize(n+1);

    for(ll i=0;i<=n;i++)
    {
      size[i]=1;
      parent[i]=i;
    }
  }

  ll findUrParent(ll node)
  {
    if(node == parent[node])
      return node;               // kind of like a base condition

    return parent[node] = findUrParent(parent[node]);
  }

  void unionBySize(ll u , ll v)
  {

    ll ult_u = findUrParent(u);
    ll ult_v = findUrParent(v);

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



ll minSpanningTreeKruskal(ll n ,vector<vector<ll>> &edges)  // to get the MST graph itselt
{
    //sort edges on basis of weight 
    sort(edges.begin() , edges.end()  ,[](auto &a , auto &b)
    {
        return a[2] < b[2];
    });

    Disjoll_set dsu(n);

    ll ans = 0;

    for(auto it: edges)
    {
        ll u = it[0];
        ll v = it[1];
        ll weight = it[2];

        ll pU = dsu.findUrParent(u);
        ll pV = dsu.findUrParent(v);

        if(pU == pV)
            continue;
        else
        {
            dsu.unionBySize(u , v);
            ans += weight;
        }
    }

    return ans;
}


vector<pair<ll,ll>>NodeCost;

int main() {
    ll n, m;
    cin >> n >> m;


    for(ll i=0;i<n;i++)
    {
        ll val;
        cin>>val;
        NodeCost.push_back({val , i});
    }

    vector<vector<ll>>allEdges;

    for(ll i=0;i<m;i++)
    {
        ll a , b, w;
        cin>>a>>b>>w;
        a--;
        b--;
        allEdges.push_back({a ,b, w});
    }


    //from the lowest NodeCost Node to all the nodes 
    sort(NodeCost.begin(), NodeCost.end());

    ll firstPrice = NodeCost[0].first;
    ll firstNode = NodeCost[0].second;




    for(auto it: NodeCost)
    {
        ll curr = it.second;
        ll cost = it.first;

        if(curr != firstNode)
        {
            allEdges.push_back({firstNode ,curr , cost + firstPrice});
        }
    }


    ll ans = 0;

    ans = minSpanningTreeKruskal(n ,allEdges);

    cout<<ans<<endl;
    return 0;
}


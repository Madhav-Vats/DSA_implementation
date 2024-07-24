#include <bits/stdc++.h>
using namespace std;


// --  u must give some time to think about its intution and what and why we will use any approach 
// before reading the below text

//its basically saying the path cost = max(edge weigth in the path)
// and we have some special nodes , and we want to find the maximum path cost special node
// for all the nodes

//the graph is totally connected 
// so we want to trim the graph

// --given = Let's define the cost of the path as the maximum weight of the edges in it. 
//And the distance between two vertexes as the minimum cost of the paths connecting them.

//--For each special vertex, find another special vertex which is farthest from it 
//(in terms of the previous paragraph, i.e. the corresponding distance is maximum possible)
//and output the distance between them.

// so this basically means btw two nodes we need the minimum distance , 
// and for all special nodes we need to find another special node , having a maximum value of (distance btw them)
// and distance is the minimum cost btw two node , and cost  = max edge weigth in btw the path 

// so its like at the end we will only be focussing on the dist btw two nodes 
// so if we have multiple path btw two nodes , we must choose only the path having minimum distance 
// so why not to trim the graph with those values only 
// and then at the end we will go from the curr special node to all , and will find the max edge weight
// which takes us to a special node

// did u realize that if we find the maximum one time , this distance is the answer for all other special nodes 




// so at the end = Build MST , and then do the DFS in that MST , to find that one answer (maximum one ) btw two sp nodes 
// and this answer will be the anser for all others as well 

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

using ll = long long;

unordered_map<ll,list<pair<ll,ll>>> solve(ll n ,vector<vector<ll>> &edges)  // to get the MST graph itselt
{
    unordered_map<ll,list<pair<ll,ll>>>adjList;

    //sort edges on basis of weight 
    sort(edges.begin() , edges.end()  ,[](auto &a , auto &b)
    {
        return a[2] < b[2];
    });

    Disjoint_set dsu(n);

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

            pair<ll ,ll>aa = make_pair(u ,weight);
            pair<ll,ll>bb = make_pair(v ,weight);

            //add edge btw them in the adjList
            adjList[u].push_back(bb);
            adjList[v].push_back(aa);
        }
    }

    return adjList;
}

vector<bool>visited;
unordered_map<ll,bool>special;

void dfs(ll src, unordered_map<ll, list<pair<ll, ll>>>& adjList, ll& endAns, ll currMax) {
    visited[src] = true;

    if (special.find(src) != special.end()) {
        endAns = max(endAns, currMax);
    }

    for (auto& nbr : adjList[src]) {
        if (!visited[nbr.first]) {
            ll newMax = max(currMax, nbr.second);
            dfs(nbr.first, adjList, endAns, newMax);
        }
    }
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll anySpecialNode;
    special.clear();

    for (int i = 0; i < k; i++) {
        ll el;
        cin >> el;
        anySpecialNode = el;
        special[el] = true;
    }

    vector<vector<ll>> edges(m);

    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    unordered_map<ll, list<pair<ll, ll>>> adjList = solve(n, edges);

    ll ans = 0;
    visited.assign(n + 1, false);

    ll curr = 0;
    dfs(anySpecialNode, adjList, ans, curr);

    for (int i = 0; i < k; i++) {
        cout << ans << " ";
    }

    return 0;
}


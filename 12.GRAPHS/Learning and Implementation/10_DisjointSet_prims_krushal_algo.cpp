#include <bits/stdc++.h>
using namespace std;
#include<list>
#include<unordered_map>

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






// disjoint set data structure
class DisjointSet{
public:
  // Data member
  vector<int> size , parent;
  // constructor
  DisjointSet(int n)
  {
    size.resize(n+1) ;
    // this will handle both kid of graph , 0 based as wel as 1 based
    parent.resize(n+1);

    for(int i=0; i<=n ;i++)
    {
      size[i]=1; // initial size = 1
      parent[i]=i; // parent itself
    }
  }

  // member functions
  int findUrParent(int node)
  {
    if(node == parent[node])
      return node;

    return parent[node] = findUrParent(parent[node]);
  }

  void unionBySize ( int u , int v)
  {
    int ultParent_u = findUrParent(u);
    int ultParent_v = findUrParent(v);

    if(ultParent_u == ultParent_v) // same parent
      return;

    // size of their ultimate parent decides the union
    if(size[ultParent_u] > size[ultParent_v])
    {
      // making the bigger one as the parent of smaller
      parent[ultParent_v] = ultParent_u ;

      // increasing  the size of the bigger one
      size[ultParent_u] += size[ultParent_v];
    }
    // this else handles both the cases , when they are equal
    // when the size[upltParent_v] > size[upltParent_u]
    else
    {
      parent[ultParent_u] = ultParent_v;
      size[ultParent_v] += size[ultParent_u];
    }
  }

};



//using integer graph
class graph{
public:
  unordered_map<int,list<pair<int,int>>> adjList;
  // tis map will handle both type of graphs
  // if undirected , make each weight as 1

  void addedge(int u, int v, int weight, bool directed)
  {

    pair<int,int> p = make_pair(v ,weight);
    adjList[u].push_back(p);

    //if not directed both edge should be added on both side elements
    if(!directed)
    {
      pair<int,int> p2 = make_pair(u ,weight);
      adjList[v].push_back(p2);
    }
    // no need to write for directed , bcoz its already been handled
  }

  void printadjList()
  {
    for(auto node : adjList)
    {
      cout<<node.first<<" --> ";
      for(auto neighbour: node.second)
      {
        cout<<"("<<neighbour.first<<","<<neighbour.second<<") ";
      }
      cout<<endl;
    }
  }

};


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





// cost of minimum spanning tree

int spanningTree_kruskals( int V , unordered_map<int,list<pair<int,int>>> &adjList)
{
  // creation of container of edges weight
  priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> edges_pq;

 // creation of edge_pq
  for(auto &it :adjList){
    for(auto nbr : it.second){

      int u = it.first;
      int v = nbr.first;
      int wt = nbr.second;

      edges_pq.push({wt , {u , v}});
    }
  }
  // min_cost
  int min_cost = 0;

  // disjoint set
  DisjointSet ds(V);

  // we are going to take only V-1 edges
  int e = 0;
  while(!edges_pq.empty() &&  e < V-1 )
  {
   auto current = edges_pq.top();

   int wt = current.first;
   int u = current.second.first;
   int v = current.second.second;

   edges_pq.pop();

   // this condition must stay // other wise cylce formation
   if(ds.findUrParent(u)  != ds.findUrParent(v))
   {
     // then use this edge in the formation of of our spanning Tree
     min_cost += wt;
     // make their union in the disjoint set
     ds.unionBySize( u , v);
     // increase the counter of edges includes
     e++;
    }
  }
  return min_cost;
}


int spanningTree_prims( int src , int V , unordered_map<int,list<pair<int,int>>> &adjList  , vector<vector<int>> &MST)
{
  // priority queue for edges
  priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq;

  // making of visited vector
  vector<bool> visited(5,false);
  // min_cost
  int min_cost = 0;
  //insert first element in the pq
  // as the source could be zero or could be 1
  pq.push({ 0 , { src , -1 }});

  while(!pq.empty())
  {
    auto current = pq.top();
    int wt = current.first;
    int u = current.second.first;   // node
    int v = current.second.second;  // here v is the parent2

    pq.pop();

  // we going going to take only V-1 edges
    // if an edge was already visited then skip it and its neighbours
    // this condition will never let the edges to be more than V-1
    if(visited[u] == true)
      continue;

    // if it wasn't visited then use its edge weight and this edge
    min_cost += wt;
    // adding this edge to ans
    if(v!= -1) // initial parent should be avoided
    {
      vector<int> temp;
      temp.push_back(u);
      temp.push_back(v);
      MST.push_back(temp);
    }

    visited[u] = true; // marking this node as visited

    for(auto nbr: adjList[u])
    {
      if(!visited[nbr.first])
      {
        pq.push({nbr.second , {nbr.first , u}});
      }
    }
  }
  return min_cost;
}



int main()
{
  graph g2;
  int v = 7;
  DisjointSet ds(v);

  g2.addedge(0,3,3,0);
  g2.addedge(1,3,5,0);
  g2.addedge(0,4,12,0);
  g2.addedge(4,2,7,0);
  g2.addedge(2,1,2,0);
  g2.addedge(3,2,3,0);


  unordered_map<int,list<pair<int,int>>> adjList = g2.adjList;


  vector<vector<int>> ans;
  int prims_ans = spanningTree_prims(0 , 5 , adjList , ans);
  cout<<endl<<prims_ans;
  cout<<endl;

  // printing the spanning tree
  for(auto it: ans)
  {
    cout<<"(";

    for(auto i : it)
      cout<<i<<" ";

    cout<<")"<<" ";
  }
  return 0;
}

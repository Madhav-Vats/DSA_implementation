#include <bits/stdc++.h>
using namespace std;
#include<list>
# include<unordered_map>

template <typename T>

//using the  template
class graph_temp{
public:
  unordered_map<T,list<pair<T,int>>> adjList;
  // tis map will handle both type of graphs
  // if undirected , make each weight as 1

  void addedge(T u, T v, int weight, bool directed)
  {

    pair<T,int> p = make_pair(v ,weight);
    adjList[u].push_back(p);

    //if not directed both edge should be added on both side elements
    if(!directed)
    {
      pair<T,int> p2 = make_pair(u ,weight);
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
// using int only
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


int main()
{
  graph g;

// for integer graph
  g.addedge(0,1,1,0);
  g.addedge(1,2,1,0);
  g.addedge(1,3,1,0);
  g.addedge(3,5,1,0);
  g.addedge(3,7,1,0);
  g.addedge(7,6,1,0);
  g.addedge(7,4,1,0);


  g.printadjList();
  cout<<endl<<"it's time for char graph"<<endl;

// for graph using template
  graph_temp<char> g2;
  g2.addedge('a','b',1,0);
  g2.addedge('b','c',1,0);
  g2.addedge('b','d',1,0);
  g2.addedge('d','f',1,0);
  g2.addedge('d','h',1,0);
  g2.addedge('h','g',1,0);
  g2.addedge('h','e',1,0);

  g2.printadjList();



}

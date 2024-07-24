//Handling case of disjoint graph , and DFS implementation
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

// src = source
  void bfs(T src , unordered_map<T, bool> & visited) // or you could have written ( int src)
  {

    queue<T> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
      T frontNode = q.front();
      q.pop();

      cout<<frontNode<<" ";
      // nbr or neighbour
      for(auto nbr: adjList[frontNode])
      {
        if(!visited[nbr.first])
        {
          q.push(nbr.first);
          visited[nbr.first]=true;
        }
      }
    }
  }


  void dfs(T src, unordered_map<T, bool> & visited)
  {
    visited[src]= true;
    cout<<src<<",";
    // there is no base case in it ,bcoz the time when
    //there is no neighbour of the src , then the recursion stack will return
    // and automatically it will end
    for(auto nbr : adjList[src])
    {
      if(!visited[nbr.first])
        dfs(nbr.first , visited);
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

  void bfs(int src , unordered_map<int, bool> & visited) // or you could have written ( int src)
  {

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
      int frontNode = q.front();
      q.pop();

      cout<<frontNode<<" ";
      // nbr or neighbour
      for(auto nbr: adjList[frontNode])
      {
        if(!visited[nbr.first])
        {
          q.push(nbr.first);
          visited[nbr.first]=true;
        }
      }
    }
  }

  void dfs(int src, unordered_map<int, bool> & visited)
  {
    visited[src]= true;
    cout<<src<<",";
    // there is no base case in it ,bcoz the time when
    //there is no neighbour of the src , then the recursion stack will return
    // and automatically it will end
    for(auto nbr : adjList[src])
    {
      if(!visited[nbr.first])
        dfs(nbr.first , visited);
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


  // g.bfs(0);
  // cout<<endl;
  // g2.bfs('a');


// Handling case of disjoint graph

  // get the value of the number of nodes(n)
  // create a visited map extensively and pass it to the functions and class

// WORK ONLY WHEN YOU KNOW THE ALL THE ELEMENTS
// AND WHEN THEY ARE IN AN ORDER FROM 0 TO N
  unordered_map <int,bool> visited;
  cout<<endl<<"time for bfs "<<endl;

  // IN THIS CASE ALL THE  ELEMENTS LIES BTW 0 TO 7
  for(int i=0;i<=7;i++)
  {
    if(!visited[i])
      g.bfs(i , visited);
  }


  cout<<endl<<"time for dfs "<<endl;
// DFS for integer graph
  unordered_map <int,bool> visited2;
  for(int i=0;i<=7;i++)
  {
    if(!visited2[i])
      g.dfs(i , visited2);
  }

cout<<endl<<char('a'+char(2));


// case of character graph g2
  unordered_map <char,bool> visited3;

  // for(int i=0;i<=7;++i)
  // {
  //   if(!visited3['a'+i])
  //     g2.bfs(i , visited3);
  // }

  g2.bfs(0 , visited3);

return 0;

return 0;
}

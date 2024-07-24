#include <bits/stdc++.h>
using namespace std;
#include<list>
# include<unordered_map>


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


  // undirected cyclic , using BFS
  bool cycle_detection_undir_bfs(int src , int &parent, unordered_map<int, bool> & visited)
  {
    // if a node is already visited and
    //its is not the parent and its a neighbour , then cycle is present
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
      int current  = q.front();
      q.pop();

      for(auto nbr: adjList[current])
      {

        if(!visited[nbr.first])
        {
          // pushing the non visited neighbours into queue
          q.push(nbr.first);
          // marking them as visited
          visited[nbr.first] = true ;
          // changing the parent for these new node
          parent = current;
        }
        else if( visited[nbr.first] && nbr.first!= parent)
          return true;
      }
    }

    return false;
  }

  bool cycle_detection_dir_dfs(int src , int &parent ,unordered_map<int,bool> df_visited ,  unordered_map<int, bool> & visited)
  {

    // unordered_map<int,bool> df_visited;
    // recursive stack storage , passed by value , therefore no permanent updation

    visited[src]=true;

    for(auto nbr : adjList[src])
    {
      if(!visited[nbr.first])
      {
        bool aage_ke_calls = cycle_detection_dir_dfs(nbr.first , src ,df_visited , visited);
      }

      else if(visited[nbr.first] && df_visited[nbr.first] && nbr.first != parent)
        return true;

    }


    return false;
  }
};


int main()
{
  graph g;

// undirected cyclic using bfs
  g.addedge(0,1,1,0);
  g.addedge(1,5,1,0);
  g.addedge(1,3,1,0);
  g.addedge(3,5,1,0);
  g.addedge(3,7,1,0);
  g.addedge(7,6,1,0);
  g.addedge(7,4,1,0);

  g.printadjList();
  cout<<endl<<"it's time for char graph"<<endl;

  unordered_map<int,bool>visited;

  int parent = -1 ;
  bool ans = g.cycle_detection_undir_bfs(0 ,parent, visited);


// directed CYCLIC using dfs
  graph g2;

  g2.addedge(0,1,1,1);
  g2.addedge(1,5,1,1);
  g2.addedge(1,6,1,1);
  g2.addedge(6,5,1,1);
  g2.addedge(1,2,1,1);
  g2.addedge(2,3,1,1);
  g2.addedge(3,4,1,1);
  g2.addedge(3,7,1,1);
  g2.addedge(7,8,1,1);
  g2.addedge(8,3,1,1);

  g2.printadjList();
  int parent2 =-1;

  unordered_map<int,bool>visited2;
  unordered_map<int,bool>dfs_visited2;
  bool ans2 = g2.cycle_detection_dir_dfs(0,parent2 ,dfs_visited2 ,visited2);
  cout<<ans<<" ";
  cout<<parent;
  return 0;






}

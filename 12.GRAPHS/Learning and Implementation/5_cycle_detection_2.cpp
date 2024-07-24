#include <bits/stdc++.h>
using namespace std;
#include<list>
#include<unordered_map>


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
        // bool aage_ke_calls = cycle_detection_dir_dfs(nbr.first , src ,df_visited , visited);
      }

      else if(visited[nbr.first] && df_visited[nbr.first] && nbr.first != parent)
        return true;

    }


    return false;
  }

  //---------------------------------------------------------------------------------------------------------------------------
 // THE TOPO ORDER IS NOT A UNIQUE ORDER , IT JUST MAINTAINS , THAT THE PARENT(ON WHICH IT DEPENDS) OF A NODE COMES BEFORE IT
  void dfs_topo(int src , unordered_map<int,bool> & visited , stack<int> &st)
  {
    visited[src] = true;


    for(auto nbr: adjList[src])
    {
      if(!visited[nbr.first])
      {
        dfs_topo(nbr.first , visited , st);
      }
    }

    // while returning , store the node in stack
    st.push(src);
    cout << "Pushed " << src << " onto stack\n"; // Debug statement

  }

  void topo_sortDFS(unordered_map<int,bool> &visited)
  {

    stack<int>st;
    int n = adjList.size();
    // where n is the number of vertices , starting from 0
    for(int i=0;i<n;i++)
    {
      if(!visited[i])
        dfs_topo(i,visited , st);
    }


    while(!st.empty())
    {
      cout<<st.top()<<" ";
      st.pop();
    }
  }


  // ON THE BASIS OF DEPENDECY ( IN DEGREE )
  void KAHNS_Algo_topoSort(int n )
  {
    // making of indegree map
    unordered_map<int,int> indegree;

    queue<int> q;


    // traversing the adjList for creation of indegree map
    for(auto it: adjList)
    {
      int src = it.first;
      for(auto nbrs : it.second)   // 1 -> {(2,1),(3,1)}   (vertices , weight_of_edge)
      {
        indegree[nbrs.first]++;
      }

    }

    // pushing those vertices , whose indegree was initially zero
    for(int i=0;i<n;i++)
    {
      if(indegree[i]==0)
      q.push(i);
    }

    // on the basis of elements of the queue , printing them and making their
    // neighbours indegree = indegree -1
    // while removing them from the queue
    // and pusing the nbr , whose indegree becomes = 0

    while(!q.empty())
    {
      int current = q.front();
      q.pop();

      cout<<current<<" ";

      for(auto nbr : adjList[current])
      {
        indegree[nbr.first] = indegree[nbr.first] - 1;

        if(indegree[nbr.first] ==0)
          q.push(nbr.first);
      }
    }
  }
};

int main()
{
  graph g2;

  int n = 8;
  g2.addedge(0,1,1,1);
  g2.addedge(1,2,1,1);
  g2.addedge(1,3,1,1);
  g2.addedge(3,5,1,1);
  g2.addedge(3,7,1,1);
  g2.addedge(7,6,1,1);
  g2.addedge(7,4,1,1);

  // g2.printadjList();

  unordered_map<int,bool> visited;
  g2.topo_sortDFS(visited);

  cout<<" \n from KAHNs algo \n";
  g2.KAHNS_Algo_topoSort(8);

  return 0;
}

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

//--------------------------------------------------------------------------------
  // dfs topo ORDERING and taking out all the elements in the stack
  void dfs1(int src , unordered_map<int,bool> &visited , stack<int> &st )
  {
    visited[src]=true;

    for(auto nbr: adjList[src])
    {
      if(!visited[nbr.first])
      {
        dfs1(nbr.first ,visited, st);
      }
    }
    st.push(src);
  }

  // NORMAL DFS , with adjNew , which contains reversed edges
  void dfs2(int src ,  unordered_map<int,bool> &visited , unordered_map<int,list<int>> &adjNew)
  {
    visited[src]=true;
    cout<<src<<" "; // it will print the SSC one at each call

    for(auto nbr : adjNew[src]){
      if(!visited[nbr]){
        dfs2(nbr ,visited , adjNew);
      }
    }
  }


// KEEP IN MIND THAT WE CAN'T DISRUPT THE ORDER AND WE DON'T KNOW FROM WHERE TO START

  void SCC(int n)
  {
    unordered_map<int,bool> visited;
    stack<int> st;

//-- FIND THE TOPO ORDERING AND STORING IT
    for(int i=0;i<n;i++)
    {
      if(!visited[i])
        dfs1(i,visited , st);
    }


//-- REVERSING THE EDGES OF THE GRAPH
    unordered_map<int,list<int>> adjNew ; //new adjacency list , unweighted

    for(auto it : adjList)
    {
      for(auto nbr : it.second)
      {
        int u = it.first;
        int v = nbr.first;   // creation of adjNew , which contains reverse edges

        adjNew[v].push_back(u);
      }
    }

    // Now traversing the stack elements accordingly
    //so that all elements of stack are traversed in the same order

    unordered_map<int,bool> visited2;
    int count =0;
    while(!st.empty())
    {
      int top = st.top();
      st.pop();
      if(!visited2[top]){
        cout<<" SSC -- ";
        dfs2(top , visited2 , adjNew);
        count++;
        cout<<endl;
      }
    }

    cout<<"\n The number of SSC present = "<<count<<endl;

  }


};



int main()
{
  graph g2;

  int n = 8;
  g2.addedge(0,1,1,1);
  g2.addedge(1,2,1,1);
  g2.addedge(3,0,1,1);
  g2.addedge(2,3,1,1);
  g2.addedge(2,4,1,1);
  g2.addedge(4,5,1,1);
  g2.addedge(5,6,1,1);
  g2.addedge(6,4,1,1);
  g2.addedge(6,7,1,1);


  g2.printadjList();
  cout<<" \n printing all the SSCs \n";
  g2.SCC(n);

  return 0;
}

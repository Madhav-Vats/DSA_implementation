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

  void bfs(int src , unordered_map<int,bool> &visited , unordered_map<int ,list<pair<int,int>>> & adjNew)
  {
    visited[src]=true;

    queue<int>q;
    q.push(src);

    while(!q.empty())
    {
      int current = q.front();
      q.pop();
      for(auto nbr : adjNew[current])
      {
        if(!visited[nbr.first])
        {
          visited[nbr.first]=true;
          q.push(nbr.first);
        }
      }
    }
  }

  int count_components_bfs(int n ,unordered_map<int ,list<pair<int,int>>> &adjNew)
  {
    unordered_map<int,bool> visited;
    int count = 0;
    for(int i =0;i<n;i++)
    {
      if(!visited[i])
      {
        bfs(i,visited , adjNew);
        count++;
      }
    }

    return count;
  }


  void bridge_in_graph(int n , int &cnt , vector<pair<int,int>> &pairs)
  {

    // removal of a node and and checking fotr number of components
    // if it was a adjMatrix it would be easy

    // copy of adjList
    unordered_map<int ,list<pair<int,int>>> adjNew = adjList;

    int ans = 1;

    for(auto it:adjList)
    {
      for( auto nbr : it.second)
      {

        int u = it.first;
        int v = nbr.first;

        // breaking and then counting the components
        adjNew[u].remove({v,1});
        int count = count_components_bfs(n , adjNew);
        if(count > ans)
        {
          cnt++;
          pairs.push_back({u,v});
        }


        // joining again
        adjNew[u].push_back({v,1});
      }
    }

  }


  void dfs_Tarzans_algo( int src , int parent , int &timer, unordered_map<int,bool> & visited , vector<int> &tin , vector<int> &low , int &cnt, vector<vector<int>> &ans_pairs)
  {
    // adding this current node's timer to the tin and low and marking it as visited
    // initially we would pass timer as 1
    // initially parent would be -1
    visited[src]=true;
    tin[src] = timer;
    low[src] = timer;

    // increasing the timer by 1 for further dfs calls
    timer++;

    for(auto nbr:adjList[src])
    {
      if(nbr.first = parent)
        continue;

      if(!visited[nbr.first])
      {
        // dfs call
        dfs_Tarzans_algo( nbr.first , src , timer , visited , tin , low , cnt , ans_pairs);

        // at the end when no neighbour of this current source is left
        // then we will proceed with our algorithm

        // updating the low of the source node
        low[src] = min(low[src] , low[nbr.first]);

        // checing for the bridging edge
        if(low[nbr.first] > tin[src])
        {
          //bridging node present
          cnt++;
          vector<int> temp;
          temp.push_back(src);
          temp.push_back(nbr.first);
          ans_pairs.push_back(temp);
        }

      }

      else // if visited
      {
        // low update
        low[src] = min(low[src], low[nbr.first]);
      }
    }

  }



};


int main()
{
  graph g2;

  int n = 8;

  g2.addedge(0,1,1,1);
  g2.addedge(1,5,1,1);
  g2.addedge(1,6,1,1);
  g2.addedge(6,5,1,1);
  g2.addedge(1,2,1,1);
  g2.addedge(2,3,1,1);
  g2.addedge(3,4,1,1);
  g2.addedge(3,7,1,1);
  g2.addedge(7,8,1,1);

  g2.printadjList();


  int cnt = 0 ;
  vector<pair<int,int>> pairs;
  g2.bridge_in_graph(n , cnt , pairs);
  cout<<endl<<cnt<<endl;
  for(auto it: pairs)
  {
    cout<<it.first<<"--"<<it.second<<endl;
  }

  // using tarzans algorithm

  graph g3;

  int m = 5;
  g3.addedge(0,1,1,0);
  g3.addedge(1,2,1,0);
  g3.addedge(0,2,1,0);
  g3.addedge(0,3,1,0);
  g3.addedge(3,4,1,0);


  vector<int>tin(n);
  vector<int>less(n);

  vector<vector<int>> ans;
  unordered_map<int,bool>visited2;

  int counter =0;

  int timer = 1;
  g3.dfs_Tarzans_algo(0, -1 , timer , visited2 , tin , less , counter , ans );

  cout<<endl<<counter<<endl;

  for(auto it : ans)
  {
    for(auto i : it)
      cout<<i<<" ";

    cout<<endl;
  }

  return 0;

}

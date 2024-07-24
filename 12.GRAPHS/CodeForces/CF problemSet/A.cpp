//---  https://codeforces.com/gym/317667

// A - use dfs , with base condn if currInd >= t return false;

//B -

#include <bits/stdc++.h>
using namespace std;

void bfs(int src , vector<int>&visited , unordered_map<int,list<int>>&adjList) // or you could have written ( int src)
{

  queue<int> q;
  q.push(src);
  visited[src] = true;

  while(!q.empty())
  {
    int frontNode = q.front();
    q.pop();

    // cout<<frontNode<<" ";
    // nbr or neighbour
    for(auto nbr: adjList[frontNode])
    {
      if(!visited[nbr])
      {
        q.push(nbr);
        visited[nbr]=true;
      }
    }
  }

}

int main()
{
  int n , p;
  cin>>n>>p;

  vector<pair<int,int>>Cost;

  for(int i=0;i<n;i++)
  {
    int el;
    cin>>el;
    Cost.push_back({ el ,i});
  }

  unordered_map<int,list<int>>adjList;
  for(int i=0;i<p;i++)
  {
    int a ,b;
    cin>>a>>b;

    a--;
    b--;

    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  sort(Cost.begin() , Cost.end());

  long long ans = 0;

  vector<int>visited(n , false);

  for(int i=0;i<n;i++)
  {
    if(!visited[Cost[i].second])
    {
      // cout<<Cost[i].second<<" ";
      ans += Cost[i].first;
      bfs(Cost[i].second  ,visited , adjList );
    }
  }

  cout<<endl;

  cout<<ans;
}

#include <bits/stdc++.h>
using namespace std;
#include<list>
#include<unordered_map>

vector<vector<bool>>visited;
int dx[4] ={-1 , 1 , 0,0};
int dy[4] = {0,0,-1 ,1};
int n,m;

bool isValid(int nx , int ny)
{
  return nx >= 0 && ny>=0 && nx <n && ny < m;
}
void bfs(int i , int j , vector<vector<char>>&grid)
{
  queue<pair<int,int>>q;
  q.push({i , j});
  visited[i][j] = true;

  while(!q.empty())
  {
    pair<int,int>a = q.front();
    int x = a.first;
    int y = a.second;
    q.pop();

    for(int k = 0;k<4;k++)
    {
      int nx = x+dx[k];
      int ny = y + dy[k];

      if(isValid(nx , ny) && !visited[nx][ny] && grid[nx][ny]== '.')
      {
        visited[nx][ny] = true;
        q.push({nx , ny});
      }
    }
  }
}

int solve(vector<vector<char>>grid)
{
  int ans = 0;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(!visited[i][j] && grid[i][j] == '.')
      {
        ans++;
        bfs(i ,  j , grid);
      }
    }
  }

  return ans;
}

int main()
{

  cin>>n;
  cin>>m;

  char el;

  vector<vector<char>>grid(n , vector<char>(m));
  visited = vector<vector<bool>>(n , vector<bool>(m , false));


  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>el;
      grid[i][j] = el;
    }
  }

  int ans = solve(grid);

  cout<<ans;
}

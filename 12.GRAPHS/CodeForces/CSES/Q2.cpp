#include <bits/stdc++.h>
using namespace std;
#include<list>
#include<unordered_map>

vector<vector<bool>>visited;
int dx[4] ={1 , -1 , 0,0};
int dy[4] = {0,0,1 ,-1};
int n,m;

bool isValid(int nx , int ny)
{
  return nx >= 0 && ny>=0 && nx <n && ny < m;
}
vector<char>mpp = {'D' , 'U' ,'R' , 'L'};
vector<char> bfs(int i , int j , int di , int dj , vector<vector<char>>&grid)
{
  queue<tuple<int,int ,vector<char>>>q;
  q.push({i , j ,{}});
  visited[i][j] = true;

  while(!q.empty())
  {
    auto [x , y , path] = q.front();
    q.pop();

    if(x == di && y ==dj)
        return path;

    for(int k = 0;k<4;k++)
    {
      int nx = x+dx[k];
      int ny = y+dy[k];

      if(isValid(nx , ny) && !visited[nx][ny] && grid[nx][ny] != '#')
      {
        vector<char>temp = path;
        temp.push_back(mpp[k]);
        q.push({nx , ny , temp});
      }
    }
  }

  return {};
}

string solve(vector<vector<char>>grid)
{
  string ans;

  int srcI , srcJ , dI , dJ;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(grid[i][j] == 'A')
      {
          srcI  = i;
          srcJ = j;
      }
      else if(grid[i][j] == 'B')
      {
        dI = i;
        dJ =j;
      }
    }
  }


    ans = bfs(srcI , srcJ , dI , dJ , grid);


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

  string ans = solve(grid);

  if(ans != "not found")
  {
    cout<<"YES"<<endl;
    cout<<ans.length()<<endl;
    cout<<ans;
  }
  else
    cout<<"NO";

}

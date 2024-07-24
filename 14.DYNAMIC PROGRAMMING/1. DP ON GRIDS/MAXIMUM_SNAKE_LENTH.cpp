/*
Input:

grid = [
	[7, 5, 2, 3, 1],
	[3, 4, 1, 4, 4],
	[1, 5, 6, 7, 8],
	[3, 4, 5, 8, 9],
	[3, 2, 2, 7, 6]
]

Output: 7
*/


#include<bits/stdc++.h>
using namespace std;

bool CheckBoundary( int x , int y , int n , int m)
{
  return x >= 0 && x < n && y >= 0 && y < m;
  // if(x<n && x>=0 && y<m && y>=0)
  //   return true;
  //
  // return false;
}

int frec(int x , int y , vector<vector<int>>&grid , int &n , int &m , vector<vector<bool>> &visited)
{
  // Base case is the CheckBoundary
  if(CheckBoundary(x , y , n , m) == false)
    return 0;

  int dx[4] = {0,0,1,-1};
  int dy[4] = {1,-1,0,0};

  // mark this cell as visited for recursive stack
  visited[x][y] = true;

  int currAns = 1; // bcoz this cell is a part of the snake

  int tempAns = 0;


  // cout<<endl<<"the currAns is"<< currAns <<"the Temp ans is "<< tempAns<<endl;

  for(int i=0;i<4;i++)
  {
    int newX = x + dx[i];
    int newY = y + dy[i];


    if( !visited[newX][newY] && CheckBoundary(newX , newY , n , m) && abs(grid[x][y] - grid[newX][newY] ==1 ))
      {
        tempAns = max(tempAns , frec(newX , newY , grid , n , m , visited));
      }
  }


  return currAns + tempAns;
}

int MaxSnakeLength(vector<vector<int>>& grid)
{
  int n = grid.size();
  int m = grid[0].size();


  vector<vector<bool>>visited(n ,vector<bool>(m , false));

  int ans = frec(0 , 2, grid , n ,m , visited);

  // traversing for all the cells
  // for(int i=0;i<n;i++)
  // {
  //   for(int j= 0;j<m;j++)
  //   {
  //     cout << "Starting from cell (" << i << ", " << j << "): ";
  //     ans = max(ans , frec(i,j, grid , n , m));
  //     cout << "Max length found: " << ans << endl;
  //   }
  // }

  return ans;
}


int main()
{
  vector<vector<int>>grid = 	{{7, 5, 2, 3, 1}};

  int ans = MaxSnakeLength(grid);

  cout<<ans;


  return 0;


}

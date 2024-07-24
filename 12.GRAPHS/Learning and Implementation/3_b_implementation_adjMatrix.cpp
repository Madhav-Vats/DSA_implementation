#include <bits/stdc++.h>
using namespace std;
#include<list>
# include<unordered_map>

// using int only
class graph_mat{
public:
  vector<vector<int>> adjMatrix;

  // constructor
  graph_mat(int m , int n ): adjMatrix(m , vector<int>(n,0))
  {
      // blank( constructorc could be blank )
  }

  void addedge(int u , int v , bool direction )
  {
    adjMatrix[u][v]=1;

    if(!direction)
      adjMatrix[v][u]=1;
  }

  void print_adjMatrix(int m , int n)
  {

    for(int i =0;i<m;i++)
    {
      cout<<i<<" --> ";
      for(int j=0;j<n;j++)
      {
        cout<<adjMatrix[i][j]<<" , ";
      }
      cout<<endl;
    }
  }

  // don't learn this , it was just a brute force
  // void bfs(int src , unordered_map<int,bool> &visited , int m , int n)
  // {
  //
  //   queue<int>q;
  //   q.push(src);
  //   visited[src]=true;
  //
  //   while(!q.empty())
  //   {
  //     int current = q.front();
  //     q.pop();
  //
  //     cout<<current<<" ";
  //
  //
  //     for(int i = 0;i<n ; i++)
  //     {
  //       // checking for the main condition
  //       if(!visited[i] && adjMatrix[current][i]==1)
  //       {
  //         // pushing the neigbour of the current front node of the queue
  //         q.push(i);
  //         // marking them visited
  //         visited[i] = true;
  //       }
  //     }
  //   }
  // }


  void dfs(int src , unordered_map<int,bool> &visited , int n)
  {
    //making the bool of source in visited as TRUE
    visited[src]=true;
    cout<<src<<" ";

    // going for the size of row
    for( int i =0;i<n;i++)
    {
      // working only on those elements which are neighbour of our source
      if(!visited[i] && adjMatrix[src][i]==1)
      {
        // recursive call of dfs , and making these found neighbours as the source this time
        dfs(i , visited , n);
      }
    }
  }


  // for BFS OF A  adjMatrix , the visited map should be of a pair{i,j}, not for a single elements bool
  void bfs_mat(int i , int j , map<pair<int,int>,bool> & visited )
  {

    queue<pair<int,int>> q;
    q.push({i,j}); // source is pushed into the queue

    // fails , doesnt work
    while(!q.empty())
    {
      auto current = q.front();
      int x = current.first;
      int y= current.second;

      cout<<adjMatrix[x][y];

      q.pop();

      // neighbour elements are at max 4 ,
      // so either you write condition for all for of them like this

      /* {
      if (x - 1 >= 0 && !visited[{x - 1, y}] && adjMatrix[x - 1][y] == 1) {
            visited[{x - 1, y}] = true;
            q.push({x - 1, y});
        }

        if (y - 1 >= 0 && !visited[{x, y - 1}] && adjMatrix[x][y - 1] == 1) {
            visited[{x, y-1}] = true;
            q.push({x, y - 1});
        }

        if (x + 1 < adjMatrix.size() && !visited[{x + 1, y}] && adjMatrix[x + 1][y] == 1) {
            visited[{x + 1, y}] = true;
            q.push({x + 1, y});
        }

        if (y + 1 < adjMatrix[0].size() && !visited[{x, y + 1}] && adjMatrix[x][y + 1] == 1) {
            visited[{x, y + 1 }] = true;
            q.push({x, y + 1});
        }
  }
  }
}}} */

      //or just realize that you got only 4 sides
      int dx[] = {-1,1,0,0};
      int dy[] = {0,0,-1,1};

      for(int i =0;i<4 ;i++)
      {
        int newX = x + dx[i];
        int newY = y + dy[i];

          // make sure that you write the boundary conditions
        if(newX >=0 && newX < adjMatrix.size() && newY >=0 &&  newY < adjMatrix[0].size() && !visited[{newX ,newY}] && adjMatrix[newX][newY]==1 )
          {
            visited[{newX ,newY}] = true;
            q.push({newX , newY});
          }
        }
      }
    }
  };

int main()
{
//   graph_mat g(11,11);
//
// // for integer graph
//   g.addedge(0,1,0);
//   g.addedge(1,2,0);
//   g.addedge(1,3,0);
//   g.addedge(3,5,0);
//   g.addedge(3,7,0);
//   g.addedge(7,6,0);
//   g.addedge(7,4,0);
//   g.addedge(8,9,0);
//   g.addedge(10,10,0);
//
//   int n=11; // number of vertices
//   int m=11;
//   g.print_adjMatrix(m,n);
//
//   unordered_map<int,bool> visited;
//
//   cout<<endl<<"---------------------------->"<<endl;
//   cout<<endl;
//
//   int count = 0;

  // for(int i =0;i<n;i++)
  // {
  //   if(!visited[i])
  //   {
  //     cout<<"component : ";
  //     g.bfs(i , visited , m,n);
  //     //cout<<endl;
  //     count++;
  //   }
  // }

//  cout<<count;





  graph_mat g2(4,5);

  g2.addedge(0,0,1);
  g2.addedge(1,1,1);
  g2.addedge(0,2,1);
  g2.addedge(2,0,1);
  g2.addedge(0,1,1);
  g2.addedge(1,0,1);
  g2.addedge(0,3,1);
  g2.addedge(1,3,1);
  g2.addedge(2,1,1);


  cout<<endl;
  map<pair<int, int>, bool> visited2;
  int m = 4;
  int n=5;

  int ct = 0;
  for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
      {
          if (!visited2[{i, j}] && g2.adjMatrix[i][j]==1) {
              g2.bfs_mat(i, j, visited2);
              ct++;
          }
      }
      cout<<endl;

  }

  cout << ct;

  return 0;
}



// for(int i=0;i<8;i++)
// {
//   if(!vis  ited[i])
//   {
//     g.bfs(i , visited , 8);
//     count++;
//   }
// }

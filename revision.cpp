#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &ans , int & element)
{
    ans.push_back(element);
    // parent element is always at i/2
    int i = ans.size() -1 ;

    while (i> 0 && ans[i] < ans[(i-1) / 2])
       {
          swap(ans[i], ans[(i-1) / 2]);
          i = (i-1)/2;
        }
}


vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // Write your code here
    vector<int> temp;

    for(int i=0; i<n ;i++)
    {
        temp.push_back(arr1[i]);
    }

    for(int i=0; i<m ;i++)
    {
        temp.push_back(arr2[i]);
    }

    vector<int> ans ;
    for( int i=0 ; i< m+n ; i++)
    {
       heapify(ans , temp[i]);
    }

    return ans;

}



class Solution {
public:

    void dfs_filling(int x , int y , vector<vector<int>>& heightMap , int surr_min, int &fill_ans , int & not_x , int & not_y  , int m , int n )
    {
        // ititially notx and noty would be same as x and y
        // initially min_surr would be startingpoints surr max ,
        //lets say 1000 if you dont want to go that way

        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int newX = x+dx[i];
            int newY = y+dy[i];


            bool avoided_direction =(newX != not_x && newY != not_y);

            // bool avoided_cell_1 = (newX == 1 && heightMap[newX][newY] < heightMap[0][newY]);
            // bool avoided_cell_2 = (newX == m-1 && heightMap[newX][newY] < heightMap[m][newY]);
            // bool avoided_cell_3 = (newY == 1 && heightMap[newX][newY] < heightMap[newX][0]);
            // bool avoided_cell_4 = (newY == n-1 && heightMap[newX][newY] < heightMap[newX][n]);

           bool avoided_cell_1 = (newX == 0 && heightMap[newX][newY] < heightMap[0][not_y]);
           bool avoided_cell_2 = (newX == m - 1 && heightMap[newX][newY] < heightMap[m - 1][not_y]);
           bool avoided_cell_3 = (newY == 0 && heightMap[newX][newY] < heightMap[not_x][0]);
           bool avoided_cell_4 = (newY == n - 1 && heightMap[newX][newY] < heightMap[not_x][n - 1]);

          bool avoided_cells =(avoided_cell_1 || avoided_cell_2 || avoided_cell_3 || avoided_cell_4);


            // adding condition for skipping cases

            if( avoided_cells && avoided_direction && newX>=1  && newX <m-1 && newY >=1 && newY < n-1 )
            {
                if(heightMap[x][y] <= heightMap[newX][newY])
                {
                    // dfs call
                    dfs_filling( newX , newY , heightMap , surr_min , fill_ans , x ,y ,m ,n );
                    // there is no way to fill now , current cell is shorter than the surroundings

                    // filling untill surr_min
                    int prev_val = heightMap[x][y];
                    int to_be_filled = surr_min - prev_val;

                    fill_ans += to_be_filled;

                    // changing the cureent cell value to to be filled value
                    heightMap[x][y] = surr_min;

                }

                else
                {
                    surr_min = min(surr_min , heightMap[newX][newY]);
                }

            }
        }

    }
    int trapRainWater(vector<vector<int>>& heightMap) {


        int m = heightMap.size();
        int n = heightMap[0].size();
        int result = 0;

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                // What are the initial skipping cases

                dfs_filling(i,j ,heightMap , 10000 , result , i , j , m , n);
            }
        }

    return result;



    }
};


class Sol {
public:
    vector<vector<int>> solve(vector<vector<char>>& board) {

    // making a matrix of 0 and 1
        vector<vector<int>> arr;

        int m=board.size();
        int n =board[0].size();


        arr.resize(m , vector<int>(n,0));

        for(int i=0;i<m;i++)
          {
            for(int j=0;j<n;j++)
              {
                if(board[i][j] == 'X')
                  arr[i][j] = 1;
                else
                  arr[i][j] = 0;
              }
          }




        return arr;


    }
};
int main()
{
  Sol s;


  vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    vector<vector<int>> ans = s.solve(board);
    for (const auto &row : ans) {
        for (const int &cell : row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }





    //
    // Solution solution;
    // int trappedWater = solution.trapRainWater(heightMap);
    //
    // cout << "Trapped water: " << trappedWater << endl;
    //
    // return 0;



return 0;
}





class Solution {
public:
    using v = pair<double, int>;  // Define a pair type for probability and node index
    vector<vector<v>> adj;  // Adjacency list to store the graph

    void create_adj(int n, vector<vector<int>>& edges, vector<double>& succProb) {
        adj.resize(n);  // Resize the adjacency list to the number of nodes
        int eN = edges.size();
        for (int i = 0; i < eN; i++) {
            int v0 = edges[i][0], v1 = edges[i][1];  // Get the source and target nodes of the edge
            adj[v0].push_back({succProb[i], v1});  // Add the target node and its success probability to the adjacency list of the source node
            adj[v1].push_back({succProb[i], v0});  // Add the source node and its success probability to the adjacency list of the target node
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n, 0);  // Initialize the probability vector for each node as 0
        create_adj(n, edges, succProb);  // Create the adjacency list for the graph
        priority_queue<v, vector<v>> pq;  // Priority queue to store nodes based on their probabilities in descending order

        pq.push({1.0, start});  // Push the start node with probability 1 to the priority queue
        prob[start] = 1.0;  // Set the probability of the start node as 1

        while (!pq.empty()) {
            auto [cur_prob, i] = pq.top();  // Get the node with the highest probability from the priority queue
            pq.pop();

            if (i == end) {  // If the current node is the end node, return its probability
                return cur_prob;
            }

            for (auto [next_prob, j] : adj[i]) {  // Iterate through the adjacent nodes of the current node
                double new_prob = cur_prob * next_prob;  // Calculate the new probability by multiplying the current probability with the success probability of the edge
                if (new_prob > prob[j]) {  // If the new probability is higher than the existing probability of the adjacent node
                    prob[j] = new_prob;  // Update the probability of the adjacent node
                    pq.push({new_prob, j});  // Push the adjacent node with its new probability to the priority queue for further exploration
                }
            }
        }
        return 0.0;  // If the end node is not reachable, return 0 as the maximum probability
    }
};

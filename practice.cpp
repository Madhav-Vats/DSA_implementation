#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs_filling(int x, int y, vector<vector<int>>& heightMap, int& surr_min, int& fill_ans, int m, int n) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            bool avoided_direction = (newX != x && newY != y);

            // adding condition for skipping cases
            if (avoided_direction && newX >= 1 && newX < m - 1 && newY >= 1 && newY < n - 1) {
                if (heightMap[x][y] <= heightMap[newX][newY]) {
                    // dfs call
                    dfs_filling(newX, newY, heightMap, surr_min, fill_ans, m, n);

                    // there is no way to fill now, current cell is shorter than the surroundings
                    int prev_val = heightMap[x][y];
                    int to_be_filled = surr_min - prev_val;

                    fill_ans += to_be_filled;

                    // changing the current cell value to to_be_filled value
                    heightMap[x][y] = surr_min;
                } else {
                    surr_min = min(surr_min, heightMap[newX][newY]);
                    dfs_filling(newX, newY, heightMap, surr_min, fill_ans, m, n);
                }
            }
        }
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        int result = 0;
        int surr_min = 10000;

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                // What are the initial skipping cases
                dfs_filling(i, j, heightMap, surr_min, result, m, n);
            }
        }

        return result;
    }
};


class Solution2 {
public:

    void kahns_algo( int src , unordered_map<int,list<int>> &adjList , int &ans)
    {
    // STEPS :- indegree map , queue , while(!q.empty()) condition
                // with printing of independent elements

    // 1 .creation of the indegree Map
        unordered_map<int,int> indegree;

        for(auto it: adjList)
        {
            for(auto i : it.second)
            {
                indegree[i]++;
            }
        }
        // indegree completed

    // 2.
        queue<int>q;
        q.push(src);

        int cnt = 0;

        while(!q.empty())
        {
            cnt++;
            int current = q.front();

            for(auto nbr: adjList[current])
            {
                indegree[nbr] -=1;

                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }


        }

        ans =cnt;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int a ;

    // how to approach in the problem , and what are the ways of solving it
    /*

        // check if cycle s present or not

        // you do this via dfs with visited and dfs_visited map

        // or you can go via topo sort
            //we dont need the topo sort stored , we just need its size
    */

    // adjList
    unordered_map<int,list<int>> adjList;

    for(auto it: prerequisites)
    {
        adjList[it[1]].push_back(it[0]);
    }

    // calling the method
    int ans = 0;
    kahns_algo( 0 , adjList , ans);

    if(ans == numCourses)
        return true;     // if the length of topo = number of vertices then no cycle

    return false;

    }
};

int main() {
  // Online C++ compiler to run C++ program online

    // Write C++ code here

   string s = " madhav";
   cout<<s.substr(1);

    return 0;
}

}

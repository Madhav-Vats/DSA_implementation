
// Explaination and Intution , and all theory is written in this commented section
/*
{

        // each number on the dial pad have only few options to explore
        // 0 - {4, 6}
        // 1 - {6, 8}
        // 2 - {7, 9}
        // 3 - {4, 8}
        // 4 - {0, 3, 9}
        // 5 - {}
        // 6 - {0, 1, 7}
        // 7 - {2, 6}
        // 8 - {1, 3}
        // 9 - {2, 4}

        // So can we make a graph , and and make an adjList , and use Dfs and Bfs , Right

        // vector<vector<int>>map = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

        // unordered_map<int , list<int>>adjList;

        // for(int i=0 ; i<10;i++)
        // {
        //     for(auto &it: map[i])
        //     {
        //         adjList[i].push_back(it);
        //     }
        // }

        // this map , can act as AdjMatrix , so we will use it
}
*/

// ------    CONSIDERING IT AS A GRAPH PROBLE ------------------------

class Solution {
public:

    vector<vector<int>>adjMatrix = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    int mod = 1000000007;

    int dfs( int node , int n , vector<vector<int>>&dp)
    {
        n = n-1;
        if(n<=0)
            return 1;

        if(dp[node][n] != -1)
            return dp[node][n];

        int temp = 0;

        for(auto &it: adjMatrix[node])
        {
            temp = (temp + dfs(it , n , dp ) )%mod;
        }

        return dp[node][n] = temp;
    }


    int knightDialer(int n) {

        int ans = 0;

        vector<vector<int>>dp (10 , vector<int>(n , -1));


        for(int i=0;i<10;i++)
        {
            ans = ( ans+ dfs(i , n , dp) )%mod;

            // map is already there as a member of Class
        }


        return ans;


    }
};

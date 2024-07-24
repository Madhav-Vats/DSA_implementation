
// ----------------------------          Dynamic Programming         --------------------------------------

// Solving it as a DP problem and memoization and Tabulation both

class Solution {
public:

    vector<vector<int>>jumps = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    int mod = 1000000007;


// ---------------------------    Memoization      --------------------------------------

    int fMemo( int digit , int n , vector<vector<int>>&dp)
    {
        if(n<=0)
            return 1;

        if(dp[digit][n] != -1)
            return dp[digit][n];

        int temp = 0;

        for(auto &it: jumps[digit])
        {
            temp = (temp + fMemo(it , n-1 , dp ) )%mod;
        }

        return dp[digit][n] = temp;
    }

    int knightDialer(int n) {

        int ans = 0;

        vector<vector<int>>dp (10 , vector<int>(n+1 , -1));


        for(int digit=0 ; digit<10 ; digit++)
        {
            // the i represents the 1st element
            // the other elements are going to be decided by i , and f(n-1) will handle it
            ans = ( ans+ fMemo(digit , n-1 , dp) )%mod;

            // map is already there as a member of Class
        }

        return ans;

    }


    // ---------------------------- Tabulation ---------------------------------------
};

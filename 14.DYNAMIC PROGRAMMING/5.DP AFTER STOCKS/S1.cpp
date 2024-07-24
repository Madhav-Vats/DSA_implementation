class Solution_DP1 {
public:
    int maxProfit(vector<int>& prices) {

        //loop in opposite direction than written in notes

        //i will start from  second last , and go till the first element
        // arr[i] = buying the stock at this price
        // and we need the max , in the right of it , so that after selling profit is max

        int size = prices.size();

    //     // for the last second element , max in right is the last element
    //     int maxSell = prices[size-1];
    //     int profit = 0;

    //     for(int i=size-2;i>=0;i--)
    //     {
    //         int currProfit = maxSell - prices[i];  // selling price - buying price
    //         maxSell = max(maxSell , prices[i]);

    //         profit = max(profit , currProfit);
    //     }

    //     return profit;

    // }

        int minBuy = prices[0];
        int profit = 0;

        for(int i=1;i<size;i++)
        {
            int currProfit = prices[i] - minBuy;
            profit = max(profit , currProfit);

            minBuy = min(minBuy , prices[i]);
        }

        return profit;

    }
};


class Solution_DP2 {
public:

  //memozation
  int fmemo( int ind , int AllowedToBuy , vector<int>&prices , int size , vector<vector<int>>&dp)
  {
      //base case
      if(ind == size )
      {
          return 0;
      }

      if(dp[ind][AllowedToBuy] !=- 1 )
      {
          return dp[ind][AllowedToBuy];
      }


     if(AllowedToBuy != 0)
     {
         int kharidIsko = (-prices[ind]) + fmemo(ind+1 , 0 , prices ,size, dp );
         int aageDekhenge = fmemo(ind+1 , 1 , prices , size , dp);
         return dp[ind][AllowedToBuy] =  max(kharidIsko , aageDekhenge);
     }

     else // u hae to sell only , not allowed to buy
     {
         int yhiBech = (+ prices[ind]) + fmemo(ind+1 , 1 , prices , size , dp);
         int aageBechenge = fmemo(ind+1 , 0 , prices , size , dp);
         return dp[ind][AllowedToBuy] = max(yhiBech , aageBechenge);
     }

  }


  // normal TABULATION
  int maxProfitTabul(vector<int>& prices) {

    int size = prices.size();

    vector<vector<int>>dp ( size+1 , vector<int>(2 , 0));

    // base cases and initialization
    for(int i=0;i<2;i++)
    {
        dp[size][i] = 0;
    }

    for(int ind = size-1;ind >= 0;ind--)
    {
        for(int AllowedToBuy = 0; AllowedToBuy<2;  AllowedToBuy++ )
        {
            //copy the recurrence
            if(AllowedToBuy != 0)
            {
                int kharidIsko = (-prices[ind]) + dp[ind+1][0];
                int aageDekhenge = 0 + dp[ind+1][1];
                dp[ind][AllowedToBuy] =  max(kharidIsko , aageDekhenge);
            }

            else // u hae to sell only , not allowed to buy
            {
                int yhiBech = (+ prices[ind]) + dp[ind+1][1];
                int aageBechenge = 0 + dp[ind+1][0];
                dp[ind][AllowedToBuy] = max(yhiBech , aageBechenge);
            }
        }

    }

    return dp[0][1];  // bcoz at first we can only buy , no sell
  }


  // space optimized TABULATION
  int maxProfit(vector<int>& prices) {

    int size = prices.size();
    vector<int> curr( 2, 0) , next( 2, 0);

    // base cases and initialization
        //already : next Elements are 0

    for(int ind = size-1;ind >= 0;ind--)
    {
        for(int AllowedToBuy = 0; AllowedToBuy<2;  AllowedToBuy++ )
        {
            //copy the recurrence
            if(AllowedToBuy != 0)
            {
                int kharidIsko = (-prices[ind]) + next[0];
                int aageDekhenge = next[1];

                curr[AllowedToBuy] =  max(kharidIsko , aageDekhenge);
            }

            else // u hae to sell only , not allowed to buy
            {
                int yhiBech = (+ prices[ind]) + next[1];
                int aageBechenge = next[0];

                curr[AllowedToBuy] = max(yhiBech , aageBechenge);
            }
        }
        // making next = curr for the next iteration
        next = curr;

    }

    return next[1];  // u can return anyone , either next[1] , or curr[1] , bcoz both are same
  }
};


class Solution_DP3 {
public:

  int fmemo( int ind , int AllowedToBuy , int NumTransactions , vector<int>& prices , int size , vector<vector<vector<int>>> &dp)
  {
    //base case ( if NUmTransactions ==2 , return 0)
    if(NumTransactions == 2)
      return 0;

    if(ind == size)
      return 0;

    if(dp[ind][AllowedToBuy][NumTransactions]  != -1)
      return dp[ind][AllowedToBuy][NumTransactions];

    // make NUmTransactions++ only after selling , not after buying

     if(AllowedToBuy != 0)
   {
      int kharidIsko = (-prices[ind]) + fmemo(ind+1 , 0 ,NumTransactions, prices ,size , dp);
      int aageDekhenge = fmemo(ind+1 , 1 ,NumTransactions, prices , size, dp );
      return dp[ind][AllowedToBuy][NumTransactions] =  max(kharidIsko , aageDekhenge);
   }

   else // u hae to sell only , not allowed to buy
   {
      int yhiBech = (+ prices[ind]) + fmemo(ind+1 , 1 , NumTransactions+1 , prices , size, dp); // no ++i , no i++
      int aageBechenge = fmemo(ind+1 , 0 ,NumTransactions, prices , size , dp );
      return dp[ind][AllowedToBuy][NumTransactions] = max(yhiBech , aageBechenge);
   }
  }

  // memoization usage
  int maxProfit(vector<int>& prices) {

    int size = prices.size();

    vector<vector<vector<int>>>dp (size , vector<vector<int>>(2 , vector<int>(3 , -1)));
    return fmemo(0 , 1 , 0 , prices , size , dp);
  }

};

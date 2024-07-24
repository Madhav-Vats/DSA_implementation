// BRUTE FORCE
class Solution {
public:

    int mod = 1000000007;

    int findValidNum( int x  , int y , int n)
    {
        n = n-1;

        if(x>3 || y>2 || x<0 || y<0)
            return 0;

        if(x==3 && y==0)
            return 0;

        if(x==3 && y==2)
            return 0;

        if(n<=0)
            return 1;

        // left chaal
        int leftiDown = findValidNum(x-2 , y+1 ,  n);

        int leftiUp  = findValidNum(x-2 , y-1 ,  n);



        // right chaal
        int RightDown = findValidNum(x+2 , y+1 , n);

        int RightUp  = findValidNum(x+2 , y-1 , n);


        // Above chaal
        int AboveLeft = findValidNum(x-1 , y-2 , n);

        int AboveRight  = findValidNum(x+1 , y-2 , n);


        // Below chaal
        int BelowLeft = findValidNum(x-1 , y+2 ,  n);

        int BelowRight  = findValidNum(x+1 , y+2 , n);



        return  ( leftiDown + leftiUp + RightDown  + RightUp  + AboveLeft + AboveRight + BelowLeft + BelowRight );

    }

    int findAns(int &n)
    {
        // consider a virtual matrix
        // 4*3 , where matrix[3][0] and matrix[3][2] , are unreachable
        int temp = 0 ;
        for(int i=0;i<4;i++)
        {
            for(int j= 0 ;j<3;j++)
            {
                // * and # should be avoided
                if((i==3 && j==0) || (i==3 && j==2))
                {
                    continue;
                }
                else
                {
                    temp += findValidNum(i , j , n);
                }
            }
        }

        return temp;
    }


    int MemofindValidNum( int x  , int y , int n , vector<vector<vector<int>>>&dp)
    {
        n = n-1;

        if(x>3 || y>2 || x<0 || y<0)
            return 0;

        if(x==3 && y==0)
            return 0;

        if(x==3 && y==2)
            return 0;

        if(n<=0)
            return 1;

        if(dp[n][x][y] != -1)
            return dp[n][x][y];

        // left chaal
        int leftiDown = MemofindValidNum(x-2 , y+1 ,  n  , dp );

        int leftiUp  = MemofindValidNum(x-2 , y-1 ,  n, dp );

        int left = ((leftiDown % mod) + (leftiUp%mod))%mod;

        // right chaal
        int RightDown = MemofindValidNum(x+2 , y+1 , n, dp );

        int RightUp  = MemofindValidNum(x+2 , y-1 , n, dp );

        int right = ((RightDown % mod) + (RightUp%mod))%mod;

        // Above chaal
        int AboveLeft = MemofindValidNum(x-1 , y-2 , n, dp );

        int AboveRight  = MemofindValidNum(x+1 , y-2 , n, dp );

        int above = ((AboveLeft % mod) + (AboveRight%mod))%mod;

        // Below chaal
        int BelowLeft = MemofindValidNum(x-1 , y+2 ,  n, dp );

        int BelowRight  = MemofindValidNum(x+1 , y+2 , n, dp );

        int below = ((BelowLeft % mod) + (BelowRight%mod))%mod;

        return dp[n][x][y] = ( (left + right)%mod + (above+below)%mod )%mod;

    }

    int MemofindAns(int &n)
    {
        // consider a virtual matrix
        // 4*3 , where matrix[3][0] and matrix[3][2] , are unreachable
        int temp = 0 ;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(3, -1)));

        for(int i=0;i<4;i++)
        {
            for(int j= 0 ;j<3;j++)
            {
                // * and # should be avoided
                if((i==3 && j==0) || (i==3 && j==2))
                {
                    continue;
                }
                else
                {
                    temp = ( temp + MemofindValidNum(i , j , n , dp) )%mod;
                }
            }
        }

        return temp;
    }




    int knightDialer(int n) {


        return MemofindAns(n);

    }
};

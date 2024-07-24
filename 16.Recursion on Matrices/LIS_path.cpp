#include<bits/stdc++.h>
using namespace std;

class Solution {
public:


    bool isValid( int x , int y , int m , int n)
    {
        if(x<m && x>=0 && y<n && y>=0)
            return true;

        return false;

    }

    int fmemo( int x , int y , int parentX , int parentY , int m , int n, vector<vector<int>>& matrix)
    {

        int cnt = 1;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        int maxi = 0;

        for(int i=0;i<4;i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(isValid(newX , newY ,m ,n) && matrix[newX][newY] > matrix[x][y])
            {
                int currPathVal = fmemo( newX , newY , x ,y , m ,n ,matrix);
                if(currPathVal > maxi)
                {
                  maxi = max(maxi , currPathVal);
                  // cout<<matrix[newX][newY];
                }
            }
        }


        return cnt + maxi;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int maxVal = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                maxVal = max( maxVal , fmemo(i , j , -1 ,-1 , m ,n ,matrix));
            }
        }

        return maxVal;


    }
};

int main()
{

  Solution sol;
  vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
  int ans = sol.longestIncreasingPath( matrix);

  cout<<ans;




  return 0;
}

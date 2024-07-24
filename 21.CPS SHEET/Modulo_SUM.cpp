// #include <bits/stdc++.h>
// using namespace std;
//
// bool frec(int ind , vector<int>&arr , int sum , int m)
// {
//   //base cases
//   if(sum!=0 && sum%m == 0)
//     return true;
//
//   if(ind<0)
//   {
//     if(sum!=0 && sum%m == 0)
//       return true;
//
//     return false;
//   }
//
//
//   int take = frec(ind-1 , arr , sum+arr[ind] , m );
//   int notTake = frec( ind-1 , arr , sum , m );
//
//   return take||notTake;
// }
// bool fmemo(int ind , vector<int>&arr , int sum , int m , vector<vector<int>>&dp)
// {
//   //base cases
//   if(sum!=0 && sum%m == 0)
//     return true;
//
//   if(ind<0)
//   {
//     if(sum!=0 && sum%m == 0)
//       return true;
//     return false;
//   }
//
//   if(dp[ind][sum]!= -1)
//     return dp[ind][sum];
//
//   int take = fmemo(ind-1 , arr , sum+arr[ind] , m , dp);
//   int notTake = fmemo( ind-1 , arr , sum , m ,dp);
//
//   return dp[ind][sum] = take|notTake;
// }
//
// bool Tabulation(vector<int>&arr ,int n , int m , int TotalSum)
// {
//   //making dp array
//   vector<vector<int>>dp(n+1 , vector<int>(TotalSum , 0));
//
//   //base case initialization
//   for(int i=0;i<=n;i++)
//   {
//     for(int j =1 ;j<=TotalSum ;j++)
//     {
//       if(j%m != 0)
//         continue;
//
//       dp[i][j] = 1;
//     }
//   }
//
//   //shifting of indices has been used
//   for(int ind=1;ind<=n;ind++)
//   {
//     for(int sum=0;sum<=TotalSum;sum++)
//     {
//       //copy the recurrence
//       int take = dp[ind-1][sum+arr[ind-1]];
//       int notTake = dp[ind-1][sum];
//
//       dp[ind][sum] = take|notTake;
//
//     }
//   }
//
//   return dp[n][TotalSum];
//
// }
//
// int main()
// {
//   {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//    //freopen("output.txt","w",stdout);
//     #endif
//   }
//
//   int n,m;
//   cin>>n>>m;
//
//   vector<int>arr(n);
//   for(int i =0;i<n;i++)
//   {
//     cin>>arr[i];
//   }
//
//   int sum  = 0;
//   int totalSum = accumulate(arr.begin() , arr.end() , 0);
//
//   vector<vector<int>>dp(n , vector<int>(totalSum+1 ,-1));
//
//   int ans = fmemo( n-1 , arr , sum ,m , dp);
//   int ans2= Tabulation(arr , n , m , totalSum);
//
//   cout<<ans2<<endl;
//   cout<<ans;
//   if(ans ==true)
//     cout<<"YES";
//   else
//     cout<<"NO";
//
//
//   return 0;
// }

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool dynamicProgramming(int n, const vector<int> &arr, int m) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

    // Base case: subset with sum 0 is always possible
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Dynamic programming
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= totalSum; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    // Check if there exists a subset with sum divisible by m
    for (int j = 1; j <= totalSum; ++j) {
        if (j % m == 0 && dp[n][j]) {
            return true;
        }
    }

    return false;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool ans = dynamicProgramming(n, arr, m);

    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

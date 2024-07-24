#include<bits/stdc++.h>
using namespace std;



// Question 2 , string with no 3 consecutive 1s , binary STRING
void generate(int ind , string str , int len)
{
  if(str.length() == len)
  {
    cout<<str<<endl;
    return;
  }

  if(ind>=2 && str[ind-1]=='1' && str[ind-2] == '1')
  {
    generate(ind+1 , str + "0" , len);
  }

  else
  {
    generate(ind+1 , str+"1" , len);

    generate(ind+1 , str+"0" , len);
  }
}



// Counting the total Number of Such Strings

int generateCount(int ind , string str , int len)
{
  if(str.length() == len)
  {
    return 1;
  }

  int Constraint1 = 0;

  int with1 = 0;
  int without1 = 0;

  // Constraint1 represents the case where '11' is encountered
    if (ind >= 2 && str[ind - 1] == '1' && str[ind - 2] == '1') {
        // Only '0' can be appended in this case to avoid consecutive '1's
        Constraint1 = generateCount(ind + 1, str + "0", len);
    }

    else
    {
      // Count the number of strings with '1' appended and '0' appended
      with1 = generateCount(ind + 1, str + "1", len);
      without1 = generateCount(ind + 1, str + "0", len);
    }

    // Return the sum of counts
    return Constraint1 + with1 + without1;
}

int generateCount2(int len) {
    // Initialize a 2D table to store counts
    vector<vector<int>> dp(len + 1, vector<int>(2, 0));

    // Base cases
    dp[0][0] = 1; // Base case: Empty string
    dp[0][1] = 1; // Base case: Empty string

    // Fill the table iteratively
    for (int i = 1; i <= len; ++i) {
        // For strings ending with '0'
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        // For strings ending with '1'
        dp[i][1] = dp[i - 1][0];
    }

    // Return the count of valid binary strings of length 'len'
    return dp[len][0] + dp[len][1];
}

int main()
{
  string str = "";

  int len = 16;

  int ans = generateCount(0 , str , len);

  int ans2 = generateCount2(len);

  cout<<ans<<endl<<ans2;


  return 0;
}

#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s)
{
    int n = s.length();
    for(int i=0;i<=n/2;i++)
    {
        int j= n-i-1;

        if(s[i] != s[j])
            return false;
    }

    return true;
}
int solve(int ind ,string s)
{
    if(ind == s.length())
        return 0;

    string soFar = "";

    int ans = INT_MAX;

    for(int i=ind;i<s.length();i++)
    {
        soFar += s[i];
        
        if(isPalindrome(soFar) == false)
            continue;

        ans = min(ans , 1 + solve(i+1 , s));        
    }


    return ans;
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;


    int ans  = solve(0 ,s);
    cout<<ans<<endl;
    return 0;
}
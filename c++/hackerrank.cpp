#include <bits/stdc++.h>
using namespace std;


vector<int> ans( vector<int>& arr)
{
    vector<int> ds;
    int size = arr.size();
    for (int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            int sum = arr[i]+arr[j];
            if(sum%2==0)
            {
                ds.push_back(sum);
            }

        }
    }
    return ds;
}

int sol ( vector<int> &arr)
{
    vector<int> ds =ans(arr);
    int size=ds.size();
    int maximum=ds[0];
    if(!ds.empty())
    {
        for(int i=0;i<size;i++)
        {
            if(ds[i]>maximum)
                maximum=ds[i];
        }
        return maximum;
    }
    else
        return -1;

}


int main() {

    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
}

    int ans= sol(arr);
    cout<<ans;



    return 0;
}

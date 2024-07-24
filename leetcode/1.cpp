#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums)
{
    vector<int> zeroes;
    vector<int> temp;
    int n=nums.size();
    int cnt1=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==0)
        {
            zeroes.push_back(nums[i]);
            cnt1++;
        }
        else
        temp.push_back(nums[i]);
    }

    int i=0;
    while(i<=n-cnt1)
    {
        nums[i]=temp[i];
      i++;
    }
    while(i<n)
    {
        nums[i]=zeroes[i];
        i++;
    }


}

class NextGreater {
public:
    // vector<int> nextGeater(vector<int> & arr )
    // {
    //     vector<int> ans;
    //     int n = arr.size();
    //     stack<int> st;
    //     ans[n-1]=-1;
    //     st.push(arr[n-1]);
    //     int i= n-2;
    //
    //     while(i>=0)
    //     {
    //         if(arr[i]<=st.top())
    //         {
    //             ans[i] = st.top();
    //             st.push(arr[i]);
    //         }
    //
    //         else if(arr[i]>st.top())
    //         {
    //             while(arr[i]>st.top())
    //             {
    //               st.pop();
    //             }
    //             if(st.empty()==true)
    //             {
    //               st.push(arr[i]);
    //               ans[i]=-1;
    //             }
    //             if(ans[i]!=-1)
    //             {
    //                 ans[i]=st.top();
    //             }
    //         }
    //         i--;
    //     }
    //     return ans;
    // }

    vector<int> nextGreater(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1);  // Initialize ans with -1 values
    stack<int> st;
    st.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && arr[i] > st.top()) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    return ans;
}
    int find_index(vector<int> &nums1 , int & target)
    {
      map<int, int> mp;
      int i=0;
      for(auto it: nums1)
      {
        mp[it]=i;
        i++;
      }

      return mp[target];
    }



    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v =  nextGreater(nums2);
         int size_of_ans = nums1.size();
         vector<int> ans (size_of_ans , 0);
        for(int i=0;i<size_of_ans;i++)
        {
          int ind = find_index(nums2 , nums1[i]);
          ans[i] = v[ind];
        }

        return ans;

    }

};


vector<pair<int, int> > left_max(vector<int> &arr)
{
    int size = arr.size();
    int maxi = INT_MIN;
    vector<pair<int,int>> ans;
    int j=-1;
    //this j  is imp , it will store the index of max element in left
    // whenever we find some new element we change it otherwise it goes forward
    // with same value
    for(int i=0 ;i<size ; i++ )
    {
      if(maxi<arr[i])
      {
           j = i;
      }
        maxi = max(maxi , arr[i]);
        pair<int,int> p = make_pair(maxi , j);
        ans.push_back(p);
    }

    return ans;
}

vector<pair<int, int>> right_max(vector<int> &arr)
{
    int size = arr.size();
    int maxi = INT_MIN;
    vector<pair<int,int>> ans;
    int j= -1;
    //this j  is imp , it will store the index of max element in left
    // whenever we find some new element we change it otherwise it goes forward
    // with same value
    for(int i=size-1 ;i>=0 ; i-- )
    {
      if(maxi<arr[i])
      {
           j = i;
      }
        maxi = max(maxi , arr[i]);
        pair<int,int> p = make_pair(maxi , j);
        ans.push_back(p);
    }

    return ans;
}
vector<int> rightt_max(vector<int> &arr)
{
    int size = arr.size();
    int maxi = INT_MIN;
    vector<int> ans(size , -1);
    for(int i=size-1 ; i>=0 ; i-- )
    {
        maxi = max(maxi , arr[i]);
        ans[i]=maxi;
    }

    return ans;
}
// 4 3 6 1



int main()
{
  // vector<int> nums1= {2,4};
  vector<int> nums2= { 4,11,0,8,2,5};

  // NextGreater obj1;

vector<pair<int,int>> ans = right_max(nums2);
  for(auto it: ans)
  {
    cout<<it.first<<" "<<it.second<<endl;
  }
  return 0;

}

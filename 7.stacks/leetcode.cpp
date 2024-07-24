#include <bits/stdc++.h>
using namespace std;

// TC = O(n2)
class histogram_On2 {
public:
    int next_smaller( vector<int>&arr , int ind , int size)
    {

        int j= ind;
        int ans;
        while(j<size)
        {
            if(arr[j]<arr[ind])
            {
                ans=j;
                break;
            }
            else
                ans= size;
            j++;
        }
        return ans;
    }

    int prev_smaller(vector<int>&arr , int ind, int size)
    {
        int j=ind;
        int ans;
        while(j>=0)
        {
            if(arr[j]<arr[ind])
            {
                ans=j;
                break;
            }
            else
                ans=-1;
            j--;
        }
        return ans;
    }
//NSI = Next smaller index
// PSI = previous smaller index
    int find_area(vector<int>&arr , int ind)
    {
        int size = arr.size();
        int NSI = next_smaller(arr,ind, size);
        int PSI = prev_smaller(arr, ind , size);
        int ans;
        ans = arr[ind]* ( abs(NSI - PSI) -1);
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {



        int size = heights.size();
        int maxi = INT_MIN;
        int i=0;
        while(i<size)
        {
            int area = find_area(heights , i);
            maxi = max(area , maxi);
            i++;
        }
        return maxi;

    }
};


class histogram_On {
public:
vector<int> next_smaller(vector<int>& arr , stack<int> &st , int size)
{
  vector<int> ans(size, -1);
  st.push(size-1);
  ans[size-1]= size;
  for(int i=size-2;i>=0;i--)
  {
    if(arr[i]<=arr[st.top()])
    {
      while(!st.empty()&& arr[i]<=arr[st.top()])
      {
        st.pop();
      }
      if(st.empty())
      {
        ans[i]=size;
      }
      else
        ans[i]=st.top();
    }
    else
      ans[i]=st.top();
    st.push(i);
  }

  return ans;
}

vector<int> prev_smaller(vector<int>& arr , stack<int> &st , int size)
{
  vector<int> ans(size, -1);
  st.push(0);
  ans[0]= -1;
  for(int i=1;i<size;i++)
  {
    if(arr[i]<=arr[st.top()])
    {
      while(!st.empty()&& arr[i]<=arr[st.top()])
      {
        st.pop();
      }
      if(st.empty())
      {
        ans[i]=-1;
      }
      else
        ans[i]=st.top();
    }
    else
      ans[i]=st.top();
    st.push(i);
  }

  return ans;
}



    int largestRectangleArea(vector<int>& heights) {

        int size  = heights.size();
        stack<int>st;

        //make the next smaller array
        vector<int>NS_array = next_smaller(heights , st , size);

        //clear the stack , make it empty for next usage
        while(!st.empty())
            st.pop();

        // make the prev smaller array
        vector<int> PS_array = prev_smaller(heights , st , size);


        int maxi = INT_MIN;
        int ind=0;
        while(ind<size)
        {
            int area;
            area = heights[ind] * ( abs(NS_array[ind] - PS_array[ind]) -1);
            maxi = max(area , maxi);
            ind++;
        }
        return maxi;

    }
};

//same as above , but without any extra funtion
// class histogram_On //with no extra functio
// {
// public:
//
//     int largestRectangleArea(vector<int>& heights) {
//
//         int size  = heights.size();
//         stack<int>st;
//
//         //make the next smaller array
//         vector<int> NS_array(size, -1);
//
//         st.push(size-1);
//         NS_array[size-1]= size;
//         for(int i=size-2;i>=0;i--)
//         {
//          if(heights[i]<=heights[st.top()])
//          {
//              while(!st.empty()&& heights[i]<=heights[st.top()])
//             {
//               st.pop();
//             }
//             if(st.empty())
//             {
//               NS_array[i]=size;
//             }
//              else
//                NS_array[i]=st.top();
//           }
//             else
//               NS_array[i]=st.top();
//          st.push(i);
//          }
//
//         //clear the stack , make it empty for next usage
//         while(!st.empty())
//             st.pop();
//
//         // make the prev smaller array
//           vector<int> PS_array(size, -1);
//           st.push(0);
//           PS_array[0]= -1;
//           for(int i=1;i<size;i++)
//           {
//             if(heights[i]<=heights[st.top()])
//             {
//               while(!st.empty()&& heights[i]<=heights[st.top()])
//               {
//                 st.pop();
//               }
//               if(st.empty())
//               {
//                PS_array[i]=-1;
//               }
//               else
//                 PS_array[i]=st.top();
//             }
//             else
//               PS_array[i]=st.top();
//             st.push(i);
//           }
//
//
//         int maxi = INT_MIN;
//         int ind=0;
//         while(ind<size)
//         {
//             int area;
//             area = heights[ind] * ( abs(NS_array[ind] - PS_array[ind]) -1);
//             maxi = max(area , maxi);
//             ind++;
//         }
//         return maxi;
//
//     }
// };


// TC= O(n) & SC = 0(2n)
class Min_stack{
public:

};

// TC= O(n) & SC = 0(n)  .....min stack formula
class Mi_stack{
public:

};
class Solution {
public:
    int minOperations(vector<string>& logs) {

        stack<string> st;

        int n = logs.size();
        int i = 0;
        st.push("mains");
        while( i < n)
        {
            if(logs[i] == "../")
            {
                if(!st.empty() && st.top()!="mains")
                    st.pop();
            }

            else if(logs[i] == "./")
                continue;

            else
            {
                st.push(logs[i]);
            }

            i++;
        }

        int size = st.size();
        if(size==0)
            return size;

        return size-1;


    }
};
int main()
{
  cout<<(2/5);


    return 0;
}

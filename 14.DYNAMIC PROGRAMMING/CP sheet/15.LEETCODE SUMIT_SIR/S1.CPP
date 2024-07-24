#include <bits/stdc++.h>
using namespace std;


// LEETCODE 11 ( approach 1 greedy)
int maxArea(vector<int>& height) {

int size = height.size();
if(size == 1 || size == 0)
return 0;

int last = size-1;
int first = 0;

int maxi = INT_MIN;



// we are going to move the pointer , until a distance of
while(first<last)
{

int value = min(height[first] , height[last]) *(last-first);
maxi = max(value , maxi);

if(height[first] <= height[last])
  first +=1;
else if(height[first] > height[last])
  last-=1;
}
return maxi;
}

// LEETCODE 11 ( approach 2 leftMax and rightMAX)
void maxArea2(vector<int>& height) {

  int size = height.size();
  // if(size == 1 || size == 0)
  //   return 0;

  vector<pair<int,int>>leftMAX;


// making of leftMAX
  leftMAX.push_back({-1,-1});
  int maxi = height[0]; // val
  int index = 0; // index

  for(int i=1;i<size;i++)
  {
      leftMAX.push_back({maxi,index});
      if(maxi < height[i])
      {
        maxi = height[i];
        index = i;
      }
  }

  vector<pair<int,int>>rightMAX(size);
  //making of rightMAX
  rightMAX[size-1] = {-1,-1};
  int rmaxi = height[size-1]; // val
  int rindex = size-1; // index

  for(int i= size-2;i>=0;i--)
  {
    rightMAX[i] = {rmaxi,rindex};
    if(rmaxi < height[i])
    {
      rmaxi = height[i];
      rindex = i;
    }
  }

  int ans = INT_MIN;
  for(int i=0;i<size;i++)
  {
    int l = leftMAX[i].first;
    int l_index = leftMAX[i].second;

    int r = rightMAX[i].first;
    int r_index = rightMAX[i].second;

    int val = min(l,r)*(r_index - l_index);

    ans = max( ans , val);

  }
  return ans;

}

int main()
{
  vector<int> a = {1,8,6,2,5,4,8,3,7};
  maxArea2(a);
  return 0;
}

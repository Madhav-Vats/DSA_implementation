#include <bits/stdc++.h>
using namespace std;


pair<pair<int,int> , int> ManhattanDistance(vector<vector<int>>&points , int exclude)
{
  int n = points.size();

  pair<int,int> maxSum = {-1 , INT_MIN} , minSum= {-1 ,INT_MAX} , maxDiff= {-1 , INT_MIN} , minDiff= {-1 ,INT_MAX};
  int currDiff , currSum;

  vector<int>Sum;
  vector<int>Diff;

  for(int i=0;i<n;i++)
  {
      if(i == exclude) continue;
    currSum = points[i][0] + points[i][1];
    currDiff = points[i][0] - points[i][1];   // dont use abs()

    maxSum = (currSum > maxSum.second) ? make_pair(i , currSum) : maxSum;
    minSum = currSum < minSum.second ? make_pair(i , currSum): minSum;
    maxDiff = currDiff > maxDiff.second ? make_pair(i , currDiff) : maxDiff;
    minDiff = currDiff < minDiff.second ? make_pair(i , currDiff) : minDiff;
  }

  int manHatMax = 0;
  pair<int,int>PP;

  if((maxSum.second - minSum.second) > (maxDiff.second - minDiff.second))
  {
    manHatMax = maxSum.second - minSum.second;
    PP = {maxSum.first , minSum.first};
  }
  else
  {
    manHatMax = maxDiff.second - minDiff.second;
    PP = {maxDiff.first , minDiff.first};
  }


  return {PP , manHatMax};
}
    int minimumDistance(vector<vector<int>>& points) {

        // exclude point aat -1 index at first and find which pair gives the max Dist
        // then exlude them each time and check after whose removal
        // you can get the minDistance
        auto MaxPair = ManhattanDistance(points , -1).first;
        int i = MaxPair.first;
        int j = MaxPair.second;

        return min(ManhattanDistance(points , i).second , ManhattanDistance(points , j).second);

    }
};

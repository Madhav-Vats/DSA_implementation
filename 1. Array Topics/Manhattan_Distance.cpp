#include <bits/stdc++.h>
using namespace std;

pair<pair<int,int> , int> ManhattanDistance(vector<vector<int>>&points)
{
  int n = points.size();

  pair<int,int> maxSum = {-1 , INT_MIN} , minSum= {-1 ,INT_MAX} , maxDiff= {-1 , INT_MIN} , minDiff= {-1 ,INT_MAX};
  int currDiff , currSum;

  vector<int>Sum;
  vector<int>Diff;
  // for(int i=0;i<n;i++)
  // {
  //   currSum = points[i][0] + points[i][1];
  //   currDiff = points[i][0] - points[i][1];
  //
  //   Diff.push_back(currDiff);
  //   Sum.push_back(currSum);
  // }
  //
  // for(int i=0;i<n;i++)
  // {
  //   cout<<Sum[i]<<" ";
  // }
  // cout<<endl;
  // for(int i=0;i<n;i++)
  // {
  //   cout<<Diff[i]<<" ";
  // }
  // cout<<endl;

  for(int i=0;i<n;i++)
  {
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

int main()
{
  vector<vector<int>>points  = {{3,10},{5,15},{10,2},{4,4}};

  auto ansi  = ManhattanDistance(points);

  cout<<"Manhattan Dist MAx "<<ansi.second<<endl;
  cout<<" Indices which are the reason "<<ansi.first.first<<" "<<ansi.first.second;

  return 0;


}

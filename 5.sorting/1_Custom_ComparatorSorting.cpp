#include<bits/stdc++.h>
using namespace std;

// sorting using custom comparator ( for vector of int)

void sortt(vector<int>&v)
{
  sort(v.begin() , v.end() ,  [&](const &a , const&b)
                                    {return a < b;}
  );
}


void sortDescending(vector<int>&v)
{
  sort(v.begin() , v.end() ,  [&](const &a , const&b)
                                    {return a > b;}
  );
}


// sorting using custom comparator ( in 2d array )
// on the basis of 2nd element of the each row
sorttMatrix(vector<vector<int>>&mat)
{
  sort(mat.begin() , mat.end() , [&](vector<int>&a , vector<int>&b)
                                {
                                  return a[1] < b[1];
                                }
);
}

// ----------- Advanced Form ------------  using auto

// always use ( auto const& ) int the comparator

sorttMatrixAd(vector<vector<int>>&mat)
{
  sort(mat.begin() , mat.end() , [&](auto &a , auto const &b)
                                {
                                  return a[2] < b[2];
                                }
);
}

/*
[1,  0,  1]
[2, -1 , 3]
[9, -2 , 9]
*/



void PrintArray(vector<int>&arr)
{
  for(auto &it: arr)
  {
    cout<<it<<" ";
  }
  cout<<endl;
}


void PrintMatrix(vector<vector<int>>&mat)
{
  for(auto &it: mat)
  {
    for(auto &i:it)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
}







int main()
{
  vector<int>v = {5 ,0,4,-1,6,2};

  vector<vector<int>>mat = {{1,  0,  1},{2, -1 , 3},{9, -2 , 9}};

  sortDescending(v);

  sorttMatrixAd(mat);

  PrintArray(v);
  PrintMatrix(mat);

}

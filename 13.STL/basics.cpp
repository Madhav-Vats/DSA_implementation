#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int fun(int &a , int&b)
{
  return a*b;
}

int main() {

  vector<int>arr = {1,2,3,4,5};

/////////////////////////////////////////////////////////////////////////
  //sum of all elements , using an iterator with a vector
    vector<int>:: iterator itt ;
    itt = arr.begin();

    int total = 0;

    for(int i=0;i<5;i++)
    {
      total += *itt;
      itt++;
    }

    cout<<" sum of all elemements = "<< total<<endl;


            //  OR   //

int accum  = 0;
std:: accumulate(arr.begin() , arr.end() , accum);   // not working
cout<<accum<<endl;
/////////////////////////////////////////////////////////////////////////

// creating a vector storing the product of adjacent elements

  int ans =0;
  int result[5];
  int result2[5];

  // creating a vector storing the product of adjacent elements
  std:: adjacent_difference(arr.begin() , arr.end() ,  result, fun );

  //using lambda function
  // std:: adjacent_difference(arr.begin() , arr.end() ,  result2, [](int a , int b){ return a*b} );

  for(auto it: result)
    cout<<it<<" ";

////////////////////////////////////////////////////////////////////////
return 0;
}

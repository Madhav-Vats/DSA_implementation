#include<bits/stdc++.h>
#include<string>
using namespace std;


int main()
{
  vector<int>arr = {1,2,3,4,5,6,7,8,9,10};

  int idx = binary_search(arr.begin() , arr.end() , 11);
  cout<<idx<<endl;
}

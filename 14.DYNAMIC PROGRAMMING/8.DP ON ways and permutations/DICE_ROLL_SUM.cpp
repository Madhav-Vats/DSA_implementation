#include<bits/stdc++.h>
using namespace std;

int frec( int ind , int F ,  int target)
{

  if(target == 0)
    return 1;

  if(ind  == 0)
  {
    if(target <=F)
      return 1;
    else
      return 0;
  }

  int count  = 0;

  for(int i=1;i<=F ;i++)
  {
    int ans = 0;
    if(i<=target)
    {
      ans= frec( ind -1 , F , target - i);
    }

    count+= ans;
  }

  return count;
}

int FindNUM( int &D , int &F , int &S)
{
  int ans = frec( D-1 , F , S);
  return ans;

}


int main()
{
  // number of dice
  int D = 2;

  // number of faces
  int F = 5;

  int SUM = 10;

  int ans = FindNUM(D , F , SUM);
  cout<<ans<<endl;
}

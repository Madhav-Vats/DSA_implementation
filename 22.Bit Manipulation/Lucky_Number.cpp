#include<bits/stdc++.h>
using namespace std;

// input len only in the function and take the whole number as an array of char
// hardcoded to 7 an d4 only

int findPosition(int len)
{
  char arr[20];

  for(int i=0;i<len;i++)
  {
    cin>>arr[i];
  }

  // number of strings smaller than giving string(number)
  int ans1 = pow(2 ,len) - 2;  // we will not use this

  // or you can do it without using pow function
  // USE LEFT SHIFT , which also means the same
  int ans = (1<<len)  - 2;

  //finding the count of numbers lesser than given num , but having same length
  // 1. for this , we need to find 7 from right everytime
  // 2. and add some value to ans , accordingly

  for(int i=len-1 ;i>=0;i--)
  {
    if(arr[i] == '7')
    {
      int addVal = (1<<i);       // or pow(2, i)
      ans += addVal;
    }
  }

  ans += 1;
  return ans;

}



int main()
{
  int a = 4;
  int b = 7;


  int ans = findPositionAny(3);
  cout<<ans<<endl;

}



// -------------- Consider it as Wrong -------------------

// int findPositionAny(int len)
// {
//
//   // 4 , 7 , 8 are present
// 
//   char arr[20];
//
//   for(int i=0;i<len;i++)
//   {
//     cin>>arr[i];
//   }
//
//   // number of strings smaller than giving string(number)
//   int temp = pow(3 , len) - 3;
//   int ans = temp/2;
//
//   // first finding the number of diffn char in the given array
//   int variety  = 3;
//
//   char mini = '4';
//
//   for(int i=len-1 ; i>=0; i--)
//   {
//     if(arr[i] != '4')
//     {
//       int addVal = pow(3, i);
//       ans += addVal;
//     }
//   }
//
//
//   return (ans + 1) ;
//
// }

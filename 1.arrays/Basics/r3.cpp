//majority element
#include <bits/stdc++.h>
using namespace std;

int majority_element( vector<int> &arr)
{

  //moore's voting algorith
  int n=arr.size();
  int i,j=0;
  int cnt=0;
  int counter=0;
  int element;
  for(int i=0;i<n;i++)
  {

      if(cnt==0)
      {
        cnt++;
        element=arr[i];
      }
      else if(arr[i]==element)
      {
        cnt++;
      }
      else
      {
        cnt--;
      }
      }

  for(int k=0;k<n;k++)
  {
    if (arr[k]=element)
    counter++;
  }
  if(counter>=n/2)
  {
    return element;
  }


return -1;

// /*
// brute force code
// check for each elements counter
// and if it is greater htat n/2 return the element
// */



// int WR_majority_element( vector<int> &arr)
// {
//   int n=arr.size();
//     for(int i=0;i<n;i++)
//     {
//       int cnt=0;
//         for(int j=0;j<n;j++)
//         {
//           if(arr[j]==arr[i])
//           {
//             cnt++;
//           }
//         }
//         if(cnt>=n/2)
//         {
//           return arr[i];
//         }
//     }
//
//   return -1;
// }
//
//
//
}





int main()
{
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

vector<int> a={2,2,3,3,1,1,2,2,2};
int ans= WR_majority_element(a);
cout<<ans;
return 0;
}

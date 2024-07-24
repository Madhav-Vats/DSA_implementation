// given a string , which i used as array while insertion
// u are given maximum number of replacements and favorite char
// find the longest subarray , where u do replacements and make all the elements as ur favorite character

/*
INPUT

15 -- length of string
yamatonadeshiko -- input string
10  -- number of ideas / test cases
1 a  -- first testcase , --> u will replace the char at index 2 , to get a max subarrayof size 3
2 a -- replace indexes 2 , 4 , to get max size = 4
3 a
4 a-- replace ,index 2,4,5,6 to get max size = 7
5 a
1 b
2 b
3 b
4 b
5 b

*/

#include<bits/stdc++.h>
using namespace std;

int afterPaintingMaxConsecutive(int m ,int n , char element, vector<char>&arr )
{
  // index of first element
  // int firstIndex = 0;
  // for(int i=0;i<n;i++)
  // {
  //   if(arr[i] == element)
  //   {
  //     firstIndex = i;
  //     break;
  //   }
  // }

  // if(arr[0]!= element && firstIndex == 0)
  // {
  //   return m;
  // }

  int i = 0;  // we will start from the first occurence of
  int j = 0;  // the given element

  // count of place where u can fit the new elements
  int currFit_in = 0;

  int maxConsecutive = INT_MIN;

  int temp = 0;

  while(j<n)
  {
    // if(arr[i] ==element)
    //   dont do anything but consider it in the size INPORTANT

    if(arr[j] != element)
    {
      currFit_in ++;
    }

    while(i<=j && currFit_in > m)
    {
      if(arr[i] != element)
        currFit_in--;

      i++;
    }

    temp = j-i+1;

    maxConsecutive = max(maxConsecutive , temp);

    j++;
  }


  return maxConsecutive;
}


int main()
{
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    #endif
  }

  int n;
  cin>>n;

  //we can get it as an array in place of string
  vector<char>arr(n);

  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  int k;
  cin>>k;

  while(k--)
  {
    int m;
    cin>>m;

    char element;
    cin>>element;

    int ans = afterPaintingMaxConsecutive( m , n ,element, arr);
    cout<<ans<<endl;

  }


  return 0;
}

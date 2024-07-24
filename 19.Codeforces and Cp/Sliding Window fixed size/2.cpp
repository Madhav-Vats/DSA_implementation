//--------------------------------------------------------//
// find the (numberOfpeak+1) in any subarray of given size in the array;
// and also if two subarrays have same number of peaks , return the first index
//of that subarray whole left index is minimum

#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n ,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    //-----------------------------------------------------------
    // Finding the maxPeaks and the minVal for left index for same numPeaks

    int maxPeaks =0;
    // map that will store the peak indexes
    unordere_map<int,int>PeakIndexes;  // index , count ( count can only be 1)

    //First sliding Window
    for(int i =0;i<k;i++)
    {
      if(i==0 || i==k-1)
        continue; // bcoz we cant check them for peak elements

      if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
      {
        maxPeaks++;
        PeakIndexes[i]++;  // will store index as a key
      }
    }

    //this will store the 2nd answer
    int miniIndex = 0;

    // edge case
    if(k == n)
    {
      cout<<maxPeaks<<" ";
      cout<<miniIndex+1<<endl;
      return; // break for this test case
    }


    int currPeaks = maxPeaks;

    int l = 1 ; //  left most index for currSliding Window
    int r = k ;// right most index for currSliding Window
    int j = k; // next element

    //checking other Sliding windows
    for(int ind = 1; ind<=n-k;ind++)  // n-k remaining sliding windows
    {
      if(ind==l || j == r)
        continue;

      //Removing prevElement
        //checking whether it was a peak or not
      if(PeakIndexes.find(ind-1) != PeakIndexes.end())  // found
      {
        //it was a peak , so , decrease the currPeak counter
        //and remove it from the map
        currPeaks -= 1;
        PeakIndexes.erase(ind-1);
      }


      //Adding nextElement  // j is the next element index
      if(arr[j] > arr[j-1] && arr[j] < arr[j+1])
      {
        //increase the currPeak counter
        currPeaks++;
        // entry in the map
        PeakIndexes[j]++;
      }

      if(currPeaks > maxPeaks)
      {
        maxPeaks = currPeaks;
        //changin the miniIndex
        miniIndex = i
      }


    }




  }
}

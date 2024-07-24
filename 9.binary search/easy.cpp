#include <bits/stdc++.h>
#include <vector>
using namespace std;

// class Solution_singleElement {
// public:
//   void loop_singleNonDuplicate(vector<int>& nums) {
//       int n = nums.size();
//       bool ans=true;
//       int val;
//       int i=0;
//       for(i ;i<n-1;i+=2)
//       {
//         if(nums[i]==nums[i+1])
//           ans= true;
//         else
//         {
//           ans=false;
//           break;
//         }
//       }
//       if(ans==false)
//       {
//         cout<<"element found at "<<i<<" and its value"<< nums[i];
//       }
//     }
//
//
//   int singleNonDuplicate(vector<int>& nums) {
//   int n= nums.size();
//   if(n==1)
//     return nums[0];
// // now if we will use range 0 to n , we will face  proble for first and last index elements
// // so we will settle them before BS
//
//   if(nums[0]!= nums[1])
//     return nums[0];
//   if(nums[n-1]!= nums[n-2])
//     return nums[n-1];
//
//
//   int low = 1;
//   int high = n-2;
//   int mid;
//
//        // where each ans or you can say mid will be stored ;
// //array  1 1 2 2 3 4 3   ( if mid = 3 , which is odd ,then the arr[mid]==arr[mid -1])
// //index  0 1 2 3 4 5 6   (therefore the left part of mid is in correct pattern and there is a need to check for right )
// //if element is not present in the  array then the pattern is
// //( same elements are at positions = even-odd)
// // so if this condition is not true then
// //means at that part of array some disturbancy is present ( means our single element)
//
//
//   while (low <=high)
//   {
//     mid =  (low+high)/2;
//
//     if(nums[mid]!=nums[mid-1]  && nums[mid]!=nums[mid+1]) // condition of single element ( as the array is sorted )
//       return nums[mid];
//     if(nums[mid]==nums[mid-1] && mid%2 ==1  || nums[mid]==nums[mid+1] && mid%2 ==0 ) //that means even-odd pair
//         low = mid+1;
//
//     else
//       high = mid-1;
//
//     }
//
//   }
// };
//
// class Solution_kokoBanana {
// public:
//     bool possible(vector<int>& piles  , int eating_rate ,  int threshold)
//     {
//         int size = piles.size();
//         long long sum=0;
//         for(int i=0; i<size ; i++)
//         {
//             sum+=ceil( double(piles[i]) / double(eating_rate));
//         }
//         if (sum<= threshold)
//             return true;
//
//         return false;
//     }
//
//
//     // looping will give us TLE ( time limit exceeded)
//     int loop_minEatingSpeed(vector<int>& piles, int h) {
//         int max_piles = *max_element(piles.begin(), piles.end());
//         for(int i=1;i<=max_piles;i++)
//         {
//             if( possible(piles , i ,h )== true)
//                 return i;
//         }
//
//         return -1;
//
//     }
//
//     int minEatingSpeed(vector<int>& piles, int h){
//         int low = 1 ; // can't be zero therwise inf , error
//         int high = *max_element(piles.begin(), piles.end());
//         int ans=-1;
//
//
//         while(low<=high)
//         {
//             int  mid =  (low+high)/2;
//             if(possible(piles , mid , h)==true)
//             {
//                 ans= mid;
//                 high = mid-1;
//             }
//             else
//                 low= mid+1;
//         }
//
//         return ans;
//
//         }
// };
//
// bool extra_possible(vector<int>& weights, int days , int capacity )
// {
//     int size = weights.size();
//     int i=0;
//     int cnt_days=days;
//     int sum = 0;
//     while(i<size && cnt_days!=0)
//     {
//       sum += weights[i];
//       if(i==size-1)
//         cnt_days--;
//       if(sum > capacity )
//       {
//           i=i-1;
//           cnt_days--;
//           sum=0;
//       }
//       i++;
//     }
//     if(cnt_days==0 && i==size)
//       return true;
//     return false ;
// }
//
//
// // bool possible(vector<int>& weights, int days , int capacity )
// // {
// //     int size = weights.size();
// //     int i=0;
// //     int cnt_days=days;
// //     int sum = 0;
// //     while(i<size-1 && cnt_days!=0)
// //     {
// //       if(i== size -2)
// //       {
// //         sum+=weights[i+1];
// //         if(sum>capacity)
// //           cnt_days-=2;
// //         else
// //           cnt_days-=1;
// //       }
// //       if(sum <=capacity )
// //       {
// //         sum+= weights[i];
// //       }
// //       if( (sum+ weights[i+1]) > capacity )
// //       {
// //           cnt_days--;
// //           sum=0;
// //       }
// //       i++;
// //     }
// //     if(cnt_days==0 && i==size-1)
// //       return true;
// //     return false ;
// // }
//
// int possible(vector<int>& weights, int capacity )
// {
//     int days = 1; //First day.
//     int load = 0;
//     int n = weights.size(); //size of array.
//     for (int i = 0; i < n; i++) {
//         if (load + weights[i] > capacity) {
//             days += 1; //move to next day
//             load = weights[i]; //load the weight.
//         }
//         else {
//             //load the weight on the same day.
//             load += weights[i];
//         }
//     }
//     return days;
// }
//
//
// int findKthPositive(vector<int>& arr, int k) {
//         int maxi = *max_element(arr.begin() , arr.end());
//         vector<int> temp;
//         int size = arr.size();
//         for(int i =0;i<maxi ;i++)
//             temp[i]=i;
//         int xor1=0;
//         int i=0;
//         int j=0;
//         while(i<size)
//         {
//             temp[arr[i]]=0;
//         }
//
//         vector<int> arr3;
//         for(int i=0;i<maxi ; i++)
//         {
//             if(temp[i]!=0)
//                 arr3.push_back(temp[i]);
//         }
//         return arr3[k-1];
//
//     }
//
//
//     class Solution {
//     public:
//         bool possible(vector<int>& bloomDay , int days , int m, int k )
//         {
//             int cnt =0;
//             int noOF_bouquets = 0;
//             int n= bloomDay.size();
//             for(int i=0 ; i<n ; i++)
//             {
//                 if(bloomDay[i]<days)
//                 {
//                     cnt++;
//                 }
//                 else
//                 {
//                     noOF_bouquets= (cnt/k);
//                     cnt=0;
//                 }
//             }
//              noOF_bouquets += (cnt/k);
//
//             if (noOF_bouquets>=m)
//                 return true ;
//
//             return false;
//
//         }
//
//         int minDays(vector<int>& bloomDay, int m, int k) {
//
//             int mini = *min_element(bloomDay.begin(), bloomDay.end());
//             int maxi = *max_element(bloomDay.begin(), bloomDay.end());
//
//             int n= bloomDay.size();
//
//             if(n<(m*k)) // number of flowers present are less than required
//                 return -1;
//             else
//             {
//               for(int i=mini; i<=maxi ; i++)
//               {
//                 if(possible(bloomDay, i, m, k)==true)
//                     return i;
//               }
//               return -1;
//             }
//
//     };



int main()
{
  int n;
  n =20;

  // for(int mask = 0; mask < (1<<n) ; mask++)
  // {
  //   cout<<" for mask  = "<<mask<<endl;
  //   for(int sub = mask; sub;sub = (sub-1)&mask)
  //   {
  //     cout<<bitset<8>(sub).to_string()<<endl;
  //   }
  //
  //   cout<<endl<<endl;
  // }

  // cout<<bitset<8>(n).to_string()<<endl;
  //
  // cout<<bitset<8>(n-1).to_string()<<endl;


  cout<<(~n + 1);





  return 0;
}

//
// int findDays(vector<int> &weights, int cap) {
//     int days = 1; //First day.
//     int load = 0;
//     int n = weights.size(); //size of array.
//     for (int i = 0; i < n; i++) {
//         if (load + weights[i] > cap) {
//             days += 1; //move to next day
//             load = weights[i]; //load the weight.
//         }
//         else {
//             //load the weight on the same day.
//             load += weights[i];
//         }
//     }
//     return days;
// }

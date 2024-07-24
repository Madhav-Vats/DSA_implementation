#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int target) {
    int n=arr.size();
    int l=0,r=n-1,mid;

    while(l<=r){
        mid=l+(r-l)/2;
        if(arr[mid]==target)return mid;

          else if(arr[mid]>=arr[l]){
            if(target>=arr[l] && target<=arr[mid])r=mid-1;
            else l=mid+1;
        }
        else {
            if(target>=arr[mid] && target<=arr[r]){
                l=mid+1;
            }else r=mid-1;
        }

    }
    return -1;
}

int main()
{

  vector<int>arr = {4,5,6,7,0,1,2};

  int n = arr.size();
  int target = 3;

  int ans = search(arr , target);


  cout<<ans<<endl;

}

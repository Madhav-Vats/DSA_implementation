#include <bits/stdc++.h>
#include <vector>

// #include <cmath>
using namespace std;

//HASHING DATA TABLES
bool hashtable[1000];
unordered_map<int, int> hashmap;
int hash_2d_TABLE[1000][2]={{0,0}};


// INSERTING FUNCTIONS

void insert_hash_2d_TABLE(int element)
{
  if (element >=0)
  {
    hash_2d_TABLE[element][0]++;
  }
  if (element<0)
  {
    int p=abs(element);
    hash_2d_TABLE[element][1]++;
  }

}

void insert_hashmap( int  *arr , int size)
{
   for(int i=0;i<size;i++)
  {
    hashmap[arr[i]]++;
  }
}

void insert_hashtable( int *arr , int size)
{
  for(int i=0;i<size;i++)
  {
    hashtable[arr[i]]=1;
  }
}


void BB_Sum_of_twoelements_is_N(int *arr , int size , int target_sum)
{
  insert_hashtable(arr , size);
  for(int i=0;i<size;i++)
  {
    int extra = target_sum-arr[i];
    if(hashtable[extra]==1)
    {
      cout<<"pair exist";
      break;
    }
  }

}

void BBB_Sum_of_twoelements_is_N(int *arr , int size , int target_sum)
{
  insert_hashmap(arr , size);
  for(int i=0;i<size;i++)
  {
    int extra = target_sum-arr[i];
    if(hashmap[extra]==1)
    {
      cout<<"pair exist";
      break;
    }
  }

}

vector<int> nonrepetive_element( int *arr , int size)
{
  insert_hashmap(arr,size);
  vector<int> v;

  for(int i=0;i<size;i++)
  {
    if(hashmap[arr[i]]==1)
    {
      v.push_back(arr[i]);
    }
  }

  return v;
}


//using hashtable 2D matrix for both type of integers
int occurence_of_elements(int *arr ,int size)
{
  for(int i=0;i<size;i++)
  insert_hash_2d_TABLE(arr[i]);

  for(int i=0;i<size;i++)
  {
    if (arr[i] >=0)
    {
      cout<<arr[i]<<" : "<<hash_2d_TABLE[arr[i]][0]<<endl;
    }
    if (arr[i]<0)
    {
      cout<<arr[i]<<" : "<<hash_2d_TABLE[arr[i]][1]<<endl;

    }

  }
}

//for only positive integers using hashmaps
int OP_first_nonrepetive_element(int *arr ,int size)
{
  int ans=-1;
  insert_hashmap(arr, size);
  for(int i=0;i<size;i++)
  {
    if(hashmap[arr[i]]==1)
    {
      ans=arr[i];
      break;
    }
  }
}


int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);

#ifndef ONLINE_JUDGE
//freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

int arr[]={-1,-2,-2,-6,1,2,2,1,3,9,5,7,8,9};

int size = sizeof(arr)/sizeof(*arr);
cout<<size<<endl;

occurence_of_elements(arr,size);
return 0;
}

#include <bits/stdc++.h>
#include <vector>

// #include <cmath>
using namespace std;


//in this compiler e can not use vector if we are going to make value n as its size

int max( int a , int b)
{
  if(a>b)
  return a;
  else
  return b;
}
int min( int a , int b)
{
  if(a<b)
  return a;
  else
  return b;
}

void print(int *arr, int n)
{
  int i=0;
  cout<<"the array is --  ";
  while(i<n)
  {
    cout<<arr[i]<<" ";
    i++;
  }
}

int position(int *arr , int size , int element)
{
  int pos=0;
  for(int i=0;i<size;i++)
  {
    if(arr[i]==element)
    {
      pos=i;
      break;
    }
  }
  return pos;
}

void swap(int &elem1 ,int &elem2)
{
  int temp=elem1;
  elem1=elem2;
  elem2=temp;
}

void rev_full_array(int *arr , int n )
{
  int j=n-1;

  for(int i=0;i<n/2;i++)
  {
    swap(arr[i],arr[j]);
    j--;
  }
}

void rev_part_of_array(int *arr , int first , int last)
{
  int j=last-1;

  for(int i=first-1;i<last;i++)
  {
    if(i<j)
    {
      swap(arr[i],arr[j]);
      j--;
    }

    if (i==j)
    {
      break;
    }
  }
}

int len( int *arr)
{
  int size = sizeof(arr)/sizeof(*arr);
  return size;
}

void sort(int *arr, int n)
{
  for(int i=0;i<n;i++)
  {
    if(arr[i]>arr[i+1])
    {
      swap(arr[i],arr[i+1]);
    }
  }
}

int B_largestElement(int *arr, int n) {
    // Write your code here.
    //Brute force (after sorting the array )
    sort(arr,n);
    return arr[n-1];
    }

int OP_largestElement(int *arr, int n) {
    //Optimized soln
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}

void BB_Second_largestElement_Second_SmallestElement( int *arr ,int n) {
    // Write your code here.

             int max= INT_MIN;
        int min=INT_MAX;
        int sec_max= -1;
        int sec_min= INT_MAX;
        // finding the largest element
        for(int i=1;i<n;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        cout<<endl<<"largest--"<<max<<endl;

        for(int i=0;i<n;i++)
        {
            if(arr[i]<min)
            {
                min=arr[i];
            }
        }
                cout<<"Smallest--"<<min<<endl;


        int j=0;
        int k=0;
        while(j<n && k<n)
        {
            if(arr[j]<max && arr[j]>sec_max)
            {

                    sec_max=arr[j];

            }
             if(arr[k]>min && arr[k]<sec_min)
             {
                 sec_min=arr[k];
             }
            j++;
            k++;
        }
        cout<<"sec Largest-- "<<sec_max<<endl;
        cout<<"sec Smallest-- "<<sec_min<<endl;

}

void OP_Second_largestElement_Second_SmallestElement( int *arr ,int n)
{

  int max=INT_MIN;
  int sec_max=INT_MIN;
  int min= 3001 ;
  int sec_min=300;

  int i=0;
  int j=0;
  while(i<n && j<n)
  {
    if(arr[i]>max)
    {
      sec_max=max;
      max=arr[i];
    }

    if(arr[j]<min)
    {
      sec_min = min;
      min = arr[j];

    }
    i++;
    j++;

  }
  cout<<endl<<"largest--"<<max<<endl;
  cout<<"Smallest--"<<min<<endl;
  cout<<"sec Largest-- "<<sec_max<<endl;
  cout<<"sec Smallest-- "<<sec_min<<endl;


}

/*
int check_sorting( int *arr , int n)
{
  for(int i=0 ;i<n-1;i++)
  {
    if(arr[i]<arr[i+1])
    {
      return 1;
    }
    else if( arr[i]>arr[i+1])
    {return 0;}

  }
}

*/

void sort(vector<int> &arr, int n)
{
  for(int i=0;i<n;i++)
  {
    if(arr[i]>arr[i+1])
    {
      swap(arr[i],arr[i+1]);
    }
  }
}

void removeDuplicates(int *arr,int n) {
	// Write your code here.
	sort(arr,n);
	vector<int> unique;
	int i=0;
	while(i<n)
	{
		if(!unique.empty() || arr[i]!=unique.back())
		{
			unique.push_back(arr[i]);
		}
	}
	// return unique.size();
  for(auto i: unique)
  {
    cout<<i<<" ";
  }
  cout<<endl;


}

void sending_element_toend( int *arr , int size , int element)
{
  int temp = element;
  int pos=position(arr , size , element);
    for(int i=pos+1;i<size;i++)
    {
      arr[i-1]=arr[i];
    }
    arr[size-1]=temp;

}

void WR_removeDuplicates( int *arr , int size)
{
  int cnt=0;
  sort(arr, size);
  print(arr,size);
  for(int i=0;i<size;i++){

    if(arr[i]==arr[i+1])
    {
      sending_element_toend(arr,size, arr[i]);
      cnt++;
    }
  }
  int red_size=size-cnt;
  int temp[red_size];
  for(int i=0;i<red_size;i++)
  {
    temp[i]=arr[i];
  }
  print(temp,red_size);

}


void BB_leftrotate( int *arr , int n )
{
  int length = len(arr);
  int nums= n%length;
  vector<int> temp;
  for(int i=0;i<nums;i++)
  {
    temp.push_back(arr[i]);
  }
  for(int i=nums;i<n;i++)
  {
    arr[i-nums]=arr[i];
  }
  int j=0;
 for(int i=nums;i<n;i++)
  {
    arr[i]=temp[j];
    j++;
  }
}

void OP_leftrotate( int *arr , int n )
{
  int length = len(arr);
  int nums= n%length;
  // here nums are numbr of rotations


  rev_part_of_array(arr,1,nums);
  rev_part_of_array(arr, nums +1,length);
  rev_full_array(arr,length);

}



void OP_rigthrotate( int *arr , int n )
{
  int length = len(arr);
  int nums= n%length;
  // here nums are numbr of rotations


  rev_part_of_array(arr,1,length-nums);
  rev_full_array(arr,length);

}


void occurence_of_a_number(int *arr , int size , int element)

{

}



void Union(int *arr1 , int n1, int *arr2, int n2)
{
  vector<int> new_array;
  int i=0;
  int j=0;
  sort(arr1,n1);
  sort(arr2,n2);
  int m=max(n1,n2);
  while ( i<n1 && j<n2)
  {
    int value = min(arr1[i], arr2[j]);
    if(new_array.empty()==1 || new_array.back()!=value)
    {
      new_array.push_back(value);

    }
    i++;
    j++;

  }
  while (i<n1)
  {
    if(new_array.empty()==1 || new_array.back()!=arr1[i])
    {
      new_array.push_back(arr1[i]);

    }
    i++;
    j++;

  }
  while (j<n2)
  {
    if(new_array.empty()==1 || new_array.back()!=arr2[j])
    {
      new_array.push_back(arr2[j]);

    }
    i++;
    j++;

  }
  for( auto it: new_array)
  {
    cout<<it<<" ";
  }


}

void Sum_of_twoelements_is_N(int *arr , int size , int target_sum)
{
  for(int i=0;i<size;i++)
  {
    for(int j=i+1;j<size;j++)
    {
      if(arr[i]+arr[j]==target_sum)
      {
        cout<<"yes pair exist";
      }
    }
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



//using hashtable 2D matrix for both type of integers




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

// vector<int> vem= first_nonrepetive_element(arr,9);
// for(auto i:vem)
// {
//   cout<<i<<endl;
// }







 /*
unordered_map<int, int> order;

   // Mapping values to keys
   order[5] = 10;
   order[3] = 500;
   order[20] = 100;
   order[1] = 1;

   // Iterating the map and
   // printing ordered values
   for (auto i = order.begin(); i
        != order.end(); i++) {
       std::cout << i->first
                 << " : "
                 << i->second << '\n';
   }



  print(arr,n);
  cout<<endl;
  sort(arr,n);
  cout<<n<<endl;
  print(arr,n);
  cout<<endl;

  //sort(arr,n);

//OP_Second_largestElement_Second_SmallestElement(arr,n);
//bool j = check_sorting(arr,n);
 //cout<<endl<<j;
 //OP_rigthrotate(arr, 3);
//(arr, 3);
*/

  return 0;
}


// len is problem
// sort is problem

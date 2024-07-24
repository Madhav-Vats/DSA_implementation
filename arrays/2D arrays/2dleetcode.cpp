// You are given an m x n integer matrix matrix with the following two properties:
//

#include <bits/stdc++.h>
#include <vector>
using namespace std;


class Basic_2d_functions
{
public:
  vector<vector<int>> create_matrix(int rows , int coloumns)
  {
    vector<vector<int>> mat( rows,vector<int>(coloumns));
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<coloumns;j++)
      {
        cin>>mat[i][j];
      }
    }
    return mat;
  }
  //print a matrix

  void print_matrix(vector<vector<int>> &matrix)
  {

    int rows =matrix.size();
    int coloumns= matrix[0].size();
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<coloumns;j++)
      {
        cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
    }
  }
};


class making_Highly_sorted_matrix
{
public:
//specially for each row
void sort_vector(vector<int> &v)
{
  int size=v.size();
  for(int i=0;i<size;i++)
  {
    if(v[i]>v[i+1])
    {
      int temp =v[i];
      v[i]=v[i+1];
      v[i+1]=temp;
    }
  }
}
void sort_each_coloumn(vector<vector<int>> &matrix)
{
  int rows =matrix.size();
  int coloumns= matrix[0].size();

  for(int j=0;j<coloumns;j++)
    {
      vector<int>new_coloumn;
      for(int i=0;i<rows;i++)
      {
        new_coloumn.push_back(matrix[i][j]);
      }
      sort_vector(new_coloumn);
      for(int i=0;i<rows;i++)
      {
        matrix[i][j]=new_coloumn[i];
      }
    }
}

void sort_the_matrix(vector<vector<int>> &matrix)
{
  int rows=matrix.size();
  int coloumns=matrix[0].size();

  //sorting rows wise
  for(int i=0;i<rows;i++)
  {
      sort_vector(matrix[i]);
  }
  sort_each_coloumn(matrix);

}

};

  //sorting coloumn wise

class intervals_using_pairs
{

};
//check
class MERGE_USING_ERASE_APPROACH {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int rows=intervals.size();
        int coloumns = intervals[0].size();

        for(int i =0;i<rows;i++)
        {
            for(int j=0;j<coloumns;j++)
            {
                if(intervals[i][coloumns]<=intervals[i+1][0])
                {
                    //check if ith ka last is less or equal to i+1th ka first element
                    intervals[i][coloumns]=intervals[i+1][coloumns];
                    //erase the next element
                    intervals.erase(intervals.begin()+(i+1));

                }
            }

        }
        return intervals;

    }
};

class merge_intervals {
public:


    //---->   BRUTE FORCE SOLUTION WAS HARD TO UBDERSTAND

    // FOCUS ON IT LATER

    // OPTIMAL SOLN
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int rows=intervals.size();
        int coloumns = intervals[0].size();

        if(rows==1)
        {
            return intervals;
        }

              //sort the intervals based on their start value

        sort(intervals.begin(),intervals.end());
              //this will only sort the matrix , on the basis of first elements
              // [[3,7],[5,6]]b   ->  [[5,4],[3,7]]
              //although each intervals last element would be greater than the first one
              //but  in this problem the next intervals last eleent would be greater
              //than previous ones last element

        vector<vector<int>> merged_intervals;
        merged_intervals.push_back(intervals[0]);

        //if you don't want to write this line you can add this thing in the first if as
        // if( merged_intervals.empty()  || merged_intervals.back()[1] >= intervals[i][0])

        for(int i=0;i<rows;i++)
        {
            // if condition is true (overlap exists) -> merge the intervals
            if(merged_intervals.back()[1] >= intervals[i][0])
            {
                merged_intervals.back()[1]= max(merged_intervals.back()[1], intervals[i][1]);
            }

            // if not (overlapp doesn't exist)-> no merging
            else
            {
                merged_intervals.push_back(intervals[i]);
            }
        }
    return merged_intervals;
    }
};

//search in a matrix (highly sorted matrix)
class search_matrix {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows=matrix.size();
        int coloumns=matrix[0].size();

        int mark;
        int maximum = INT_MIN;
        for(int i=0;i<rows;i++)
        {
            if(matrix[i][0]<target)
            {
                if(matrix[i][0]>maximum)
                {
                    maximum=matrix[i][0];
                    mark=i;
                }
            }
        }
        for(int j=0;j<coloumns;j++)
        {
            if(matrix[mark][j]==target)
            {
                return true;
            }
        }

        return false;

    }
};

int main()
{
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
  #endif
}

int rows, coloumns=3;
Basic_2d_functions obj1;
making_Highly_sorted_matrix obj2;
vector<vector<int>> ans={{1 ,2 ,3},{ 4, 5, 6},{ 7, 8, 9}};
obj2.sort_the_matrix(ans);
obj1.print_matrix(ans);
// obj2.sorted_matrix(ans);
// obj1.print_matrix(ans);
// vector<vector<int>> ans =transpose(matrix1);
return 0;

}

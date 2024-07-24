#include <bits/stdc++.h>
#include <vector>
using namespace std;

//input matrix
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

void print_matrix(vector<vector<int>> matrix)
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
class set_zeroes_class
{
public:
void mark_rows(vector<vector<int>> &matrix, int rows, int coloumns, int i)
{
  for(int j=0;j<coloumns;j++)
  {
    if(matrix[i][j]!=0)
    matrix[i][j]=-1;
  }
}

void mark_coloumn(vector<vector<int>> &matrix, int rows, int coloumns, int j)
{
  for(int i=0;i<coloumns;i++)
  {
    if(matrix[i][j]!=0)
    matrix[i][j]=-1;
  }
}
void BRUTE_set_zeroes(vector<vector<int>> &matrix)
{
  //rows and coloumns
  int rows = matrix.size();
  int coloumns = matrix[0].size();

  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<coloumns ; j++)
    {
      //basic condition
      if(matrix[i][j]==0)
      {
        //mark rows elements as -1 , other that 0
        mark_rows(matrix,rows,coloumns,j);
        //marking coloumn elements as -1 other than 0
        mark_coloumn(matrix,rows,coloumns,i);
      }// end of if condition
    }//end of j loop
  }//end of i loop

//making -1 into zero for final result
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<coloumns ; j++)
    {
      if(matrix[i][j]==-1)
      {
        matrix[i][j]=0;
      }
    }
  }



//ending the function
}

vector<vector<int>> BETTER_set_zeroes(vector<vector<int>> &matrix)
{
  //rows and coloumns
  int rows = matrix.size();
  int coloumns = matrix[0].size();
  vector<int> v1(coloumns,0);
  vector<int> v2(rows,0);

  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<coloumns ; j++)
    {
      //basic condition
      if(matrix[i][j]==0)
      {
        v1[j]=-1;
        v2[i]=-1;
      }
    }
  }
//filling the whole row with zeroes
for(int j=0;j<coloumns;j++)
{

  if(v1[j]==-1)
  {
    for(int i=0;i<rows;i++)
      matrix[i][j]==0;
  }
}
//filling the whole coloumn with zeroes
for(int i=0;i<rows;i++)
{
 if(v2[i]==-1)
      {
        for(int j=0;j<coloumns;j++)
          matrix[i][j]==0;
      }
}
}

vector<vector<int>> OPTIMAL_set_zeroes(vector<vector<int>> &matrix)
{
  //reducing the space complexity //with time complexity as 0(n^2)

  //for later
}

};


class rotate_matrix
{
public:
//BRUTE// make another matrix and place the eements from the last
//matrix to the correct places in new matrix


vector<vector<int>>transpose(vector<vector<int>> &matrix)
{
  int rows=matrix.size();
  int coloumns =matrix[0].size();
  vector<vector<int>>result(coloumns,vector<int>(rows));
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<coloumns;j++)
    {
      result[i][j]=matrix[j][i];
    }
  }
return result;
}

void swap(int &elem1 ,int &elem2)
{
  int temp=elem1;
  elem1=elem2;
  elem2=temp;
}

void reverse_vector(vector<int> &v)
{
  int n= v.size();
  int j=n-1;
  for(int i=0;i<n/2;i++)
  {
    swap(v[i],v[j]);
    j--;
  }
}


void BRUTE_rotate_matrix(vector<vector<int>> &matrix)
{
  //
}

vector<vector<int>> OPTIMAL_rotate_matrix(vector<vector<int>> &matrix)
{
  int rows = matrix.size();
  vector<vector<int>> ans1=transpose(matrix);
  for(int i=0;i<rows;i++)
  {
    reverse_vector(ans1[i]);
  }
  return ans1;
}

};


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

set_zeroes_class obj1;
vector<vector<int>> ans={ {1,1,1}, {1,0,1}, {1,1,1}};
obj1.BETTER_set_zeroes(ans);
// vector<vector<int>> ans =transpose(matrix1);
print_matrix(ans);
return 0;

}

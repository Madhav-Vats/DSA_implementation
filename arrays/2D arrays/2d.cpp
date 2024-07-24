#include <bits/stdc++.h>
#include <vector>

// #include <cmath>
using namespace std;

//input matrix
vector<vector<int>> matrix(int rows , int coloumns)
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


//multiplication of 2 matrix

vector<vector<int>> multiplication_matrix(vector<vector<int>> matrix1 , vector<vector<int>> matrix2)
{
  int rows1 = matrix1.size();
  int coloumns1 = matrix1[0].size();
  int rows2 = matrix2.size();
  int coloumns2 = matrix2[0].size();


  vector<vector<int>> mat(rows1,vector<int>(coloumns2,0));
  for(int i=0;i<rows1;i++)
  {
    for (int j=0;j<coloumns2;j++)
    {
      //(3*2)*(2*4)=(3*4) means rows of first matrix
      //and coloumns of second matrix in resultant matrix

      //coloumns of first and rows of second should be same
      for (int k = 0; k<coloumns1 /*or rows of matrix2*/; k++)
      {
        mat[i][j]+= matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return mat;

}

void m_ultiplication_matrix(vector<vector<int>> matrix1 , vector<vector<int>> matrix2 )
{
  int rows1 = matrix1.size();
  int coloumns1 = matrix1[0].size();
  int rows2 = matrix2.size();
  int coloumns2 = matrix2[0].size();


  vector<vector<int>> mat(rows1 , vector<int>(coloumns2));
  for(int i=0;i<rows1;i++)
  {
    for (int j=0;j<coloumns2;j++)
    {
      //(3*2)*(2*4)=(3*4) means rows of first matrix
      //and coloumns of second matrix in resultant matrix

      //coloumns of first and rows of second should be same
      for (int k = 0; k<coloumns1 /*or rows of matrix2*/; k++)
      {
        mat[i][j]+= matrix1[i][k] * matrix2[k][j];
      }
    }
  }

    int rows =mat.size();
    int coloumns= mat[0].size();
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<coloumns;j++)
      {
        cout<<mat[i][j]<<" ";
      }
      cout<<endl;
    }

}

//transpose of matrix






//add or summ of matrix
vector<vector<int>> add_subtract_matrix(vector<vector<int>> matrix1 , vector<vector<int>> matrix2)
{
  // number of rows and coloumns and both matrix should be equal
  int rows =matrix1.size();
  int coloumns= matrix1[0].size();
  char choice;
  cout<<" enter your choice "<<endl;
  cin>>choice;
  vector<vector<int>> mat(rows, vector<int>(coloumns));

  if(choice=='+')
  {
    for(int i=0;i<rows;i++)

    {
      for(int j=0;j<coloumns;j++)
      {
        mat[i][j]=matrix1[i][j]+matrix2[i][j];
      }
    }
  }

  else if ( choice== '-')
  {
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<coloumns;j++)
      {
        mat[i][j]=matrix1[i][j]-matrix2[i][j];
      }
    }
  }
  return mat;

}


class pascal_triangle
{
public:

//data members
vector<vector<int>> matrix1;
vector<vector<int>> matrix2;
vector<vector<int>> ans;

//member function
int factorial(int n)
{
  int sum=1;
  for(int i=1;i<=n;i++)
  {
    sum*=i;
  }
  return sum;

}
//member function
int nCr(int upper , int lower)
{
  int fact1=factorial(upper);
  int fact2=factorial(lower);
  int fact3=factorial(upper-lower);
  int ans;
  ans=(fact1/(fact2*fact3));
  return ans;
}

//member function
// pascal's triangle using matrix
void pascals_T_pattern(int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<i+1;j++)
    {
      cout<<nCr(i,j);
    }
    cout<<endl;
  }
}

vector<vector<int>> pascals_T_array(int n)
{
  vector<vector<int>> pascal(n);

  for(int i=0;i<n;i++)
  {
    vector<int> ith=pascal[i];
    ith.resize(i+1);
    for(int j=0;j<i+1;j++)
    {
      if(j==0 || j==i)
      {
        pascal[i][j]=1;
      }
      else
      {
        pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
      }

    }
  }
  return pascal;
}


//member function
};







//paspac triangle using (pattern)



//spiral printing of elements
void spiral_printing( vector<vector<int>> matrix)
{
//guide
/*
//left - right(top)-bottom-top-LOOP CONTINUE

//         left----right
//  top       1  2  3
//  |         4  5  6
//  bottom    7  8  9


//left to right(top row) then top++(means top will go down)(reducing the matrix to the leftover matrix)
//top to bottom (right coloumn) then right--
//right to left(bottom row) then bottom --
//bottom to up(left coloumn) then left++
*/

  int rows=matrix.size();
  int coloumns=matrix[0].size();

  int left = 0 ;
  int right = coloumns-1 ;
  int top = 0 ;
  int bottom = rows-1 ;
  int direction =0;
  while(left<=right && top<=bottom )
{
  //left->right
   if(direction==0)
  {
    for(int i=left;i<=right;i++)
    {cout<<matrix[top][i]<<" ";}
    top++;
  }
  //top->bottom
  else if(direction==1)
  {
    for(int i=top;i<=bottom;i++)
    {
      cout<<matrix[i][right]<<" ";
    }
    right--;
  }
  //right->left
  else if (direction==2)
  {
    for(int i=right;i>=left;i--)
    {
      cout<<matrix[bottom][i]<<" ";
    }
    bottom--;

  }
  //bottom->top
  else
  {
    for(int i=bottom;i>=top;i--)
    {
      cout<<matrix[i][left]<<" ";
    }
    left++;
  }

  direction=(direction+1)%4;
}
}






//spiral insertion of elements


void spiral_insertion( vector<vector<int>> matrix)
{
//guide
/*
//left - right(top)-bottom-top-LOOP CONTINUE

//         left----right
//  top       1  2  3
//  |         4  5  6
//  bottom    7  8  9


//left to right(top row) then top++(means top will go down)(reducing the matrix to the leftover matrix)
//top to bottom (right coloumn) then right--
//right to left(bottom row) then bottom --
//bottom to up(left coloumn) then left++
*/

  int rows=matrix.size();
  int coloumns=matrix[0].size();

  int left = 0 ;
  int right = coloumns-1 ;
  int top = 0 ;
  int bottom = rows-1 ;
  int direction =0;
  int value=1;
  while(left<=right && top<=bottom )
{
  //left->right
   if(direction==0)
  {
    for(int i=left;i<=right;i++)
    {matrix[top][i]=value++;}
    top++;
  }
  //top->bottom
  else if(direction==1)
  {
    for(int i=top;i<=bottom;i++)
    {
      cin>>matrix[i][right];
    }
    right--;
  }
  //right->left
  else if (direction==2)
  {
    for(int i=right;i>=left;i--)
    {
      cin>>matrix[bottom][i];
    }
    bottom--;

  }
  //bottom->top
  else
  {
    for(int i=bottom;i>=top;i--)
    {
      cin>>matrix[i][left];
    }
    left++;
  }

  direction=(direction+1)%4;
}
}

























int main()
{
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

// vector<vector<int>> matrix1 =matrix(3,3);
// vector<vector<int>> matrix2 =matrix(3,3);
// vector<vector<int>> ans=add_subtract_matrix(matrix1,matrix2);
// print_matrix(ans);
// pascal_triangle first;
vector<vector<int>> matrix1= matrix(3,3);
spiral_insertion(matrix1);
print_matrix(matrix1);

return 0;

}

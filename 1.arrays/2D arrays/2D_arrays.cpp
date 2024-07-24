#include <bits/stdc++.h>
#include <vector>

// #include <cmath>
using namespace std;

//input matrix
vector<vector<int>> matrix(int rows , int coloumns)
{
  vector<vector<int>> mat ( rows,vector<int>(coloumns));
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
  vector<vector<int>> mat;
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<coloumns;j++)
    {
      cout<<mat[i][j];
    }
  }
}





//multiplication of 2 matrix




//transpose of matrix





//add or summ of matrix





// pascal's triangle using matrix







//paspac triangle using (pattern)






























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

vector<vector<int>> ans =matrix(3,3);
print_matrix(ans);

return 0;
}

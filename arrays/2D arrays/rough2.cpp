#include <bits/stdc++.h>
#include <vector>
using namespace std;
// void swap(int &elem1 ,int &elem2)
// {
//   int temp=elem1;
//   elem1=elem2;
//   elem2=temp;
// }
//
// void reverse_vector(vector<int> &v)
// {
//   int n= v.size();
//   int j=n-1;
//   for(int i=0;i<n/2;i++)
//   {
//     swap(v[i],v[j]);
//     j--;
//   }
// }
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
// }
// void sort_vector(std::vector<int> &v) {
//     int size = v.size();
//     for (int i = 0; i < size - 1; i++) {
//         for (int j = 0; j < size - i - 1; j++) {
//             if (v[j] > v[j + 1]) {
//                 int temp = v[j];
//                 v[j] = v[j + 1];
//                 v[j + 1] = temp;
//             }
//         }
//     }
// }
//
// void sort_columns(std::vector<std::vector<int>> &matrix) {
//     int rows = matrix.size();
//     int columns = matrix[0].size();
//
//     for (int j = 0; j < columns; j++) {
//         std::vector<int> column;
//         for (int i = 0; i < rows; i++) {
//             column.push_back(matrix[i][j]);
//         }
//
//         sort_vector(column);
//
//         for (int i = 0; i < rows; i++) {
//             matrix[i][j] = column[i];
//         }
//     }
// }
//
//


int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
//freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  #endif

vector<vector<int>> ans={{6 ,7 ,3},{ 9, 5, 11},{ 7, 8, 9}};
rr(ans);
print_matrix(ans);

return 0;

}

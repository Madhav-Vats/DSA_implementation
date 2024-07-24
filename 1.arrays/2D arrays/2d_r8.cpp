// void row_zeroes(int arr[][3], int n matrix , int row_no)
//     {
//         int c=matrix[0].size();
//
//         for(int i=0;i<c;i++)
//         {
//             matrix[row_no][i]=0;
//        }
//     }
//
//         void coloumn_zeroes(int arr[][3], int n, int col_no)
//     {
//         int r=matrix.size();
//
//         for(int i=0;i<r;i++)
//         {
//             matrix[i][col_no]=0;
//        }
//     }
//     void setZeroes(int arr[][3], int n) {
//         int r=matrix.size();
//         int c=matrix[0].size();
//
//     for(int i=0;i<r;i++)
//     {
//         for(int j=0;j<c;j++)
//         {
//             int k=i;
//             int l=j;
//            row_zeroes(matrix , k);
//            coloumn_zeroes(matrix, l);
//         }
//
//     }
//
//
//     int main()
//     {
//       int arr[][3], int n arr={}{1,1,1},{1,0,1},{1,1,1}};
//       setZeroes(arr);
//     }
//
//
//
//     #include <bits/stdc++.h>
//     using namespace std;
//
#include <bits/stdc++.h>
#include <vector>
using namespace std;


    void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
        // set all non-zero elements as -1 in the row i:
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }


    void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
        // set all non-zero elements as -1 in the col j:
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

        // Set -1 for rows and cols
        // that contains 0. Don't mark any 0 as -1:

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix, n, m, i);
                    markCol(matrix, n, m, j);
                }
            }
        }

        // Finally, mark all -1 as 0:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }

        return matrix;
    }

    int main()
    {
        vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans = zeroMatrix(matrix, n, m);

        cout << "The Final matrix is: n";
        for (auto it : ans) {
            for (auto ele : it) {
                cout << ele << " ";
            }
            cout << "n";
        }
        return 0;
    }

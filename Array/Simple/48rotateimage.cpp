#include <iostream>
#include <vector>
using namespace std;
/*
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]旋转90度

[
    [1 ,2 ,3 ,4 ],
    [5 ,6 ,7 ,8 ],
    [9 ,10,11,12],
    [13,14,15,16]
]

[
    [13,9 ,5,1],
    [14,10,6,2],
    [15,11,7,3],
    [16,12,8,4]
]
*/

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++) //求矩阵转置
    {
        for (int j = i; j < n; j++)
        {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
    for (int i = 0; i < n; i++) //每行逆序
    {
        for (int j = 0; j < n / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }
}

void rotate_1(vector<vector<int>> &matrix) //先旋转四个角元素，然后第二个元素
{
    int n = matrix.size();
    for (int i = 0; i < (n + 1) / 2; i++)// 列
    {
        for (int j = 0; j < n / 2; j++) // 行
        {
            int temp = matrix[n - 1 - j][i];       // 左下角
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1]; // 左下角=右下角
            matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i]; // 右下角=右上角
            matrix[j][n - 1 - i] = matrix[i][j]; // 右上角=左上角
            matrix[i][j] = temp;
        }
    }
}

int main()
{
    vector<int> row1{1, 2, 3};
    vector<int> row2{4, 5, 6};
    vector<int> row3{7, 8, 9};

    vector<vector<int>> vi{row1, row2, row3};

    rotate_1(vi);
    for (auto row : vi)
    {
        for (auto c : row)
            cout << c << ' ';
        cout << endl;
    }
}
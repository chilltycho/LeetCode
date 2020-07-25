/*找到矩阵中target，矩阵每行元素从左到右升序排列，每列元素从上到下升序排列
[
    [1,4,7,11,15],
    [2,5,8,12,19],
    [3,6,9,16,22],
    [10,13,14,17,24],
    [18,21,23,26,30]
]
target=5，返回true
*/
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size() - 1;
    int col = 0;

    while (row >= 0 && col < matrix[0].size())
    {
        if (matrix[row][col] > target)
        {
            row--;
        }
        else if (matrix[row][col] < target)
        {
            col++;
        }
        else
        { // found it
            return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix{{1, 4, 7, 11, 15},
                               {2, 5, 8, 12, 19},
                               {10, 13, 14, 17, 24},
                               {18, 21, 23, 26, 30}};
    vector<vector<int>> vi;
    cout << searchMatrix(vi, 6);
}
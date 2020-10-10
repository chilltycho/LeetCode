/*找到矩阵中target，矩阵每行元素从左到右升序排列，每列元素从上到下升序排列
[
    [1,  4, 7,11,15],
    [2,  5, 8,12,19],
    [3,  6, 9,16,22],
    [10,13,14,17,24],
    [18,21,23,26,30]
]
target=5，返回true*/
#include <iostream>
#include <vector>
using namespace std;
//从左下角开始
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty())
        return false;
    int row = matrix.size() - 1;
    int col = 0;

    while (row >= 0 && col < matrix[0].size())
    {
        if (matrix[row][col] > target)
            row--;
        else if (matrix[row][col] < target)
            col++;
        else // found it
            return true;
    }
    return false;
}

//二分法,对每行二分查找
bool binarySearch(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

bool searchMatrix_bi(vector<vector<int>> &matrix, int target)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i][0] > target)
            break;
        if (matrix[i][matrix[i].size() - 1] >= target)
        {
            if (binarySearch(matrix[i], target))
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
    cout << searchMatrix(matrix, 4) << endl;
}
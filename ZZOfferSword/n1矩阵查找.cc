/**
 * 在二维数组中，每行按从左到右递增顺序排序，每列按从上到下递增顺序排序。完成函数
 * 输入二维数组和一个整数，判断数组中是否有该整数。
*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

// 旋转90度相当于搜索二叉树
bool find(int target, vector<vector<int>> &array)
{
    int r = array.size();
    int c = array.size();
    int i = 0, j = c - 1;
    while (i < r && j >= 0)
    {
        if (target == array[i][j])
            return true;
        else if (target > array[i][j])
            ++i;
        else
            --j;
    }
    return false;
}

int main()
{
    vector<vector<int>> arr{{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}};
    assert(find(7, arr));
}
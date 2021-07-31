//矩阵每行从左到右升序，每行第一个整数大于前一行最后一个整数
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int l = 0, r = row * col - 1; // 将矩阵看作数组
    while (l < r)
    {
        auto m = l + (r - l) / 2;
        auto p = matrix[m / col][m % col]; // 当前位置
        if (p < target)
            l = m + 1;
        else
            r = m;
    }
    return matrix[l / col][l % col] == target;
}
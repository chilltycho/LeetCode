//矩阵每行从左到右升序，每行第一个整数大于前一行最后一个整数
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int le = 0, ri = r * c - 1;
    while (le <= ri)
    {
        auto piIdx = le + (ri - le) / 2;
        auto pele = matrix[piIdx / c][piIdx % c];
        if (target == pele)
            return true;
        else
        {
            if (target < pele)
                ri = piIdx - 1;
            else
                le = piIdx + 1;
        }
    }
    return false;
}
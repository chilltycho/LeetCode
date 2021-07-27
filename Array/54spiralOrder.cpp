#include <vector>
#include <iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    if (matrix.empty())
        return res;
    int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1, x = 0;
    res.resize((r + 1) * (b + 1));
    while (true)
    {
        for (int i = l; i <= r; i++) //从左到右
            res[x++] = matrix[t][i];
        if (++t > b)
            break;
        for (int i = t; i <= b; i++) //从上到下
            res[x++] = matrix[i][r];
        if (l > --r)
            break;
        for (int i = r; i >= l; i--) //从右到左
            res[x++] = matrix[b][i];
        if (t > --b)
            break;
        for (int i = b; i >= t; i--) //从下到上
            res[x++] = matrix[i][l];
        if (++l > r)
            break;
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = spiralOrder(matrix);
    for (const auto &c : res)
        cout << c << ' ';
}

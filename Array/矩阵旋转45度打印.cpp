#include <bits/stdc++.h>
using namespace std;

void sol(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j <= n - 1; ++j)
        {
            if (i + j <= n - 1)
                cout << matrix[j][i + j] << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = 0; j <= n - 1; ++j)
        {
            if (i + j <= n - 1)
            {
                cout << matrix[i + j][j] << ' ';
            }
        }
        cout << endl;
    }
}

int main()
{
    // int n;
    // cin >> n;
    // vector<vector<int>> vi(n, vector<int>(n, 0));
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         cin >> vi[i][j];
    //     }
    // }
    vector<vector<int>> vi{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol(vi);
}
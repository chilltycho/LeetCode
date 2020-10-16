//给定由0和1组成的矩阵，找出每个元素到最近的0的距离
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

bool inArea(vector<vector<int>> &matrix, int r, int c)
{
    int row = matrix.size();
    int col = matrix[0].size();
    return 0 <= r && r < row && 0 <= c && c < col;
}

void updateMatrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    deque<vector<int>> mq;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (matrix[i][j] == 0)
                mq.push_back({i, j}); //以0为起点
    vector<vector<int>> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dis = -1;
    while (!mq.empty())
    {
        int n = mq.size();
        for (int i = 0; i < n; i++)
        {
            auto pos = mq.front();
            mq.pop_front();
            int r = pos[0];
            int c = pos[1];
            for (auto move : moves)
            {
                int r1 = r + move[0];
                int c1 = c + move[1];
                if (inArea(matrix, r1, c1) && matrix[r1][c1] == 1)
                {
                    matrix[r1][c1] = dis;
                    mq.push_back({r1, c1});
                }
            }
        }
        dis -= 1;
    }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matrix[i][j] = -matrix[i][j];
}

int main()
{
    vector<vector<int>> vii1{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> vii2{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> vii3{{0, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    updateMatrix(vii3);
    for (auto c : vii3)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}
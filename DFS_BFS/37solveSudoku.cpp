//求解9x9数独
#include <vector>
#include <cstring>
using namespace std;

bool line[9][9];//判断行
bool column[9][9];//判断列
bool block[3][3][9];//判断3×3格
bool valid;
vector<pair<int, int>> spaces;

void dfs(vector<vector<char>> &board, int pos)
{
    if (pos == spaces.size())
    {
        valid = true;
        return;
    }
    auto pa = spaces[pos];
    auto i = pa.first;
    auto j = pa.second;
    for (int digit = 0; digit < 9 && !valid; ++digit)
    {
        if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit])
        {
            line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
            board[i][j] = digit + '0' + 1;
            dfs(board, pos + 1);
            line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
        }
    }
}

void solveSudoku(vector<vector<char>> &board)
{
    memset(line, false, sizeof(line));
    memset(column, false, sizeof(column));
    memset(block, false, sizeof(block));
    valid = false;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                spaces.emplace_back(i, j);
            else
            {
                int digit = board[i][j] - '0' - 1;
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
            }
        }
    }
    dfs(board, 0);
}
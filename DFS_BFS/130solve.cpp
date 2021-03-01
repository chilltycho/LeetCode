//给定二维矩阵，包含字母'X','O'。将被围绕的'O'用'X'代替
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
//法1：从边界的'O'开始，将相邻的'O'标记为'A'。再次遍历，将'O'标记为'X'，将'A'标记为'O'
void dfs(vector<vector<char>> &grid, int r, int c)
{
    if (!(0 <= r && r < grid.size() && 0 <= c && c < grid[0].size()) || grid[r][c] != 'O')
        return;
    grid[r][c] = 'A';
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}

void solve(vector<vector<char>> &board)
{
    int row = board.size();
    if (row <= 1)
        return;
    int col = board[0].size();
    if (col <= 1)
        return;
    for (int i = 0; i < col; i++)
    {
        dfs(board, 0, i);
        dfs(board, row - 1, i);
    }
    for (int i = 0; i < row; i++)
    {
        dfs(board, i, 0);
        dfs(board, i, col - 1);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 'A')
                board[i][j] = 'O';
            else if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}
//bfs
void bfs(vector<vector<char>> &board, int r, int c)
{
    board[r][c] = 'A';
    queue<vector<int>> mq;
    mq.push(vector<int>{r, c});
    while (!mq.empty())
    {
        int row = (mq.front())[0];
        int col = (mq.front())[1];
        mq.pop();
        if (row - 1 >= 0 && board[row - 1][col] == 'O')
        {
            board[row - 1][col] = 'A';
            mq.push(vector<int>{row - 1, col});
        }
        if (row + 1 < board.size() && board[row + 1][col] == 'O')
        {
            board[row + 1][col] = 'A';
            mq.push(vector<int>{row + 1, col});
        }
        if (col - 1 >= 0 && board[row][col - 1] == 'O')
        {
            board[row][col - 1] = 'A';
            mq.push(vector<int>{row, col - 1});
        }
        if (col + 1 < board[0].size() && board[row][col + 1] == 'O')
        {
            board[row][col + 1] = 'A';
            mq.push(vector<int>{row, col + 1});
        }
    }
}

void solve_1(vector<vector<char>> &board)
{
    int row = board.size();
    if (row <= 1)
        return;
    int col = board[0].size();
    if (col <= 1)
        return;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((i == 0 || i == row - 1 || j == 0 || j == col - 1) && board[i][j] == 'O')
                bfs(board, i, j);
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 'A')
                board[i][j] = 'O';
            else if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}

int main()
{
    vector<vector<char>> vvc{{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    solve_1(vvc);
    for (auto c : vvc)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}
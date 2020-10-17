#include <iostream>
#include <vector>
using namespace std;
//将n个皇后放置在nxn的棋盘上，使得皇后彼此之间不能相互攻击。皇后可横、竖、斜走7步
vector<vector<string>> res;
//因为是按行从上到下排列，故只考虑同列，左上和右上
bool isValid(vector<string> &board, int row, int col)
{
    int n = board.size();
    for (int i = 0; i < n; i++) //同列
    {
        if (board[i][col] == 'Q')
            return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) //右上
    {
        if (board[i][j] == 'Q')
            return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) //左上
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void dfs(vector<string> &board, int row)
{
    if (row == board.size())
    {
        res.push_back(board);
        return;
    }
    int n = board[row].size();
    for (int col = 0; col < n; col++)
    {
        if (isValid(board, row, col))
        {
            board[row][col] = 'Q';
            dfs(board, row + 1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.')); //.表示空，'Q'表示皇后
    dfs(board, 0);
    return res;
}

int main()
{
    auto res = solveNQueens(4);
    for (auto c : res)
    {
        for (auto cc : c)
            cout << cc << endl;
        cout << endl;
    }
}
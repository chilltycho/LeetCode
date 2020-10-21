/*给定二维网格和一个单词，找出该单词是否存在于网格中。单词必须按字母顺序，通过相邻单元格内字母构成
其中“相邻”指水平或垂直相邻单元格。同一单元格内字母不允许被重复使用*/
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
#if 0
int direction[4][2]{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
bool inArea(int x, int y, vector<vector<char>> &board)
{
    return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
}
bool dfs(int i, int j, int start, string word, vector<vector<char>> &board, vector<vector<bool>> &marked)
{
    if (start == word.size() - 1)
        return board[i][j] == word[start];
    if (board[i][j] == word[start])
    {
        marked[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int newX = i + direction[k][0];
            int newY = j + direction[k][1];
            if (inArea(newX, newY, board) && !marked[newX][newY])
            {
                if (dfs(newX, newY, start + 1, word, board, marked))
                    return true;
            }
        }
        marked[i][j] = false;
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    if (board.empty())
        return false;
    auto rows = board.size();
    auto cols = board[0].size();
    vector<vector<bool>> marked(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (dfs(i, j, 0, word, board, marked))
                return true;
        }
    }
    return false;
}
#endif

bool helper(vector<vector<char>> &board, string word, size_t i, size_t j, size_t p)
{
    //是否越界或者字符不匹配
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[p])
    {
        return false;
    }
    if (p == word.size() - 1)
    {
        return true;
    }
    char tmp = board[i][j];
    board[i][j] = '#';
    bool res = helper(board, word, i - 1, j, p + 1) ||
               helper(board, word, i + 1, j, p + 1) ||
               helper(board, word, i, j - 1, p + 1) ||
               helper(board, word, i, j + 1, p + 1);
    board[i][j] = tmp;
    return res;
}
bool exist_1(vector<vector<char>> &board, string word)
{
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[0].size(); j++)
        {
            if (helper(board, word, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'}};
    assert(exist_1(board, "ABCCED"));
    assert(exist_1(board, "SEE"));
    assert(!exist_1(board, "ABCB"));
}
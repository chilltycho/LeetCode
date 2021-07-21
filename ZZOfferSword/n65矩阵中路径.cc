#include <string>
#include <vector>
using namespace std;

bool helper(vector<vector<char>> &board, string word, size_t i, size_t j, size_t p)
{
    //是否越界或者字符不匹配
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
            || board[i][j] != word[p])
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
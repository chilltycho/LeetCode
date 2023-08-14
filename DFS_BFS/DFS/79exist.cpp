/*给定二维网格和一个单词，找出该单词是否存在于网格中。单词必须按字母顺序，通过相邻单元格内字母构成
其中“相邻”指水平或垂直相邻单元格。同一单元格内字母不允许被重复使用*/
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>> &board, string &word, int i, int j, int p) {
  if (p == word.size())
    return true;
  if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
      board[i][j] != word[p])
    return false;
  char tmp = board[i][j];
  board[i][j] = '#';
  bool res =
      dfs(board, word, i - 1, j, p + 1) || dfs(board, word, i + 1, j, p + 1) ||
      dfs(board, word, i, j - 1, p + 1) || dfs(board, word, i, j + 1, p + 1);
  board[i][j] = tmp;
  return res;
}

bool exist_1(vector<vector<char>> &board, string word) {
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      if (dfs(board, word, i, j, 0))
        return true;
    }
  }
  return false;
}

int main() {
  vector<vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  assert(exist_1(board, "ABCCED"));
  assert(exist_1(board, "SEE"));
  assert(!exist_1(board, "ABCB"));
}

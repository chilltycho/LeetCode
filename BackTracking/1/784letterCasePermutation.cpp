/*给定一个字符串S，将S中每个字母转变大小写，可得到一个新字符串，返回所有可能的字符串集合
输入:"a1b2" 输出：["a1b2","a1B2","A1b2","A1B2"]
输入："3z4" 输出：["3z4","3Z4"]*/
#include <cctype>
#include <iostream>
#include <vector>
using namespace std;
vector<string> res;
// 使用异或转换字母大小写,大写字母与对应小写字母ASCII差为32,2^5
// 若是小写,减去32,若是大写,加上32.合并为对字符的异或操作
void dfs_1(string S, int index) {
  if (S.size() == index) {
    res.push_back(S);
    return;
  }
  // 未修改时
  dfs_1(S, index + 1);
  // 修改当前字母时
  if (isalpha(S[index])) {
    S[index] = S[index] ^ 32;
    dfs_1(S, index + 1);
  }
}

vector<string> letterCasePermutation_1(string S) {
  dfs_1(S, 0);
  return res;
}

string path;
vector<string> res;
void dfs(int depth, string &s) {
  if (depth == s.size()) {
    res.push_back(path);
    return;
  }
  if (isalpha(s[depth])) // 字母时
  {
    path.push_back(s[depth]); // 不修改
    dfs(depth + 1, s);
    path.pop_back();

    path.push_back(s[depth] ^ 32); // 修改
    dfs(depth + 1, s);
    path.pop_back();
  } else // 非字母，不修改
  {
    path.push_back(s[depth]);
    dfs(depth + 1, s);
    path.pop_back();
  }
}
vector<string> letterCasePermutation(string s) {
  dfs(0, s);
  return res;
}

int main() {
  string s = "ab";
  auto res = letterCasePermutation_1(s);
  for (auto c : res)
    cout << c << ' ';
}
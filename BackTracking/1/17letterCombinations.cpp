/*给定一个仅包含数字2-9的字符串，返回它能表示的字母组合。2:abc 3:def 4:ghi 5:jkl
6:mno 7:pqrs 8:tuv 9:wxyz 输入："23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, string> mmap = {
    {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
};

vector<string> res;
string s;
void dfs(string digits, int index) {
  if (index == digits.size()) {
    // 到达叶子节点
    res.push_back(s);
    return;
  }
  for (int i = 0; i < mmap[digits[index]].size(); i++) {
    s += mmap[digits[index]][i];
    dfs(digits, index + 1);
    s.pop_back();
  }
}

vector<string> letterCombinations(string digits) {
  if (digits == "")
    return res;
  s = "";
  dfs(digits, 0);
  return res;
}

int main() {
  string s = "23";
  auto res = letterCombinations(s);
  for (auto c : res)
    cout << c << ' ';
}
/*给定字符串数组，将字母异位词组合在一起*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  vector<vector<string>> res;
  unordered_map<string, size_t> us;
  if (strs.empty())
    return res;
  int i = 1;
  for (auto &s : strs) {
    string temp = s;
    sort(temp.begin(), temp.end());
    if (us.count(temp)) {
      res[us[temp] - 1].push_back(s);
    } else {
      us[temp] = i++;
      res.push_back(vector<string>{s});
    }
  }
  return res;
}

int main() {
  vector<string> vs{"eat", "tea", "tan", "ate", "nat", "bat"};
  auto res = groupAnagrams(vs);
  for (auto c : res) {
    for (auto cc : c)
      cout << cc << ' ';
    cout << endl;
  }
}

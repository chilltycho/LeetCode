/*给定一个可包含重复数字的序列，返回所有不重复的全排列
输入：[1,1,2]
输出：
[
    [1,1,2]
    [1,2,1]
    [2,1,1]
]
1.在哪里会重复，需要跳过（剪枝）
2.回退的时候，撤销哪个变量*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> path;
vector<bool> used;
vector<vector<int>> res;
void dfs(vector<int> &nums, int len, int depth) {
  if (depth == len) {
    res.push_back(path);
  }
  for (int i = 0; i < len; i++) {
    if (!used[i]) {
      // 对要剪枝的直接跳过
      if (!(i > 0 && nums[i] == nums[i - 1] &&
            !used[i - 1])) // 上次1刚被撤销，下次再次使用会重复
                           //  continue;//注意这里不是return
      {
        path.push_back(nums[i]);
        used[i] = true;
        dfs(nums, len, depth + 1);
        used[i] = false;
        path.pop_back();
      }
    }
  }
}

vector<vector<int>> permute_1(vector<int> &nums) {
  int len = nums.size();
  if (len == 0)
    return res;
  sort(nums.begin(), nums.end()); // 排序是剪枝前提
  used = vector<bool>(len, false);
  dfs(nums, len, 0);
  return res;
}

int main() {
  vector<int> vi{1, 1, 2};
  auto res = permute_1(vi);
  for (auto c : res) {
    for (auto cc : c) {
      cout << cc << ' ';
    }
    cout << endl;
  }
}
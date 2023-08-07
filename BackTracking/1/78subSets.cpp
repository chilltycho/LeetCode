/*给定一组不含重复元素的整数数组nums，返回该数组所有可能的子集。
输入：nums=[1,2,3]
输出：[[3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[]]*/
#include <iostream>
#include <vector>
using namespace std;
// 一个子集可选择使用或不使用第一个元素，选好之后，再对第二个元素选择...
// 对第k个元素的选择
void backtrack(vector<int> &nums, int k, vector<int> &current,
               vector<vector<int>> &res) {
  if (k == nums.size()) // 到达底层
  {
    res.push_back(current);
    return;
  }
  // 左子叶，不选
  backtrack(nums, k + 1, current, res);

  // 右子叶，选
  current.push_back(nums[k]);
  backtrack(nums, k + 1, current, res);
  current.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums) {
  vector<int> current;
  vector<vector<int>> res;
  backtrack(nums, 0, current, res);
  return res;
}

vector<vector<int>> res;
// 法二，res为树上所有节点，和法一树不同
void dfs(vector<int> &nums, int start, vector<int> &track) {
  res.push_back(track);
  for (int i = start; i < nums.size(); i++) {
    track.push_back(nums[i]);
    dfs(nums, i + 1, track);
    track.pop_back();
  }
}

vector<vector<int>> subsets_1(vector<int> &nums) {
  vector<int> track;
  dfs(nums, 0, track);
  return res;
}

int main() {
  vector<int> nums{1, 2, 3};
  auto res = subsets_1(nums);
  for (auto c : res) {
    for (auto cc : c)
      cout << cc << ' ';
    cout << endl;
  }
}

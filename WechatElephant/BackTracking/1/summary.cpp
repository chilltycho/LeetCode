/*回溯：采用试错思想，当它通过尝试发现现有的分布答案不能得到有效的正确答案时，它将取消上一步
甚至上几步的计算，再通过其他的可能的分布解答再次尝试寻找问题的答案

二叉树dfs遍历中，从一个节点退出就是一种回溯。
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> res;
void dfs(int target, int start, vector<int> &candidates, vector<int> &current)
{
    if (target == 0)
    {
        res.push_back(current);
        return;
    }
    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++)
    {
        if (!(i > start) || !(candidates[i] == candidates[i - 1]))
        {
            current.push_back(candidates[i]);
            dfs(target - candidates[i], i + 1, candidates, current);
            current.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    if (candidates.empty())
        return res;
    sort(candidates.begin(), candidates.end());
    vector<int> current;
    dfs(target, 0, candidates, current);
    return res;
}

int main()
{
    vector<int> nums{10, 1, 2, 7, 6, 1, 5};
    auto res = combinationSum(nums, 8);
    for (auto c : res)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}
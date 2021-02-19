/*给定无重复元素的数组candidates和目标数target,找出candidates中所有可使数字和为target的组合
candidates中数字可无限重复选取。全为正整数，解集不包含重复组合*/

//candidates:[2,3,6,7] target=7, 输出[[7],[2,2,3]]
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//去重复：搜索时设置搜索起点的下标
vector<vector<int>> res;
vector<int> path;

void dfs(int start, int target, vector<int> &candidates)
{
    if (target == 0)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++)
    {
        path.push_back(candidates[i]);
        //一个数可使用多次，下层节点从该搜索起点开始，start之前的点已搜索过，会重复。如[2,3,2]重复，搜索3后不应考虑2
        dfs(i, target - candidates[i], candidates);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end()); //剪枝前操作，排序提高速度。如果小的数不符合，大的也不符合
    dfs(0, target, candidates);
    return res;
}

//法二，加法
void dfs_2(int start, int target, int cursum, vector<int> &candidates)
{
    if (cursum == target)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size() && cursum + candidates[i] <= target; i++)
    {
        path.push_back(candidates[i]);
        dfs_2(i, target, cursum + candidates[i], candidates);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum_2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    dfs_2(0, target, 0, candidates);
    return res;
}

int main()
{
    vector<int> nums{2, 3, 6, 7};
    auto res = combinationSum_2(nums, 7);
    for (auto c : res)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}
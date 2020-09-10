/*给定一个没有重复数字的序列，返回其所有可能的全排列。
输入：[1,2,3]
输出：
[
    [1,2,3],
    [1,3,2],
    [2,1,3],
    [2,3,1],
    [3,1,2],
    [3,2,1]
]*/

/*
回溯法实际上是在一棵决策树上做遍历的过程，每次决策考虑可选什么，先序遍历选择，后序遍历取消选择
*/
#include <vector>
#include <iostream>
using namespace std;
//current[0..k)是已选集合，current[k..N)是备选集合
void backtrack(vector<int> &current, int k, vector<vector<int>> &res)
{
    if (k == current.size())
    {
        res.push_back(current);
        return;
    }
    //从备选集合中选择
    for (int i = k; i < current.size(); i++)
    {
        //选择数字current[i]
        int temp = current[k];
        current[k] = current[i];
        current[i] = temp;
        //将k+1
        backtrack(current, k + 1, res);
        //撤销选择,回溯即状态重置
        temp = current[k];
        current[k] = current[i];
        current[i] = temp;
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    backtrack(nums, 0, res);
    return res;
}

//法2
void dfs(vector<int> &nums, int len, int depth, 
            vector<int> &path, bool *used, vector<vector<int>> &res)
{
    if (depth == len)
    {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (!used[i])
        {
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, len, depth + 1, path, used, res);
            used[i] = false;
            path.pop_back();
        }
    }
}
vector<vector<int>> permute_1(vector<int> &nums)
{
    int len = nums.size();
    vector<vector<int>> res;
    if (len == 0)
        return res;
    bool* used=new bool[len]{false};
    vector<int> path;
    dfs(nums, len, 0, path, used, res);
    delete [] used;
    return res;
}

int main()
{
    vector<int> vi{1, 2,3};
    auto res = permute_1(vi);
    for (auto c : res)
    {
        for (auto cc : c)
        {
            cout << cc << ' ';
        }
        cout << endl;
    }
}
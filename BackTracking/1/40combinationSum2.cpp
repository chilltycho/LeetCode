/*相比39题，每个数只能使用一次
输入：[10,1,2,7,6,1,5]  target=8
输出：[[1,7],[1,2,5],[2,6],[1,1,6]]*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> path;
vector<vector<int>> res;

void dfs(int start, vector<int> &candidates, int target)
{
    if (target == 0)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++)
    {
        // 或者满足时，continue
        if (!(i > start && candidates[i] == candidates[i - 1])) //i>start保证i-1>=0，此时为回溯时候
        {
            path.push_back(candidates[i]);                  //先序
            dfs(i + 1, candidates, target - candidates[i]); //不允许数组元素重复使用，从i+1开始
            path.pop_back();                                //后序
        }
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    if (candidates.empty())
        return res;
    sort(candidates.begin(), candidates.end());
    dfs(0, candidates, target);
    return res;
}

int main()
{
    vector<int> vi{1, 6, 7, 2, 5, 3};
    auto res = combinationSum2(vi, 8);
    for (auto c : res)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}
/*找出所有相加之和为n的k个数的组合，组合中只允许含有1-9的正整数。组合中无重复数
输入：k=3,n=7 输出[[1,2,4]]
输入：k=3,n=9 输出[[1,2,6],[1,3,5],[2,3,4]]*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;
void dfs(int target, int k, int start)
{
    if (target == 0 && path.size() == k)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i <= 9 && k >= path.size() && target - i >= 0; i++)
    {
        path.push_back(i);
        dfs(target - i, k, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    dfs(n, k, 1);
    return res;
}

int main()
{
    combinationSum3(3, 9);
    for (auto c : res)
    {
        for (auto cc : c)
            cout << cc << " ";
        cout << endl;
    }
}
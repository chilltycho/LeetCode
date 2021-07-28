#include <iostream>
#include <vector>
using namespace std;
/*给定n和k，返回1...n中所有可能的k个数的组合。
输入：n=4,k=2
输出：[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]*/
vector<vector<int>> res;
vector<int> path;
void dfs(int n, int k, int start)
{
    if (path.size() == k)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i <= n; i++)
    {
        path.push_back(i);
        dfs(n, k, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    dfs(n, k, 1);
    return res;
}
int main()
{
    auto res = combine(4, 2);
    for (auto c : res)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}
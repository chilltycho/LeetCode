#include <iostream>
#include <vector>
using namespace std;
/*给定n和k，返回1...n中所有可能的k个数的组合。
输入：n=4,k=2
输出：[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]*/
vector<vector<int>> res;
void findCombinations(int n, int k, int begin, vector<int> &pre)
{
    if (pre.size() == k) //深度为k
    {
        res.push_back(pre);
        return;
    }
    for (int i = begin; i <= n - (k - pre.size()) + 1; i++)
    {
        pre.push_back(i);
        findCombinations(n, k, i + 1, pre);
        pre.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    if (n <= 0 || k <= 0 || n < k)
        return res;
    vector<int> pre;
    findCombinations(n, k, 1, pre);
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
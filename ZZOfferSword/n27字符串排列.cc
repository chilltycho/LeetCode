// 输入abc 输出[abc, acb, bac, cab, cba] 输入可能有字母重复
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> res;
string temp;
void dfs(string str, vector<bool> &used)
{
    if (temp.size() == str.size())
    {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (!used[i] && !(i > 0 && str[i] == str[i - 1] && !used[i - 1]))
        {
            used[i] = true;
            temp.push_back(str[i]);
            dfs(str, used);
            temp.pop_back();
            used[i] = false;
        }
    }
}
vector<string> Permutation(string str)
{
    sort(str.begin(), str.end());
    vector<bool> used(str.size(), false);
    dfs(str, used);
    return res;
}
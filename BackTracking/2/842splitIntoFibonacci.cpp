/*给定数字字符串S，分成菲波那契序列[123,456,579]，若不能返回空。*/
#include <vector>
#include <climits>
#include <iostream>
using namespace std;
bool backtrack(vector<int> &list, string S, int length, int index, long long sum, int prev)
{
    if (index == length)
        return list.size() >= 3;
    long long curr = 0;
    for (int i = index; i < length; i++)
    {
        if (i > index && S[index] == '0') //两位以上数字不能以0开始
            break;
        curr = curr * 10 + S[i] - '0';
        if (curr > INT_MAX)
            break;
        if (list.size() >= 2)
        {
            if (curr < sum)
                continue;
            else if (curr > sum)
                break;
        }
        list.push_back(curr);
        if (backtrack(list, S, length, i + 1, prev + curr, curr))
            return true;
        list.pop_back();
    }
    return false;
}
vector<int> splitIntoFibonacci_1(string s)
{
    vector<int> list;
    backtrack(list, s, s.size(), 0, 0, 0);
    return list;
}

vector<int> path;
vector<vector<int>> res;
void dfs(string &num, int len, int start, long long sum, int prev)
{
    if (start == len && path.size() >= 3)
    {
        res.push_back(path);
        return;
    }
    long long cur = 0;
    for (int i = start; i < len; ++i)
    {
        if (i > start && num[start] == '0')
            return;
        if (cur > INT_MAX)
            return;
        cur = cur * 10 + num[i] - '0';
        if (cur > INT_MAX)
            return;
        if (path.size() >= 2)
        {
            if (cur < sum)
                continue;
            else if (cur > sum)
                return;
        }
        path.push_back(cur);
        dfs(num, len, i + 1, prev + cur, cur);
        path.pop_back();
    }
}
vector<int> splitIntoFibonacci(string num)
{
    dfs(num, num.size(), 0, 0, 0);
    return res.empty() ? vector<int>{} : res[0];
}
int main()
{
    string s = "123456579";
    auto res = splitIntoFibonacci(s);
    for (auto c : res)
        cout << c << ' ';
}
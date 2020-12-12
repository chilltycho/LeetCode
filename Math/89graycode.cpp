/*格雷编码，两个连续数值仅有一个位数的差异。给定总位数n。打印格雷编码序列*/
#include <vector>
#include <unordered_set>
#include <cmath>
#include <iostream>
using namespace std;

bool dfs(int n, int N, vector<int> &res, unordered_set<int> &st)
{
    if (res.size() == N)
        return true;
    auto last = res.back();
    for (int i = 0; i < n; i++)
    {
        auto next = last;
        next ^= (0x1 << i);
        if (st.count(next))
            continue;
        res.push_back(next);
        st.insert(next);
        if (dfs(n, N, res, st))
        {
            return true;
        }
        res.pop_back();
        st.erase(next);
    }
    return false;
}

vector<int> grayCode(int n)
{
    vector<int> res;
    res.push_back(0);
    unordered_set<int> st;
    st.insert(0);
    int N = pow(2, n);//n位格雷码总数
    dfs(n, N, res, st);
    return res;
}
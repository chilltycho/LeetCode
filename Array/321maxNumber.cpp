/*给定长度分别为m和n的两个数组，元素由0-9组成，从两数组中选出k个数字拼接成新的数，
要求从同一个数组中取出的数字保持其在原数组中相对顺序。返回最大数*/
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
//单调栈
vector<int> GetMonStack(vector<int> &nums, int length)
{
    stack<int> s;
    int n = nums.size();
    int drop_num = n - length;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() < nums[i] && drop_num > 0)
        {
            s.pop();
            --drop_num;
        }
        if (s.size() < length)
            s.push(nums[i]);
        else
            --drop_num;
    }
    return [](stack<int> ss) {vector<int> res(ss.size(),0);int i=ss.size()-1;while(!ss.empty()){res[i--]=ss.top();ss.pop();}return res; }(s);
}
int compare(vector<int> &l, int a, vector<int> &r, int b)
{
    int ls = l.size(), rs = r.size();
    while (a < ls && b < rs)
    {
        int tag = l[a++] - r[b++];
        if (tag != 0)
            return tag;
    }
    return (ls - a) - (rs - b);
}
vector<int> MergeVector(vector<int> &l, vector<int> &r)
{
    int sl = l.size(), sr = r.size();
    if (!sl)
        return r;
    if (!sr)
        return l;
    int a = 0, b = 0;
    int n = sl + sr, i = 0;
    vector<int> res(n, 0);
    while (i < n)
    {
        if (compare(l, a, r, b) > 0)
            res[i++] = l[a++];
        else
            res[i++] = r[b++];
    }
    return res;
}

vector<int> MaxNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    int s1 = nums1.size(), s2 = nums2.size();
    int start = max(0, k - s2), end = min(s1, k);
    vector<int> res(k, 0);
    for (int i = start; i <= end; i++)
    {
        vector<int> one(GetMonStack(nums1, i));
        vector<int> two(GetMonStack(nums2, k - i));
        vector<int> temp(MergeVector(one, two));
        if (compare(temp, 0, res, 0) > 0)
            res.swap(temp);
    }
    return res;
}

int main()
{
    vector<int> v1{3, 4, 6, 5};
    vector<int> v2{9, 1, 2, 5, 8, 3};
    auto res = MaxNumber(v1, v2, 5); //98653
    for (auto c : res)
        cout << c << ' ';
}
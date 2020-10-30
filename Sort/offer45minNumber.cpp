//输入非负整数数组，将数组里所有数字拼接成一个数，使最小
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string minNumber(vector<int> &nums)
{
    vector<string> snum;
    for (const auto &c : nums)
        snum.push_back(to_string(c));
    sort(snum.begin(), snum.end(), [](string &s1, string &s2) { return s1 + s2 < s2 + s1; });
    string res;
    for (auto &s : snum)
    {
        res += s;
    }
    return res;
}

int main()
{
    vector<int> vi{3, 30, 34, 5, 9};
    cout << minNumber(vi);
}
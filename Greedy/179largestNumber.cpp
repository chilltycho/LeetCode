#include <bits/stdc++.h>
using namespace std;

string largestNumber(vector<int> &nums)
{
    vector<string> vs;
    for (auto s : nums)
        vs.push_back(to_string(s));
    sort(vs.begin(), vs.end(), [](string &l, string &r)
         { return l + r > r + l; });
    string res;
    for (auto s : vs)
        res += s;
    if (res[0] == '0')
        return "0";
    return res;
}
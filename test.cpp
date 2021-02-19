#include <climits>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
string path;
vector<string> res;

void dfs(string &s, int depth)
{
    if (path.size() == s.size())
        res.push_back(path);
    if (isalpha(s[depth]))
    {
        path.push_back(s[depth]);
        dfs(s, depth + 1);
        path.pop_back();

        path.push_back(s[depth]^32);
        dfs(s, depth + 1);
        path.pop_back();
    }
    else
    {
        path.push_back(s[depth]);
        depth++;
    }
}

vector<string> letterCasePermutation(string S)
{
    dfs(S, 0);
    return res;
}

int main()
{
    string s{"a1b2"};
    auto res = letterCasePermutation(s);
    for (auto c : res)
        cout << c << endl;
}
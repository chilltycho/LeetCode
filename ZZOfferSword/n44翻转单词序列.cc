#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string ReverseSentence(string str)
{
    vector<string> tmp;
    string s{};
    for (auto c : str)
    {
        if (c == ' ')
        {
            tmp.push_back(s);
            s = "";
        }
        else
        {
            s.push_back(c);
        }
    }
    tmp.push_back(s);
    reverse(tmp.begin(), tmp.end());
    string res;
    for (auto c : tmp)
        res += c + " ";
    res.erase(res.end() - 1);
    return res;
}
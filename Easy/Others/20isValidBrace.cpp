#include <iostream>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;

bool isValid(string s)
{
    stack<char> sta;
    unordered_map<char, char> brace{{'{', '}'}, {'[', ']'}, {'(', ')'}};
    set<char> bra{'}', ']', ')'};
    for (auto c : s)
    {
        if (bra.find(c) != bra.end())
        {
            if (!sta.empty() && brace.at(sta.top()) == c)
            {
                sta.pop();
                continue;
            }
            else
                return false;
        }
        else if (brace.find(c) != brace.end())
        {
            sta.push(c);
        }
    }
    return sta.empty();
}

bool isValid_1(string s)
{
    if (s.empty())
        return true;
    stack<char> charstack;
    for (char c : s)
    {
        if (c == '(')
            charstack.push(')');
        else if (c == '{')
            charstack.push('}');
        else if (c == '[')
            charstack.push(']');
        else if (charstack.empty() || c != charstack.pop())
            return false;
    }
    return charstack.empty();
}

int main()
{
    string s1 = "()[aaa]{}";
    string s2 = "]";
    cout << isValid(s1) << ' ' << isValid(s2);
}
//将字符串转换为整数
#include <iostream>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;
class Automaton
{
    string state = "start";
    unordered_map<string, vector<string>> table =
        {
            {"start", {"start", "signed", "in_number", "end"}},
            {"signed", {"end", "end", "in_number", "end"}},
            {"in_number", {"end", "end", "in_number", "end"}},
            {"end", {"end", "end", "end", "end"}}};

    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' || c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;
    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : max(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};
int strToInt(string str)
{
    Automaton automaton;
    for (char c : str)
        automaton.get(c);
    return automaton.sign * automaton.ans;
}

int main()
{
    string s1{"42"};            //42
    string s2{"   -42"};        //-42
    string s3{"4139   with"};   //4139
    string s4{"words and 987"}; //0
    string s5{"-91283472332"};  //INT_MIN
}
/**
 * 将字符串中每个空格替换成"%20"
*/
#include <iostream>
using namespace std;

string replaceSpace(string &s)
{
    string temp{"%20"};
    string res{};
    for (auto &c : s)
    {
        if (c == ' ')
            res += temp;
        else
            res.push_back(c);
    }
    return res;
}

int main()
{
    string s{"We Are Happy"};
    cout << replaceSpace(s) << endl;
}
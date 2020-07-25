#include <iostream>
#include <string>
#include <stack>
using namespace std;

string ite(string s)
{
    string res;
    for (int i = 0; i < s.size(); i++)
    {
        int times = 1;
        while (s[i] == s[i + 1])
        {
            times++;
            i++;
        }
        res += to_string(times);
        res += s[i];
    }
    return res;
}

string countAndSay(int n)
{
    int i = 1;
    string res = to_string(i);
    while (i < n)
    {
        res = ite(res);
        i++;
    }
    return res;
}

string countAndSay_1(int n)
{
   
}

int main()
{
    for (int i = 0; i < 10; i++)
        cout << countAndSay_1(i) << endl;
}
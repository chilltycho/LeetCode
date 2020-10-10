/*气球的最大数量：给定一个字符串text，用text中字母来拼凑尽可能多的"balloon"，每个字母只能使用1次
输入：nlaebolko
输出：1*/
#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int maxNumberOfBallons(string text)
{
    string ballon = "balloon";
    unordered_map<char, int> um = {{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};
    for (auto c : text)
    {
        if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n')
            um[c]++;
    }
    um['l'] /= 2;
    um['o'] /= 2;
    int res = INT_MAX;
    for (auto c : um)
    {
        res = min(c.second, res);
    }
    return res;
}

int maxNumberOfBalloons_1(string text)
{
    int balloon[5]{0}; //a b l o n
    if (text.empty())
        return 0;
    for (const auto &c : text)
    {
        if (c == 'a')
            balloon[0]++;
        if (c == 'b')
            balloon[1]++;
        if (c == 'l')
            balloon[2]++;
        if (c == 'o')
            balloon[3]++;
        if (c == 'n')
            balloon[4]++;
    }
    balloon[2] /= 2;
    balloon[3] /= 2;
    int res = INT_MAX;
    for (int i = 0; i < 5; i++)
        res = min(balloon[i], res);
    return res;
}

int main()
{
    cout << maxNumberOfBallons("leetcode");            //0
    cout << maxNumberOfBalloons_1("nlaebolko");        //1
    cout << maxNumberOfBalloons_1("loonbalxballpoon"); //2
}
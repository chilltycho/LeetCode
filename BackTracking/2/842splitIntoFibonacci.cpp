/*给定数字字符串S，分成菲波那契序列[123,456,579]，若不能返回空。*/
#include <vector>
#include <climits>
#include <iostream>
using namespace std;
bool backtrack(vector<int> &list, string S, int length, int index, long long sum, int prev)
{
    if (index == length)
        return list.size() >= 3;
    long long curr = 0;
    for (int i = index; i < length; i++)
    {
        if (i > index && S[index] == '0') //一个数不能以0开始
            break;
        curr = curr * 10 + S[i] - '0';
        if (curr > INT_MAX)
            break;
        if (list.size() >= 2)
        {
            if (curr < sum)
                continue;
            else if (curr > sum)
                break;
        }
        list.push_back(curr);
        if (backtrack(list, S, length, i + 1, prev + curr, curr))
            return true;
        list.pop_back();
    }
    return false;
}
vector<int> splitIntoFibonacci(string s)
{
    vector<int> list;
    backtrack(list, s, s.size(), 0, 0, 0);
    return list;
}

int main()
{
    string s = "123456579";
    auto res = splitIntoFibonacci(s);
    for (auto c : res)
        cout << c << ' ';
}
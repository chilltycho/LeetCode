//给定两个字符串s，t，判断t是否为s变位词，即是否可以将字母重新排列得到t

//1.排序：army->amry  mary->amry
//2.计数：state->{a:1,e:1,s:1,t:2}  taste->

#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() == t.size())
    {
        unordered_map<char, int> counter;
        for (auto c : s)
        {
            counter[c]++;
        }
        for (auto a : t)
        {
            if (counter[a] == 0)
                return false;
            else
                counter[a]--;
        }
        return true;
    }
    else
        return false;
}

int main()
{
}
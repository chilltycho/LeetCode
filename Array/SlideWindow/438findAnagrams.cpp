/*给定字符串s，非空字符串p，找到s中所有是p的字母异位词的子串，返回这些子串的起始索引*/
#include <vector>
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    if (s.size() == 0 || p.size() == 0 || s.size() < p.size())
        return res;
    int needs[26]{0};
    int window[26]{0};
    for (int i = 0; i < p.size(); i++)
        needs[p[i] - 'a']++;
    int left = 0, right = 0;
    while (right < s.size())
    {
        int curR = s[right] - 'a';
        right++;
        window[curR]++;
        //窗口中包含多个s[right]字符,窗口右移
        while (window[curR] > needs[curR])
        {
            int curL = s[left] - 'a';
            left++;
            window[curL]--;
        }
        //完全匹配
        if (right - left == p.size())
            res.push_back(left);
    }
    return res;
}

int main()
{
    vector<int> res{0, 6};
    vector<int> res1{0, 1, 2};
    //索引0开始的子串是"cba"，是"abc"异位词。索引6开始子串是"bac",是"abc"异位词
    assert(res == findAnagrams("cbaebabacd", "abc"));
    assert(res1 == findAnagrams("abab", "ab"));
}
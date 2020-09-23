/*给定字符串S，T。在O(n)时间内从字符串S中找出：包含T所有字符的最小子串
若S中不存在这样子串，返回空字符串。答案唯一*/
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t)
{
    if (s.empty())
        return "";
    int need[128]{0};
    int count = 0;
    //需包含的字符
    for (auto c : t)
        need[c]++;
    count = t.size();

    int l = 0, r = 0, start = 0, size = INT32_MAX;
    while (r < s.size())
    {
        char c = s[r];
        if (need[c] > 0)
            count--;
        need[c]--;
        if (count == 0) //窗口完全包含了need
        {
            //need[s[l]]<0表面字符不在need中
            while (l < r && need[s[l]] < 0) //从左边缩减窗口至最小
                need[s[l++]]++;
            if (r - l + 1 < size) //新窗口长度小于旧的时，更新minWindow
            {
                size = r - l + 1;
                start = l;
            }
            need[s[l]]++; //窗口右移
            l++;
            count++;
        }
        r++;
    }
    return size == INT32_MAX ? "" : s.substr(start, size);
}

int main()
{
    assert("BANC" == minWindow("ADOBECODEBANC", "ABC"));
}
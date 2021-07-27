/*给定字符串S，T。在O(n)时间内从字符串S中找出：包含T所有字符的最小子串
若S中不存在这样子串，返回空字符串。答案唯一*/
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t)
{
    if (s.size() < t.size())
        return "";

    int need[128]{0}; //存储t的哈希表
    size_t count = t.size();
    size_t slen = s.size();
    for (const auto &c : t)
        need[c]++;

    size_t min_size = s.size() + 1; //包含t的窗口大小
    size_t l = 0, r = 0, start = 0;
    for (l = 0, r = 0; r < slen; r++)
    {
        if (need[s[r]] > 0)
            count--;
        need[s[r]]--;
        if (count == 0) //窗口完全包含t
        {
            while (l < r && need[s[l]] < 0) //左边存在不必要字符
                need[s[l++]]++;
            if (r - l + 1 < min_size) //存在较小窗口
            {
                min_size = r - l + 1;
                start = l; //记录该窗口起始
            }
            // need[s[l]]++; //无论后面是否还有包含t窗口,窗口右移
            // l++;
            // count++;
        }
    }
    return min_size == s.size() + 1 ? "" : s.substr(start, min_size);
}

int main()
{
    assert("BANC" == minWindow("ADOBECODEBANCDDD", "ABC"));
}
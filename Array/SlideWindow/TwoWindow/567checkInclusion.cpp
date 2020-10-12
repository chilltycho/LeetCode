//给定两个字符串s1和s2,判断s2是否包含s1的排列
#include <string>
#include <cassert>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;
    int need[128]{0};
    int window[128]{0};
    for (const auto &c : s1)
        need[c]++;

    for (int left = 0, right = 0; right < s2.size(); right++)
    {
        window[s2[right]]++;
        while (window[s2[right]] > need[s2[right]])
        {
            window[s2[left]]--;
            left++;
        }
        if (right - left + 1 == s1.size())
            return true;
    }
    return false;
}

int main()
{
    assert(checkInclusion("ab", "eidbaooo"));
    assert(!checkInclusion("ab", "eidboaoo"));
}
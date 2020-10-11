#include <string>
#include <cassert>
using namespace std;
bool matches(int *slmap, int *s2map)
{
    for (int i = 0; i < 26; i++)
        if (slmap[i] != s2map[i])
            return false;
    return true;
}

bool checkInclusion(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;
    int need[26]{0};
    for (int i = 0; i < s1.size(); i++)
        need[s1[i] - 'a']++;
    for (int i = 0; i <= s2.size() - s1.size(); i++)
    {
        int window[26]{0};
        for (int j = 0; j < s1.size(); j++)
            window[s2[i + j] - 'a']++;
        if (matches(need, window))
            return true;
    }
    return false;
}

bool checkInclusion_1(string s1, string s2)
{
    if (s1.size() > s2.size())
        return false;
    int need[26]{0};
    int window[26]{0};
    for (int i = 0; i < s1.size(); i++)
    {
        need[s1[i] - 'a']++;
        window[s2[i] - 'a']++;
    }
    for (int l = 0; l < s2.size() - s1.size(); l++)
    {
        if (matches(need, window))
            return true;
        //右移窗口
        window[s2[l + s1.size()] - 'a']++;
        window[s2[l] - 'a']--;
    }
    return matches(need, window);
}

bool checkInclusion_2(string s1, string s2)
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
    assert(checkInclusion_2("ab", "eidbaooo"));
    assert(!checkInclusion_2("ab", "eidboaoo"));
}
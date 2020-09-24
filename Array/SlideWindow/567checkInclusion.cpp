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
    int slmap[26]{0};
    for (int i = 0; i < s1.size(); i++)
        slmap[s1[i] - 'a']++;
    for (int i = 0; i <= s2.size() - s1.size(); i++)
    {
        int s2map[26]{0};
        for (int j = 0; j < s1.size(); j++)
            s2map[s2[i + j] - 'a']++;
        if (matches(slmap, s2map))
            return true;
    }
    return false;
}

bool checkInclusion_1(string s1,string s2)
{
    if(s1.size()>s2.size())
        return false;
    int s1map[26]{0};
    int s2map[26]{0};
    for(int i=0;i<s1.size();i++)
    {
        s1map[s1[i]-'a']++;
        s2map[s2[i]-'a']++;
    }
    for(int i=0;i<s2.size()-s1.size();i++)
    {
        if(matches(s1map,s2map))
            return true;
        s2map[s2[i+s1.size()]-'a']++;
        s2map[s2[i]-'a']--;
    }
    return matches(s1map,s2map);
}

int main()
{
    assert(checkInclusion("ab", "eidbaooo"));
    assert(!checkInclusion("ab", "eidboaoo"));
}
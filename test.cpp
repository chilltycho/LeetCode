#include <iostream>
using namespace std;
bool backspaceCompare(string s, string t)
{
    int l = s.size() - 1, r = t.size() - 1;
    int skips = 0, skipt = 0;
    while (l >= 0 && r >= 0)
    {
        while (l >= 0 && s[l] == '#')
        {
            --l;
            ++skips;
        }
        l -= skips;
        while (r >= 0 && t[r] == '#')
        {
            --r;
            ++skipt;
        }
        r-=skipt;
        if (l < 0 && r < 0)
            return true;
        if (l < 0 || r < 0)
            return false;
        if (s[l] != t[r])
            return false;
        --l, --r;
    }
    return true;
}

int main()
{
    string s{"xywrrmp"};
    string t{"xywrrmu#p"};
    cout << backspaceCompare(s, t) << endl;
}
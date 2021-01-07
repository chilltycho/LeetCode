/*给定字符串s，将s分割为子串，每个子串都是回文串。返回最少分割次数*/
#include<vector>
using namespace std;

bool isPalindrome(string s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int minCut(string s)
{
    
}

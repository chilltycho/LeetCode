/*判断回文串，只考虑字母和数字字符，可忽略字母大小写*/
#include <string>
#include <cassert>
using namespace std;
bool isPalindrome(string s)
{
    size_t left = 0;
    size_t right = s.size() - 1;
    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
            ++left;
        while (left < right && !isalnum(s[right]))
            --right;
        if (left < right)
        {
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            else
            {
                ++left;
                --right;
            }
        }
    }
    return true;
}

int main()
{
    assert(isPalindrome("A man, a plan, a canal: Panama"));
    assert(!isPalindrome("race a car"));
}
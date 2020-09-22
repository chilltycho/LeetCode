/*判断回文串，只考虑字母和数字字符，可忽略字母大小写*/
#include <string>
#include <cassert>
using namespace std;

bool isValid(char &c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c = c - 'A' + 'a';
        return true;
    }
    else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return true;
    else
        return false;
}
bool isPalindrome(string s)
{

    int left = 0;
    int right = s.size() - 1;
    while (left < right)
    {
        if (!isValid(s[left]))
        {
            left++;
            continue;
        }
        if (!isValid(s[right]))
        {
            right--;
            continue;
        }
        if (s[left] != s[right])
            return false;
        else
        {
            left++;
            right--;
        }
    }
    return true;
}

int main()
{
    assert(isPalindrome("A man, a plan, a canal: Panama"));
    assert(!isPalindrome("race a car"));
}
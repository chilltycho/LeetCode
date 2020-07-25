#include <iostream>
using namespace std;
//只考虑字母和数字字符，忽略字母大小写
bool isPalindrome(string s)
{
    string tmp;
    for (auto c : s)
    {
        if (islower(c) || isdigit(c))
            tmp += c;
        else if (isupper(c))
            tmp += (c + 32);
    }
    int i = 0, j = tmp.size() - 1;
    while (i < j)
    {
        if (tmp[i] != tmp[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    string s="A man, a plan, a canal: Panama";
    string s1="race a car";
    cout<<isPalindrome(s1);
}
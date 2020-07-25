#include <iostream>
#include<string>
using namespace std;
/*
给定haystack字符串和needle字符串，在haystack中找出needle字符串
出现的第一个位置（从0开始）。如果不存在，返回-1
当neddle为空字符串饭返回0
*/
int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int L = needle.size();
    for (int start = 0; start < n - L + 1; ++start)
    {
        if(haystack.substr(start,L)==needle)
            return start;
    }
    return -1;
}


int main()
{
    cout<<30000%13;
}
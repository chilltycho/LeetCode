#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> strs) //LCP(S1...Sn)=LCP(LCP(LCP(S1,S2),S3),..Sn)
{
    if (strs.empty())
        return "";
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        while ((strs[i]).substr(0, prefix.size()) != prefix)
        {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.size() == 0)
                return "";
        }
    }
    return prefix;
} //O(S) S为所有字符串中字符数量额总和

string longestCommonPrefix_1(vector<string> strs) //对每列比较
{
    if (strs.empty())
        return "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            if (i == strs[j].size() || strs[j][i] != c)
                return strs[0].substr(0, i);
        }
    }
    return strs[0];
} //O(S)

string commonPrefix(string left, string right)
{
    int minsize = min(left.size(), right.size());
    for (int i = 0; i < minsize; i++)
        if (left[i] != right[i])
            return left.substr(0, i);
    return left.substr(0, minsize);
}

string longestCommonPrefix_merge(vector<string> strs, int l, int r)
{
    if (l == r)
        return strs[l];
    else
    {
        int mid = (l + r) / 2;
        string lcpleft = longestCommonPrefix_merge(strs, l, mid);
        string lcpright = longestCommonPrefix_merge(strs, mid + 1, r);
        return commonPrefix(lcpleft, lcpright);
    }
}

string longestCommonPrefix_merge_sum(vector<string> strs) //分治算法
{
    if (strs.empty())
        return "";
    return longestCommonPrefix_merge(strs, 0, strs.size() - 1);
}//O(S)

bool isCommonPrefix(vector<string> strs, int len)
{
    string str1 = strs[0].substr(0, len);
    for (int i = 1; i < strs.size(); i++)
        if (!(strs[i].substr(0, str1.size()) == str1))
            return false;
    return true;
}
string longestCommonPrefix_Binary(vector<string> strs)//利用二分法寻找所有字符串公共前缀最大长度L
{
    if (strs.empty())
        return "";
    size_t minLen = 9999;
    for (auto str : strs)
        minLen = min(minLen, str.size());
    int low = 1;
    int high = minLen;
    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (isCommonPrefix(strs, middle))
            low = middle + 1;
        else
            high = middle - 1;
    }
    return strs[0].substr(0, (low + high) / 2);
}//O(S*log(n))

int main()
{
    vector<string> vs{"leets", "leetcode", "leet", "leeds"};
    cout << longestCommonPrefix_Binary(vs);   
}
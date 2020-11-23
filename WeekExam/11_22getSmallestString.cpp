//返回长度等于n且数值等于k的字典序最小的字符串
#include <iostream>
using namespace std;

string getSmallestString(int n, int k)
{
    string res(n, 'a');
    int nz = (k - n) / 25; //‘z'数量
    int r = (k - n) % 25;  //第一个z前面那位
    res[n - nz - 1] = 'a' + r;
    for (int i = n - nz; i < n; i++)
        res[i] = 'z';
    return res;
}

/*贪心法，每次选择满足要求的最小字母。
对某位放入的字母c应满足n'-1<=k'-c<=26(n'-1)
若k'-26(n'-1)<=0，选a，否则选对应数值对应字符。*/
string getSmallestString_1(int n, int k)
{
    string ans;
    for (int res = n; res >= 1; --res)
    {
        int bound = k - 26 * (res - 1);
        if (bound > 0)
        {
            ans.push_back('a' + bound - 1);
            k -= bound;
        }
        else
        {
            ans.push_back('a');
            k--;
        }
    }
    return ans;
}

int main()
{
    cout << getSmallestString(2, 18) << endl; //aq
    cout << getSmallestString(5, 73) << endl; //aaszz
    cout << getSmallestString(3, 27) << endl; //aay
}
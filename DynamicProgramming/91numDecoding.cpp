/*A对应1,..Z对应26.求字符串解码方法总数*/
#include <iostream>
#include <vector>
using namespace std;
/**
 * dp[i]为str[0..i]解码方法总数。
 * s[i]=='0' 则若s[i-1]=='1'or'2' dp[i]=dp[i-2] 否则dp[i]=0
 * s[i-1]=='1' 则dp[i]=dp[i-1]+dp[i-2]
 * s[i-1]=='2' 且'1'<=s[i]<='6' 则dp[i]=dp[i-1]+dp[i-2]
*/
int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;
    int pre = 1, cur = 1; // dp[-1]=dp[0]=1
    for (int i = 1; i < s.size(); i++)
    {
        int tmp = cur;
        if (s[i] == '0')
        {
            if (s[i - 1] == '1' || s[i - 1] == '2')
                cur = pre;
            else
                return 0;
        }
        else if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')
            cur = cur + pre;
        pre = tmp;
    }
    return cur;
}

int numDecodings_1(string s)
{
    if (s[0] == '0')
        return 0;
    int n = s.size();
    vector<int> dp(n + 1, 1);
    //dp[0]表示s[-1]的状态， dp[1] 表示 s[0]的状态
    //dp[i] 表示 s[i-1]的状态
    for (int i = 2; i <= n; i++)
    {
        if (s[i - 1] == '0')
        {
            if (s[i - 2] == '1' || s[i - 2] == '2') //唯一译码，不增加情况
                dp[i] = dp[i - 2];
            else 
                return 0;
        }
        else if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] >= '1' && s[i - 1] <= '6')
            dp[i] = dp[i - 1] + dp[i - 2];
        else //s[i-1]为3-9
            dp[i] = dp[i - 1];
    }
    //for(auto c:dp) cout << c << ",";
    return dp[n]; //返回dp[n] 即最后 s[n-1] 的状态
}

int main()
{
    cout << numDecodings("12") << endl;  //(1 2)或(12)
    cout << numDecodings("226") << endl; //(2 26)或(22 6)或(2 2 6)
}
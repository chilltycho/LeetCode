/*给定字符串s1,s2,s3,判断s3是否为s1,s2交错组成*/
#include <iostream>
#include <vector>
using namespace std;
//dp[i][j]表示s1前i个字符和s2前j个字符能否组成s3前i+j个字符
bool isInterleave(string s1, string s2, string s3)
{
    vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1));
    dp[0][0] = true;
    int size1 = s1.size();
    int size2 = s2.size();
    int size3 = s3.size();
    if (size1 + size2 != size3)
        return false;
    for (int i = 1; i <= size1; i++)
        dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    for (int j = 1; j <= size2; j++)
        dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
        {
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                       (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    return dp[size1][size2];
}

int main()
{
    string str1 = "aabcc";
    string str2 = "dbbca";
    string str3 = "aadbbcbcac";
    cout << isInterleave(str1, str2, str3) << endl;
}
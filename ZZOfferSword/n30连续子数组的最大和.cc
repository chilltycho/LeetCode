#include <vector>
using namespace std;
int FindGreatestSumOfSubArray(vector<int> array)
{
    if (array.empty())
        return 0;
    vector<int> dp(array.size(), 0);
    dp[0] = array[0];
    int cur = array[0];
    int res = INT_MIN;
    for (int i = 1; i < array.size(); ++i)
    {
        cur = max(cur, 0) + array[i];
        res = max(res, cur);
    }
    return res;
}
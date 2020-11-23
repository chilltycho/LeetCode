/*选择下标删除对应元素，使得奇数下表元素和等于偶数元素下表，
返回删除下标方案数。*/
#include <vector>
#include <iostream>
using namespace std;
//前缀和
int waysToMakeFair(vector<int> &nums)
{
    int n = nums.size();
    vector<int> odd(n);
    vector<int> even(n);
    even[0] = nums[0];
    odd[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            even[i] = even[i - 1] + nums[i];
            odd[i] = odd[i - 1];
        }
        else
        {
            even[i] = even[i - 1];
            odd[i] = odd[i - 1] + nums[i];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) //删除元素位置
    {
        int left_odd = i - 1 >= 0 ? odd[i - 1] : 0;   //左半部分奇数和
        int left_even = i - 1 >= 0 ? even[i - 1] : 0; //左半部分偶数和
        int right_odd = odd[n - 1] - odd[i];
        int right_even = even[n - 1] - even[i];
        swap(right_even, right_odd);
        if (left_even + right_even == left_odd + right_odd)
            res++;
    }
    return res;
}
//考虑奇偶元素差值，求正负交替的前缀和dp[i]
int waysToMakeFair_1(vector<int> nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    for (int i = 1; i < dp.size(); i++)
    {
        if (i % 2 == 1)
            dp[i] = dp[i - 1] + nums[i - 1];
        else
            dp[i] = dp[i - 1] - nums[i - 1];
    }
    int ans = 0;
    for (int i = 1; i < dp.size(); i++)
        if (dp[i - 1] == dp[n] - dp[i])
            ans++;
    return ans;
}
int main()
{
    vector<int> vi{2, 1, 6, 4};
    cout << waysToMakeFair(vi);
}
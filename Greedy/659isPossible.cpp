/*按升序数组，分割为一个或多个子序列，每个序列由连续整数组成
且长度至少为3，若能完成分割，返回true,否则返回false*/
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
/*哈希+堆，只需知道子序列最后一个数字和子序列长度，就能确定子序列。
1.当x在数组中，若存在一个子序列以x-1结尾，长度为k，则可将x加入子序列中，得到长度为
k+1的子序列。若不存在x-1结尾的子序列，则新建只包含x的子序列，长度为1
2.当x在数组中，若存在多个子序列以x-1结尾，应将x加入最短的子序列（每个子序列长度至少为3）
*/
bool isPossible(vector<int> &nums)
{
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for (auto &x : nums)
    {
        if (mp.find(x) == mp.end())
        {
            mp[x] = priority_queue<int, vector<int>, greater<int>>();
        }
        if (mp.find(x - 1) != mp.end())
        {
            int prevLength = mp[x - 1].top();
            mp[x - 1].pop();
            if (mp[x - 1].empty())
                mp.erase(x - 1);
            mp[x].push(prevLength + 1);
        }
        else
        {
            mp[x].push(1);
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        priority_queue<int, vector<int>, greater<int>> queue = it->second;
        if (queue.top() < 3)
            return false;
    }
    return true;
}

//贪心
/*考虑数组中每个不同整数，设当前整数为x，前一个整数为prev。首先统计x数量，
dp1为prev结尾长度为1的子序列数目，dp2为长度为2,dp3为长度比2大的。总是将x添加到
prev子序列长度小于3的，若x数量不够，说明不存在相应分割方案。
2.剩下x数目left=cnt-dp1-dp2。将x加入长度大于2的。最多添加min(left,dp3)，其他的
才创建新序列。
*/
bool isPossible_greedy(vector<int> &nums)
{
    int n = nums.size();
    int dp1 = 0, dp2 = 0, dp3 = 0;
    int i = 0;
    while (i < n)
    {
        int start = i;
        int x = nums[i];
        while (i < n && nums[i] == x)
            i++;
        int cnt = i - start;
        if (start > 0 && x != nums[start - 1] + 1)
        {
            if (dp1 + dp2 > 0)
                return false;
            else
            {
                dp1 = cnt;
                dp2 = dp3 = 0;
            }
        }
        else
        {
            if (dp1 + dp2 > cnt)//x不够用
                return false;
            int left = cnt - dp1 - dp2;
            int keep = min(dp3, left);
            dp3 = keep + dp2;//更新为以x结尾的子序列数目
            dp2 = dp1;
            dp1 = left - keep;
        }
    }
    return dp1 == 0 && dp2 == 0;
}

int main()
{
    vector<int> vi{1,2,3,3,4,5};
    cout<<isPossible_greedy(vi);
}
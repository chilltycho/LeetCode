#include <deque>
#include <iostream>
#include <vector>
using namespace std;
/**
 * 设当前滑动窗口下标i，j。i<j，i对应元素不大于j。窗口向右移动时，只要i
 * 还在窗口中，j一定也在窗口中。因此nums[i]一定不是窗口最大值，可删除
 * 使用队列存储所有还没被移出的下标，下标按从小到大存储，对应值严格单调
 * 递减。
*/
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (nums.empty() || k == 0)
        return vector<int>{};
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && dq.back() < nums[i])
            dq.pop_back();
        dq.push_back(nums[i]);
    }
    vector<int> res(nums.size() - k + 1);
    res[0] = dq.front();
    for (int i = k; i < nums.size(); i++)
    {
        //滑动窗口已经略过队列中头部元素
        if (dq.front() == nums[i - k])
            dq.pop_front();
        while (!dq.empty() && dq.back() < nums[i])
            dq.pop_back();
        dq.push_back(nums[i]);
        res[i - k + 1] = dq.front();
    }
    return res;
}

int main()
{
    vector<int> nums{1, 3, -1, -3, 5, 4, 6, 7};
    auto res = maxSlidingWindow(nums, 3);
    for (auto &c : res)
        cout << c << ' ';
}
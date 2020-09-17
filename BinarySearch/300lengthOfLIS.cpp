/*给定无序整数数组，找到其中最长上升子序列（可不连续）长度
[10,9,2,5,3,7,101,18] [2,3,7,101]*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
//可使用动态规划O(n^2)
/*贪心算法：若已得到的上升子序列结尾的数越小，遍历时后接一个数，更有可能构成更长上升自序列
tail[i]表示长度为i+1的所有上升子序列的结尾的最小值

*/
int lengthOfLIS(vector<int> &nums)
{
    int len = nums.size();
    if (len <= 1)
        return len;
    vector<int> tail(len);
    tail[0] = nums[0];
    int end = 0; //tail最后一个已赋值元素的索引
    for (int i = 1; i < len; i++)
    {
        if (nums[i] > tail[end])//直接添加到tail末尾
        {
            end++;
            tail[end] = nums[i];
        }
        else//tail数组为上升序，可用二分法搜索应该替换的较大元素
        {
            int left = 0;
            int right = end;
            while (left < right)
            {
                int mid = left + (right - left) / 2;
                if (tail[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid;
            }
            tail[left] = nums[i];
        }
    }
    end++;//求长度，+1
    return end;
}

int main()
{
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    assert(4 == lengthOfLIS(nums));
}
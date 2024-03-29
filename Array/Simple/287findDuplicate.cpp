/*给定包含n+1个整数的数组nums,数字[1,n]，至少存在一个重复整数，假设只有一个，找出重复数
1.不能更改原数组 2.只能使用额外的O(1)空间*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
int findDuplicate(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        while (nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != i + 1)
            return nums[i];
    }
    return -1;
}

/*快慢指针[1,2,3,4,5,6,7,8,9,5],按路径point=0; point=nums[point]移动,
陷入循环1,2,3,4,5,[6,7,8,9],[6,7,8,9]
设置快指针f(每次走两步),慢指针s(每次走一步),fs相遇时,s在环中前进距离为n-m.在让s
前进m步,则s回到环入口.*/
int findDuplicate_fs(vector<int> &nums)
{
    int fast = 0, slow = 0;
    while (true)
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
        if (fast == slow)
            break;
    }
    int finder = 0; //用于寻找环起点
    while (true)
    {
        finder = nums[finder];
        slow = nums[slow];
        if (slow == finder)
            break;
    }
    return slow;
}

int main()
{
    vector<int> nums{1, 3, 4, 2, 2};
    assert(2 == findDuplicate(nums));
    vector<int> nums1{3, 1, 3, 4, 2};
    assert(3 == findDuplicate(nums1));
}
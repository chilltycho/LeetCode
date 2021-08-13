#include <iostream>
#include <vector>
using namespace std;
/**
 * 最好O(n)，最坏O(n^2)
 * 冒泡：比较相邻，若不是递增，则交换。每次把较大地放到最后，稳定排序，不改变相对顺序
*/
void bubbleSort(vector<int> &nums)
{
    auto len = nums.size();
    for (int i = len - 1; i >= 0; i--) //需比较次数
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

int main()
{
    vector<int> vi{4, 7, 2, 3, 5, 1, 8, 6};
    bubbleSort(vi);
    for (auto c : vi)
        cout << c << ' ';
}
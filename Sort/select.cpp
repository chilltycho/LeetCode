//时间复杂度：O(N^2) 空间复杂度O(1)
#include <vector>
#include <iostream>
using namespace std;
void selectSort(vector<int> &nums)
{
    auto len = nums.size();
    //循环不变量：[0,i)有序
    for (size_t i = 0; i < len - 1; i++)
    {
        //选择[i,len-1]最小元素索引，交换到i
        size_t minIndex = i;
        for (size_t j = i + 1; j < len; j++)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}

int main()
{
    vector<int> vi{2, 1, 5, 3};
    selectSort(vi);
    for (auto c : vi)
        cout << c << " ";
}
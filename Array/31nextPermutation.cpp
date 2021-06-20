//获取下一排列，当不存在下一个更大排列时（逆序），返回正序[1,2,3]->[1,3,2]->[2,1,3]->[2,3,1]->[3,1,2]->[3,2,1]->[1,2,3]
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*下一排列总比当前排列大，除非当前排列已经是最大排列，将后面[大数]与前面[小数]交换。
1.增加幅度尽可能小，在尽可能靠右的地方进行交换，从后向前找
2.将尽可能小的[大数],与前面[小数]交换。123465将5与4交换
3.将[大数]换到前面后，将[大数]后面的数重置为升序，升序就是最小的排列123465交换后123564排序123546*/
void nextPermutation(vector<int> &nums)
{
    if (nums.size() < 2)
        return;
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--; //小数,降序前第一个数，123465中4
    if (i >= 0)
    {
        int j = nums.size() - 1; //大数，123465中5
        while (j >= 0 && nums[i] >= nums[j])
            j--;
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

int main()
{
    vector<int> vi{1, 4, 3, 2};
    nextPermutation(vi);
    for (auto c : vi)
        cout << c << ' ';
}
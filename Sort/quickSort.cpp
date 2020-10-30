#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[left]; //基准值
    int lt = left;          //less than
    //循环不变量：确保[left+1,lt]<pivot, [lt+1,i]>=pivot
    for (int i = left + 1; i <= right; i++)
    {
        if (pivot > nums[i])
        {
            lt++;
            swap(nums[i], nums[lt]);
        }
    }
    swap(nums[left], nums[lt]);
    return lt;
}
void quickSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return; //小区间使用插入排序可提高效率
    int pIndex = partition(nums, left, right);
    quickSort(nums, left, pIndex - 1);
    quickSort(nums, pIndex + 1, right);
}

int partition_2(vector<int> &nums, int left, int right)
{
    int pivot = nums[left];
    int lt = left + 1;
    int gt = right;
    //确保[lt,pivot,gt]
    while (true)
    {
        while (lt <= right && nums[lt] < pivot) //左指针右移直到有元素小于哨值
            lt++;
        while (gt > left && nums[gt] > pivot) //右指针左移直到有元素大于哨值
            gt--;
        if (lt >= gt) //只有当lt<gt时才交换左右指针
            break;
        swap(nums[lt], nums[gt]);
        lt++;
        gt--;
    }
    swap(nums[left],nums[gt]); //交换哨值
    return gt;
}

//若包含大量重复元素，则中间元素将使递归过程不平衡,两路快排
void quickSort_2ways(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int pIndex = partition_2(nums, left, right);
    quickSort_2ways(nums, left, pIndex - 1);
    quickSort_2ways(nums, pIndex + 1, right);
}

//3路快排，小于，等于，大于
pair<int, int> partition_3(vector<int> &nums, int left, int right)
{
    int pivot = nums[left];
    int lt = left;
    int gt = right + 1;

    int i = left + 1;
    while (i < gt)
    {
        if (nums[i] < pivot)
        {
            lt++;
            swap(nums[i], nums[lt]);
            i++;
        }
        else if (nums[i] == pivot)
            i++;
        else
        {
            gt--;
            swap(nums[i], nums[gt]);
        }
    }
    swap(nums[left], nums[lt]);
    return make_pair(lt, gt);
}

void quickSort_3ways(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    auto lg = partition_3(nums, left, right);
    quickSort_3ways(nums, left, lg.first - 1);
    quickSort_3ways(nums, lg.second, right);
}

int main()
{
    vector<int> nums{3, 4, 1, 2, 5};
    quickSort(nums, 0, nums.size() - 1);
    for (auto c : nums)
        cout << c << ' ';
}
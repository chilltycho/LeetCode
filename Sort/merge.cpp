#include <iostream>
#include <vector>
using namespace std;
//将已排好序的数组合并，nums[lef,...mid]和nums[mid+1,right]
void mergeTwoSortedArray(vector<int> &nums, int left, int mid, int right)
{
    int length = right - left + 1;
    vector<int> temp(length, 0);
    for (int i = 0; i < length; i++)
        temp[i] = nums[left + i];//复制元素
    int l = 0;//左边数组指针
    int r = mid - left + 1;//右边数组指针
    for (int i = 0; i < length; i++)//需复制次数
    {
        if (l > mid - left)//左边数组耗尽，则复制右边数组
        {
            nums[i + left] = temp[r];
            r++;
        }
        else if (r > length - 1)//右边数组耗尽
        {
            nums[i + left] = temp[l];
            l++;
        }
        else if (temp[l] < temp[r])//左边指针较小，复制左边
        {
            nums[i + left] = temp[l];
            l++;
        }
        else//右边指针较小
        {
            nums[i + left] = temp[r];
            r++;
        }
    }
}

void mergeSort(vector<int> &nums, int left, int right)
{
    //只有一个元素时，无需操作
    if (left >= right)
        return;
    //int mid=(left+right)/2;//left+right可能溢出
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    mergeTwoSortedArray(nums, left, mid, right);
}

int main()
{
    vector<int> vi{8, 7, 6, 5, 4, 3, 2, 1};
    mergeSort(vi, 0, vi.size() - 1);
    for (auto c : vi)
        cout << c << ' ';
}
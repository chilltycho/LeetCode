//输入整数数组，找出最小的k个数
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> getLeastNumbers(vector<int> &arr, int k)
{
    priority_queue<int> mq;
    for (int i = 0; i < k; i++)
        mq.push(arr[i]);
    for (int i = k; i < arr.size(); i++)
    {
        if (mq.top() > arr[i])
        {
            mq.pop();
            mq.push(arr[i]);
        }
    }
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(mq.top());
        mq.pop();
    }
    return res;
}

//快排思想
int partition(vector<int> &nums, int l, int r)
{
    int pivot = nums[l]; //基准值
    int lt = l;          //less than
    //循环不变量：确保[left+1,lt]<pivot, [lt+1,i]>=pivot
    for (int i = l + 1; i <= r; i++)
    {
        if (pivot > nums[i])
        {
            lt++;
            swap(nums[i], nums[lt]);
        }
    }
    swap(nums[l], nums[lt]);
    return lt;
}

void select(vector<int> &arr, int l, int r, int k)
{
    if (l >= r)
        return;
    int pos = partition(arr, l, r);
    int num = pos - l + 1;
    if (k == num)
        return;
    else if (k < num)
        select(arr, l, pos - 1, k);
    else
        select(arr, pos + 1, r, k - num);
}

vector<int> getLeastNumbers_1(vector<int> &arr, int k)
{
    select(arr, 0, arr.size() - 1, k);
    vector<int> res;
    for (int i = 0; i < k; i++)
        res.push_back(arr[i]);
    return res;
}

int main()
{
    vector<int> vi{3, 2, 2, 3, 4, 5};
    auto res = getLeastNumbers_1(vi, 2);
    for (auto &c : res)
        cout << c << ' ';
}

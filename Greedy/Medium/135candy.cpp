/*每个孩子至少分配到 1 个糖果。
评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。*/
#include<iostream>
#include<vector>
using namespace std;
int candy(vector<int> &ratings)
{

    vector<int> left(ratings.size(), 1);
    auto right = left;
    int len = ratings.size();
    for (int i = 1; i < len; i++) // 从左往右，和左边的比
    {
        if (ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;
    }
    int res = left[len - 1];
    for (int i = len - 2; i >= 0; i--) // 从右往左，和右边的比
    {
        if (ratings[i] > ratings[i + 1])
            right[i] = right[i + 1] + 1;
        res += max(right[i], left[i]);
    }
    return res;
}
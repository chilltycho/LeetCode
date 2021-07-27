//N个孩子站一条直线，每个孩子至少一颗糖。相邻孩子，评分高的必须获得更多的糖果
#include <vector>
using namespace std;
/* 假设学生A和B左右相邻
左规则：rB>rA时，B比A多
右规则：rA>rB时，A比B多
先从左到右，所有学生一颗糖，满足左规则。
再从右到左，满足右规则。
结果取最大的
*/
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
// 常数空间
/*
* 从左到右枚举每位同学，记前一个同学糖果为pre：
1. 当前同学比上位同学评分高，在最近的递增序列，分配该同学pre+1
2. 否则递减序列，直接给1颗糖果，且该同学所在递减序列中所有同学多分配1颗
只需记录当前递减序列长度dec，最近的递增序列长度inc和前一个同学糖果数量pre
*/
int candy_1(vector<int> &ratings)
{
    int n = ratings.size();
    int res = 1;
    int inc = 1, dec = 0, pre = 1;
    for (int i = 1; i < n; ++i)
    {
        if (ratings[i] >= ratings[i - 1])
        {
            dec = 0;
            pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
            res += pre;
            inc = pre;
        }
        else
        {
            ++dec;
            if (dec == inc) // 递减序列长度和上个递增序列等长，将最近递增序列最后一位同学并进递减序列
                ++dec;
            res += dec;
            pre = 1;
        }
    }
    return res;
}
int main()
{
}
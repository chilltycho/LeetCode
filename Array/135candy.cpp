//N个孩子站一条直线，每个孩子至少一颗糖。相邻孩子，评分高的必须获得更多的糖果
#include <vector>
using namespace std;
/*当ratings[i-1]<ratings[i]时，i号学生糖果数比i-1号多
当ratings[i]>ratings[i+1]时，i号比i+1号多*/
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> left(n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;
    }
    int right = 0, ret = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1 && ratings[i] > ratings[i + 1])
            right++;
        else
            right = 1;
        ret += max(left[i], right);
    }
    return ret;
}
//从左到右枚举，记前一个同学糖果数量为pre，若当前同学比上一个同学评分高，pre+1
//否则在一个递减数列中，直接给当前同学一颗糖果，把当前所在递减序列中所有同学再多分配一颗糖果
int candy_1(vector<int> &ratings)
{
    int n = ratings.size();
    int ret = 1;
    int inc = 1, dec = 0, pre = 1;
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] >= ratings[i - 1])
        {
            dec = 0;
            pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
            ret += pre;
            inc = pre;
        }
        else
        {
            dec++;
            if (dec == inc)
                dec++;
            ret += dec;
            pre = 1;
        }
    }
    return ret;
}
int main()
{
}
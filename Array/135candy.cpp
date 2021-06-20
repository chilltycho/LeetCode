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
    vector<int> left(ratings.size(),1);
    auto right = left;
    int len = ratings.size();
    for(int i=1;i<len;i++) // 从左往右，和左边的比
    {
        if(ratings[i]>ratings[i-1])
            left[i]=left[i-1]+1;
    }
    int res=left[len-1];
    for(int i=len-2;i>=0;i--) // 从右往左，和右边的比
    {
        if(ratings[i]>ratings[i+1])
            right[i]=right[i+1]+1;
        res+=max(right[i],left[i]);
    }
    return res;
}
int main()
{
}
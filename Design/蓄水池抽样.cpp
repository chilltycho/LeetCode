/*
从未知大小的数据流中随机选取k个数据，保证每个数据被抽到概率相等
*/

//k=1
/*
遇到1，概率为1，保留第一个数
遇到2，概率1/2，1和2各1/2概率被保留
遇到3，概率1/3，2/3概率1保留，1被保留总概率1/2 * 2/3 = 1/3
遇到4，概率1/4，3/4概率1保留，1被保留总概率3/4 * 2/3 * 1/2 = 1/4
*/

//k=m
/*
对前k个数，全部保留
对第k+1个数，以k/k+1概率保留，之前任意一个数能保留概率=上轮保留概率1 * 第k+1个数丢弃1-(k/k+1) + 不被替换(1-1/k) * 第k+1个数留k/(k+1)
对第k+2个数，以k/k+2概率保留，之前任意一个数能保留概率=上轮保留概率k/(k+1) * 2/(k+2) + k/k+1 * k-1/k+2
总结，对前k个数，全部保留，对第i(i>k)个数，以k/i的概率保留第i个数，并以1/k的概率与前面已选择的任意一个替换
*/
#include <random>
using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode(int v) : val(v), next(nullptr) {}
};

int getRandom(ListNode *head)
{
    auto phead = head;
    int val = phead->val;
    int count = 1;
    while (phead)
    {
        if (rand() % count++ == 0)
            val = phead->val;
        phead = phead->next;
    }
    return val;
}
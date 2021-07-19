#include <vector>
using namespace std;
/**
 * 堆排序思想：将待排序列先构造一个最大堆，堆顶元素即为最大值，然后移走堆顶元素，调整剩余元素为最大堆，如此反复执行，便得到有序序列
 * 
 * 建立堆的过程是nlogn,遍历所有非叶子结点，将其和子树调整为最大堆
 * 由数组变为最大堆有两种方式，一种是逐个插入（O(n)），一种是heapify(从第一个非叶子结点开始调整，bottom to up)（O(1)）
*/
void heap_sort(vector<int> &a)
{
    int len = a.size();
    build_max_heap(a, len);
    for (int i = len - 1; i >= 1; i--)
    {
        //将堆顶的元素和最后一个元素交换位置
        swap(a[0], a[i]);

        //每次将数组前面的部分再调整为最大堆，后续调整的时候传进去的就是当前数组能取到的最大下标了，因为i赋初值时已经解决
        heapadjust(a, 0, i - 1);
    }
}

//建堆的意思是将数组转换成最大堆
//本质：从下往上，从右往左，将每个非叶子结点当做根节点，将其和子树调整成最大堆，首先找到最后一个叶子结点的父节点len / 2 - 1
//最大堆，每个结点都大于等于左右孩子结点的值
void build_max_heap(vector<int> &a, int len)
{ //建堆
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        heapadjust(a, i, len - 1); //建堆的时候应该传进去len-1，即当前数组能取到的最大下标，即保证堆调整过程中左右孩子不会数组越界
    }
}

//以i当做根节点，调整其和其子树为最大堆
void heapadjust(vector<int> &a, int i, int len)
{
    int temp, j;
    temp = a[i];

    //当前结点为j，左孩子序号是2*i，右孩子序号是2*i+1
    //这里的结点从0开始，不是从1开始，因此左孩子序号是2*i + 1，右孩子序号是2*i+2
    for (j = 2 * i + 1; j <= len; j *= 2)
    {
        //先比较左右孩子,找到左右孩子中较大的那个
        if (j < len && a[j] < a[j + 1])
            ++j;

        //如果左右孩子中最大值小于当前值，则不需要移动
        if (a[j] <= temp)
            break;
        //若最大值大于当前值，需要将最大值往前移动，赋给i位置
        //此时不要动j，直到找到j所在位置再赋值
        a[i] = a[j];

        //将当前值和左右孩子比较后，若移动了，则继续往下比较，将j向下移动到刚才较大的孩子处
        i = j;
    }
    //直到找到temp的合适位置
    a[i] = temp;
}

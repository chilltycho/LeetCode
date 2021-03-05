// 判断数组是否为二叉树后序遍历
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

// 时间复杂度O(N^2)每次helper减去根节点
bool helper(vector<int> &po, int l, int r)
{
    if (l >= r)
        return true;
    int m = l;
    while (po[m] < po[r])
        ++m;
    int tm = m;
    for (int i = m; m < r; ++m)
        if (po[m] < po[r])
            return false;
    return helper(po, l, tm - 1) && helper(po, tm, r - 1);
}
//左右根，数组中最后数一定为根节点
bool verifyPostorder(vector<int> &postorder)
{
    return helper(postorder, 0, postorder.size() - 1);
}

/**
 * 假设后序[3,6,5,9,8,11,13,12,10] 左右根
 * 逆序[10,12,13,11,8,9,5,6,3] arr 根右左
 * 如果arr[i]<arr[i+1],arr[i+1]为arr[i]右子节点。如10,12
 * 如果arr[i]>a[i+1]则arr[i+1]为arr[0]...arr[i]中左子节点
*/
bool verifyPostOrder_s(vector<int> &postorder)
{
    stack<int> si;
    int parent = __INT_MAX__;
    for (int i = postorder.size() - 1; i >= 0; --i)
    {
        int cur = postorder[i];
        // 倒序，应找到父节点
        while (!si.empty() && si.top() > cur)
        {
            parent = si.top();
            si.pop();
        }
        if (cur > parent)
            return false;
        si.push(cur);
    }
    return true;
}
int main()
{
    vector<int> vi{3, 5, 4, 10, 12, 9};
    assert(verifyPostorder(vi));
    vector<int> vi1{1, 3, 2, 6, 5};
    assert(verifyPostorder(vi1));
}
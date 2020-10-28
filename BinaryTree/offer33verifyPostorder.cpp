//判断数组是否为二叉搜索树后序遍历结果
#include <vector>
#include <cassert>
using namespace std;
bool helper(vector<int> &postorder, int left, int right)
{
    if (left >= right)
        return true;
    int mid = left;
    int root = postorder[right];
    while (postorder[mid] < root)
        mid++;
    int temp = mid;//第一个比根节点大的
    while (temp < right)
    {//右子树中存在比根节点小的，false
        if (postorder[temp++] < root) 
            return false;
    }
    return helper(postorder, left, mid - 1) && helper(postorder, mid, right - 1);
}
//左右根，数组中最后数一定为根节点
bool verifyPostorder(vector<int> &postorder)
{
    return helper(postorder, 0, postorder.size() - 1);
}

int main()
{ //9为根节点，第一个比9大的为10,则[10,12]为9右子树，之前为9左子树。对左右子树相同判断
    vector<int> vi{3, 5, 4, 10, 12, 9};
    assert(verifyPostorder(vi));
    vector<int> vi1{1, 3, 2, 6, 5};
    assert(verifyPostorder(vi1));
}
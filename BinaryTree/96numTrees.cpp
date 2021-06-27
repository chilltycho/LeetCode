//给定整数n，求以1..n为节点组成的二叉搜索数有多少种。
#include <iostream>
#include <vector>
using namespace std;
/*遍历每个数字i，作为树根，将1..(i-1)作为左子树，将(i+1)..n作为右子树
G(n)为长度n的序列能构成的不同二叉搜索树的个数
F(i,n)为以i为根，序列长度n的不同二叉搜索树个数。
G(n)=sum(F(i,n)) i=1,..,n
F(i,n)=G(i-1)G(n-i)*/
int numTrees(int n)
{
    vector<int> G(n + 1, 0);
    G[0] = 1;
    G[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
}
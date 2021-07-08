#include "TreeNode.h"
using namespace std;

int main()
{
    vector<int> vi{1, 2, 3, -1, 4, 5, 6};
    auto t = vecToTree(vi);
    auto res = inorder(t);
    for (auto c : res)
        cout << c << ' ';
}
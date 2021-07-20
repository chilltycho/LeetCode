#include "TreeNode.h"
using namespace std;

int main()
{
    vector<int> vi{9, 4, 10, 3, 5, -1, 12};
    auto t = vecToTree(vi);
    auto res = inorder(t);
    for (auto c : res)
        cout << c << ' ';
}
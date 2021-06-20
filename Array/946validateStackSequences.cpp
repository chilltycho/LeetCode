//给定栈pushed、popped数组，判断popped是否合理
#include <vector>
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <stack>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> si;
    int i = 0;
    for (const auto &num : pushed)
    {
        si.push(num);
        while (!si.empty() && si.top() == popped[i])
        {
            si.pop();
            i++;
        }
    }
    return si.empty();
}

bool validate(vector<int> &pushed, vector<int> &popped)
{
    int n = pushed.size();
    int s = 0;
    for (int i = 0, j = 0; j < n;)
    {
        // 栈顶元素不是当前popped序列所处理的那个或栈空，从pushed序列取元素入栈
        while (i < n && (s == 0 || pushed[s - 1] != popped[j]))
            pushed[s++] = pushed[i++];
        // 出栈序列用完了都得不到出栈序列元素
        if (i == n && pushed[s - 1] != popped[j])
            return false;
        while (j < n && s > 0 && pushed[s - 1] == popped[j])
        {
            --s;
            ++j;
        }
    }
    return true;
}

int main()
{
    vector<int> pu1{1, 2, 3, 4, 5};
    vector<int> po1{4, 5, 3, 2, 1};
    assert(validateStackSequences(pu1, po1));

    vector<int> pu2{1, 2, 3, 4, 5};
    vector<int> po2{4, 3, 5, 1, 2};
    assert(!validateStackSequences(pu2, po2));
}

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
    int i=0;
    for(const auto& num:pushed)
    {
        si.push(num);
        while(!si.empty()&&si.top()==popped[i])
        {
            si.pop();
            i++;
        }
    }
    return si.empty();
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

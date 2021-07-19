#include<stack>
using namespace std;
stack<int> si;
stack<int> mins;
void push(int value)
{
    si.push(value);
    if (mins.empty() || mins.top() > value)
        mins.push(value);
    else
        mins.push(mins.top());
}
void pop()
{
    si.pop();
    mins.pop();
}
int top()
{
    return si.top();
}
int min()
{
    return mins.top();
}
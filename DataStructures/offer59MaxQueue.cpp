/*实现队列并实现函数`max_value`得到队列里最大值，要求max_value, push_back,pop_front均摊时间
复杂度都是O(1)。*/
#include <queue>
#include <deque>
#include <iostream>
using namespace std;
class MaxQueue
{
private:
    queue<int> q;
    deque<int> d;

public:
    int max_value()
    {
        if (d.empty())
            return -1;
        return d.front();
    }
    void push_back(int value)
    {
        while (!d.empty() && d.back() < value)
        {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    int pop_front()
    {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == d.front())
            d.pop_front();
        q.pop();
        return ans;
    }
};

int main()
{
    cout << 3 % 2 << endl;
}
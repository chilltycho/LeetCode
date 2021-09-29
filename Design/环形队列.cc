#include <bits/stdc++.h>
using namespace std;
class CircleQueue
{
private:
    long d_rear, d_front;
    size_t d_size;
    size_t d_maxsize;
    int *d_arr;

public:
    CircleQueue()
    {
        d_front = d_rear = -1;
        d_maxsize = 15;
        d_size = 0;
        d_arr = new int[15];
    }
    ~CircleQueue()
    {
        delete[] d_arr;
    }
    bool is_full() const
    {
        return (d_rear == d_maxsize - 1 && d_front == 0) || (d_rear == d_front - 1);
    }
    bool is_empty() const
    {
        return d_front == -1 || d_rear == -1;
    }
    void enqueue(const int &value)
    {
        if (is_full())
        {
            cout << "enqueue in full CircleQueue" << endl;
            return;
        }
        else if (d_front == -1)
        {
            d_rear = d_front = 0;
        }
        else if (d_rear == d_maxsize - 1 && d_front != 0)
        {
            d_rear = 0;
        }
        else
        {
            ++d_rear;
        }
        d_arr[d_rear] = value;
        ++d_size;
    }
    int deque()
    {
        if (is_empty())
        {
            cout << "deque on empty circlequeue" << endl;
            return -1;
        }
        int res = d_arr[d_front];
        if (d_front == d_rear)
        {
            d_rear = -1;
            d_front = -1;
        }
        else if (d_front == d_size - 1)
        {
            d_front = 0;
        }
        else
        {
            ++d_front;
        }
        --d_size;
        return res;
    }
};
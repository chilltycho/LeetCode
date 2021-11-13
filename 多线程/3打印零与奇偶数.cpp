#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <future>
using namespace std;
// A调用zero，B调用even，C调用odd。输出010203040506, 长度2n
class ZeroEvenOdd
{
    int n;
    int flag = 0;
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int _n) : n(_n) {}
    void zero()
    {
        for (int i = 1; i <= n; ++i)
        {
            unique_lock<mutex> l(m);
            cv.wait(l, [this]
                    { return !flag; });
            cout << 0;
            cout.flush();
            if (i % 2 == 0)
            {
                flag = 2;
            }
            else
            {
                flag = 1;
            }
            cv.notify_all();
        }
    }
    void even()
    {
        for (int i = 2; i <= n; i += 2)
        {
            unique_lock<mutex> l(m);
            cv.wait(l, [this]
                    { return flag == 2; });
            cout << i;
            cout.flush();
            flag = 0;
            cv.notify_all();
        }
    }
    void odd()
    {
        for (int i = 1; i <= n; i += 2)
        {
            unique_lock<mutex> l(m);
            cv.wait(l, [this]
                    { return flag == 1; });
            cout << i;
            cout.flush();
            flag = 0;
            cv.notify_all();
        }
    }
};
int main()
{
    ZeroEvenOdd z(2);
    auto f1 = async(launch::async, [&z]()
                    { z.zero(); });
    auto f2 = async(launch::async, [&z]()
                    { z.odd(); });
    auto f3 = async(launch::async, [&z]()
                    { z.even(); });
    f1.get();
    f2.get();
    f3.get();
}
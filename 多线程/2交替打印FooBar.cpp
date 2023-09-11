#include <iostream>
#include <mutex>
#include <condition_variable>
#include <future>
#include <thread>
using namespace std;
// 两个线程公用一个实例，一个调用foo，一个调用bar。确保foobar输出n次
class FooBar
{
    int n;
    bool fo = true;
    mutex m;
    condition_variable cv;

public:
    FooBar(int _n) : n(_n) {}
    void foo()
    {
        for (int i = 0; i < n; ++i) // 下面未对i进行修改
        {
            {
                unique_lock<mutex> ul(m);
                cv.wait(ul, [this]()
                        { return fo; });
                cout << "foo \n";
                cout.flush();
                fo = false;
            }
            cv.notify_all();
        }
    }
    void bar()
    {
        for (int i = 0; i < n; ++i)
        {
            {
                unique_lock<mutex> ul(m);
                cv.wait(ul, [this]()
                        { return !fo; });
                cout << "bar \n";
                cout.flush();
                fo = true;
            }
            cv.notify_all();
        }
    }
};

int main()
{
    FooBar f(3);
    auto f1 = async(launch::async, [&f]()
                    { f.foo(); });
    auto f2 = async(launch::async, [&f]()
                    { f.bar(); });
    f1.get();
    f2.get();
}
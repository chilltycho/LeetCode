/**
 * 如果可被3整除，输出"fizz"，
 * 如果可被5整除，buzz，
 * 如果同时可被3和5整除，输出fizzbuzz
 * 否则输出数字
 */
#include <thread>
#include <functional>
#include <iostream>
#include <condition_variable>
#include <future>
using namespace std;
class FizzBuzz
{
private:
    int n;
    int cur = 1;
    condition_variable cv;
    mutex m;

public:
    FizzBuzz(int nn)
    {
        n = nn;
    }

    void fizz()
    {

        while (true)
        {
            unique_lock<mutex> l(m);
            cv.wait(l, [this]
                    { return cur > n || cur % 3 == 0 && cur % 5 != 0; });
            if (cur > n)
                break;
            cout << "fizz, ";
            cout.flush();
            ++cur;
            cv.notify_all();
        }
    }

    void buzz()
    {

        while (true)
        {
            unique_lock<mutex> l(m);
            cv.wait(l, [this]
                    { return cur > n || cur % 3 != 0 && cur % 5 == 0; });
            if (cur > n)
                break;
            cout << "buzz, ";
            cout.flush();
            ++cur;
            cv.notify_all();
        }
    }

    void fizzbuzz()
    {

        while (true)
        {
            unique_lock<mutex> l(m);
            cv.wait(l, [this]
                    { return cur > n || cur % 3 == 0 && cur % 5 == 0; });
            if (cur > n)
                break;
            cout << "fizzbuzz, ";
            cout.flush();
            ++cur;
            cv.notify_all();
        }
    }

    void number()
    {

        while (true)
        {
            unique_lock<mutex> l(m);
            cv.wait(l, [this]
                    { return cur > n || cur % 3 != 0 && cur % 5 != 0; });
            if (cur > n)
                break;
            cout << cur << ", ";
            cout.flush();
            ++cur;
            cv.notify_all();
        }
    }
};

int main()
{
    FizzBuzz f(15);
    auto f1 = async(launch::async, [&f]
                    { f.buzz(); });
    auto f2 = async(launch::async, [&f]
                    { f.fizzbuzz(); });
    auto f3 = async(launch::async, [&f]
                    { f.fizz(); });
    auto f4 = async(launch::async, [&f]
                    { f.number(); });
    f1.get();
    f2.get();
    f3.get();
    f4.get();
}
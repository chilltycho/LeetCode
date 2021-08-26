/*
 * 如果可被3整除，输出"fizz"，如果可被5整除，buzz，如果同时可被3和5整除，输出fizzbuzz
 */
#include <thread>
#include <functional>
#include <iostream>
#include <condition_variable>
using namespace std;
class FizzBuzz
{
private:
    int n;
    int num;
    condition_variable cv;
    mutex m;

public:
    FizzBuzz(int nn)
    {
        n = nn;
        num = 1;
    }

    void fizz(function<void()> printFizz)
    {
        unique_lock<mutex> guard(m);
        while (num <= n)
        {
            if (num % 3 == 0 && num % 5 != 0)
            {
                printFizz();
                ++num;
                cv.notify_all();
            }
            cv.wait(guard, [this]
                    { return (num > n) || (num % 3 == 0 && num % 5 != 0); });
        }
    }

    void buzz(function<void()> printBuzz)
    {
        unique_lock<mutex> guard(m);
        while (num <= n)
        {
            if (num % 5 == 0 && num % 3 != 0)
            {
                printBuzz();
                ++num;
                cv.notify_all();
            }
            cv.wait(guard, [this]
                    { return (num > n) || (num % 5 == 0 && num % 3 != 0); });
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz)
    {
        unique_lock<mutex> guard(m);
        while (num <= n)
        {
            if (num % 5 == 0 && num % 3 != 0)
            {
                printFizzBuzz();
                ++num;
                cv.notify_all();
            }
            cv.wait(guard, [this]
                    { return (num > n) || (num % 3 == 0 && num % 5 == 0); });
        }
    }

    void number(function<void(int)> printNumber)
    {
        unique_lock<mutex> guard(m);
        while (num <= n)
        {
            if (num % 3 != 0 && num % 5 != 0)
            {
                printNumber(num);
                ++num;
                if (num > n)
                {
                    cv.notify_all();
                    break;
                }
                if (num % 3 != 0 && num % 5 != 0)
                {
                    continue;
                }
                else
                {
                    cv.notify_all();
                }
            }
            cv.wait(guard, [this]
                    { return (num > n) || (num % 3 != 0 && num % 5 != 0); });
        }
    }
};

int main()
{
    FizzBuzz fz(10);

    function<void()> fizz = []()
    {
        cout << "fizz" << endl;
    };

    function<void()> buzz = []()
    {
        cout << "buzz" << endl;
    };

    function<void()> fizzbuzz = []()
    {
        cout << "fizzbuzz" << endl;
    };

    function<void(int)> num = [](int n)
    {
        cout << n << endl;
    };

    thread th1([&]()
               { fz.fizz(fizz); });
    thread th2([&]()
               { fz.buzz(buzz); });
    thread th3([&]()
               { fz.fizzbuzz(fizzbuzz); });
    thread th4([&]()
               { fz.number(num); });
    th1.join();
    th2.join();
    th3.join();
    th4.join();

    return 0;
}
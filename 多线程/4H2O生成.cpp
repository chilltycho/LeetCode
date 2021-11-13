#include <iostream>
#include <future>
#include <thread>
#include <condition_variable>
using namespace std;
/**
 * 组织两线程hydrogen，oxygen产生是u分子。存在屏障使得每个线程必须等待直到一个完整水分子生成
 * 氢和氧分别给release允许突破屏障。
 * 如果氧线程到达屏障而没有氢线程到达，需等待直到两个氢气线程到达
 * 如果氢线程到达屏障而没有其他线程到达，需等待直到一个氧线程和一个氢线程到达
*/
class H2O
{
    int h = 0;
    mutex m;
    condition_variable cv;

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen)
    {
        unique_lock<mutex> l(m);
        cv.wait(l, [this]
                { return h < 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++h;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        unique_lock<mutex> l(m);
        cv.wait(l, [this]
                { return h == 2; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        h = 0;
        cv.notify_all();
    }
};
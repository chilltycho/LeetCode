#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

static int avail = 0;
mutex mutex_;
condition_variable cv;

void producer() {
  while (true) {
    unique_lock<mutex> guard(mutex_);
    ++avail;
    cv.notify_one();
  }
}

void consumer() {
  while (true) {
    unique_lock<mutex> guard(mutex_);
    // 必须while不能if，wait返回时不能确定条件状态，应该立即重新检查判断条件。wait返回时，可能多个线程等待，其他线程可能先获取了avail。
    while (avail == 0) {
      // 解锁互斥量（让其他线程访问avail）并阻塞
      cv.wait(guard);
    }
    while (avail > 0) {
      --avail;
    }
  }
}

int main() {}
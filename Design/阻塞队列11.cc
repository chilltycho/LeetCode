#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

static int avail = 0;
mutex g_num_mutex;
condition_variable cv;

void producer() {
  while (true) {
    unique_lock<mutex> guard(g_num_mutex);
    ++avail;
    cout << "producing " << avail << endl;
    cv.notify_one();
  }
}

void consumer() {
  while (true) {
    unique_lock<mutex> guard(g_num_mutex);
    while (avail == 0)
      cv.wait(guard);
    while (avail > 0) {
      --avail;
      cout << "consuming " << avail << endl;
    }
  }
}

int main() {
  thread t1(consumer), t2(producer);
  while (true) {
  }
}


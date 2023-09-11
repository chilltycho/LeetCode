#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
// 三个不同线程A，B，C共用一个Foo实例，各调用三个方法。确保执行顺序为first,second,third

class Foo {
private:
  int k = 0;
  condition_variable cv;
  mutex m;

public:
  Foo() = default;
  void first() {
    cout << "first" << endl;
    k = 1;
    cv.notify_all();
  }

  void second() {
    unique_lock<mutex> l(m);
    cv.wait(l, [this]() { return k == 1; });
    k = 2;
    cout << "second" << endl;
    cv.notify_all();
  }

  void third() {
    unique_lock<mutex> l(m);
    cv.wait(l, [this]() { return k == 2; });
    cout << "third" << endl;
    cv.notify_all();
  }
};

int main() {
  Foo f;
  // auto f1 = async(launch::async, &Foo::first, f); //
  // 报错，正复制f，但f内包含mutex，mutex不可复制 f1.get(); 使用lambda解决

  // auto f1 = async(launch::async, [&]
  //                 { f.first(); });

  auto f1 = thread([&] { f.first(); });

  // 使用thread
  auto t2 = thread([&] { f.second(); });
  auto t3 = thread([&] { f.third(); });
  t3.join();
  t2.join();
  f1.join();
}


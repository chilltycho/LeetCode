// 5个哲学家，5个叉子，所有哲学家只会思考或进食，得拿到两个叉才能进食。
// 0-4编号，每个哲学家一个线程，使用类得同一对象模拟该过程。
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>

using namespace std;

class DiningPhilosophers {
private:
  bool isusing[5]{false};
  mutex m;
  condition_variable cv;

public:
  DiningPhilosophers() {}
  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    // 左右边叉子代号
    int l = philosopher;
    int r = (philosopher + 1) % 5;
    unique_lock<mutex> ul(m);
    cv.wait(ul, [&l, &r, this]() { return !isusing[l] && !isusing[r]; });
    isusing[l] = true;
    isusing[r] = true;
    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();
    isusing[l] = false;
    isusing[r] = false;
    cv.notify_all();
  }
};

int main() {
  // 输入：n=1, 每个哲学家需要进餐的次数
  // 输出：[[4,2,1],[4,1,1],[0,1,1],[2,2,1],[2,1,1],[2,0,3]...]
  // 输出表示叉子的控制和进餐的调用，output[i]=[a,b,c] a为哲学家编号，b指定叉子:
  // 1为左，2为右，c指定行为{1拿起，2放下，3吃面}
}
#include <iostream>
#include <mutex>
#include <pthread.h>
#include <thread>
#include <unistd.h>
using namespace std;

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static int avail = 0;

void *producer(void *) {
  while (true) {
    // 生产者
    pthread_mutex_lock(&mtx);
    cout << "producing " << avail << endl;
    avail++;
    pthread_mutex_unlock(&mtx); // 解锁并唤醒一个消费者
    pthread_cond_signal(&cond); // 唤醒至少一个消费者，也可反过来先唤醒再解锁
    // this_thread::sleep_for(chrono::seconds(2));
  }
}

void *consumer(void *) {
  // 消费者
  for (;;) {
    pthread_mutex_lock(&mtx);
    // 必须while不能if，wait返回时不能确定条件状态，应该立即重新检查判断条件。wait返回时，可能多个线程等待，其他线程可能先获取了avail。
    while (avail == 0) {
      // 解锁互斥量（让其他线程访问avail）并阻塞
      pthread_cond_wait(&cond, &mtx);
    }
    // 被唤醒并加锁，因为该线程会立即访问avail
    while (avail > 0) {
      cout << "consuming " << avail << endl;
      avail--;
    }
    pthread_mutex_unlock(&mtx);
  }
}

int main() {
  pthread_t id;
  pthread_create(&id, nullptr, consumer, nullptr);
  pthread_create(&id, nullptr, producer, nullptr);
  while (true) {
  }
}

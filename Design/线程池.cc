#include <condition_variable>
#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

class Task {
public:
  virtual void doIt() { cout << "handle a task..." << endl; }
  virtual ~Task() { cout << "a task destructed..." << endl; }
};

class TaskPool final {
public:
  TaskPool();
  ~TaskPool();
  TaskPool(const TaskPool &) = delete;
  TaskPool &operator=(const TaskPool &) = delete;

  void init(int threadNum = 5);
  void stop();
  void addTask(Task *task);
  void removeAllTasks();

private:
  void threadFunc();
  list<shared_ptr<Task>> m_taskList;
  mutex m_mutexList;
  condition_variable m_cv;
  bool m_bRunning;
  vector<shared_ptr<thread>> m_threads;
};

TaskPool::TaskPool() : m_bRunning(false) {}

TaskPool::~TaskPool() { removeAllTasks(); }

void TaskPool::init(int threadNum) {
  if (threadNum <= 0)
    threadNum = 5;
  m_bRunning = true;
  for (int i = 0; i < threadNum; ++i) {
    shared_ptr<thread> spThread;
    spThread.reset(new thread(bind(&TaskPool::threadFunc, this)));
    m_threads.push_back(spThread);
  }
}

void TaskPool::threadFunc() {
  shared_ptr<Task> spTask;
  while (true) {
    unique_lock<mutex> guard(m_mutexList);
    while (m_taskList.empty()) {
      if (!m_bRunning)
        break;
      m_cv.wait(guard);
    }
    if (!m_bRunning)
      break;
    spTask = m_taskList.front();
    m_taskList.pop_front();
    if (spTask == nullptr)
      continue;
    spTask->doIt();
    spTask.reset();
  }
  cout << "exit thread, threadID: " << this_thread::get_id() << endl;
}

void TaskPool::stop() {
  m_bRunning = false;
  m_cv.notify_all();
  for (auto &iter : m_threads) {
    if (iter->joinable())
      iter->join();
  }
}

void TaskPool::addTask(Task *task) {
  shared_ptr<Task> spTask;
  spTask.reset(task);
  {
    lock_guard<mutex> guard(m_mutexList);
    m_taskList.push_back(spTask);
    cout << "add a Task." << endl;
  }
  m_cv.notify_one();
}

void TaskPool::removeAllTasks() {
  {
    lock_guard<mutex> guard(m_mutexList);
    for (auto &iter : m_taskList)
      iter.reset();
    m_taskList.clear();
  }
}

int main() {
  TaskPool threadPool;
  threadPool.init();
  Task *task = nullptr;
  for (int i = 0; i < 10; ++i) {
    task = new Task();
    threadPool.addTask(task);
  }
  this_thread::sleep_for(chrono::seconds(5));
  threadPool.stop();

  TaskPool p1;
  p1.init();
  Task *t = nullptr;
  for (int i = 0; i < 10; ++i) {
    t = new Task();
    p1.addTask(t);
  }
  this_thread::sleep_for(chrono::seconds(5));
  p1.stop();
}


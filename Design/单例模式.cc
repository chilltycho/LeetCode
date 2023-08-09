#include <iostream>
#include <mutex>
using namespace std;
// 惰性求值，正确销毁，线程安全。
class S {
public:
  static S &getInstance() {
    cout << "initialized" << endl;
    static S instance; // 保证销毁，第一次使用时初始化。
    return instance;
  }

private:
  S() {} // 需要{}，在getInstance里使用。
         // // C++ 03做法
         // S(S const &);              // Don't Implement
         // void operator=(S const &); // Don't implement
public:
  // C++11做法，delete函数声明为public会有更好的错误信息，因为编译器会在删除状态前检查是否能访问。
  S(S const &) = delete;
  S &operator=(S const &) = delete;
};

int main() {
  cout << "start main" << endl;
  S::getInstance();
}

#if 0
// 懒汉，只适合在单线程下，多线程时，考虑两个线程同时首次调用instance，则同时构造实例给p，违反单例
class singleton
{
private:
    singleton() {} // 将构造函数声明为private或protect防止被外部函数实例化，内部有静态类指针保存唯一实例
    static singleton *p;

public:
    static singleton *instance();
};
singleton *singleton::p = nullptr;
singleton *singleton::instance()
{
    if (p == nullptr)
        p = new singleton();
    return p;
}

/*
饿汉，隐藏问题：非静态对象(函数外static对象)在不同编译单元中初始化顺序未定义。
若在初始化完成前调用getinstance()方法会返回未定义实例。
*/
class singleton
{
private:
    singleton() {}
    static singleton *p;

public:
    // main函数执行前，静态变量已经初始化
    static singleton *instance();
};

singleton *singleton::p = new singleton();
singleton *singleton::instance()
{
    return p;
}

// 多线程加锁，lock_guard不用手动管理unlock，效率低，每次调用instance()都会加锁解锁。实际上只有第一次才必要
class singleton
{
private:
    singleton() {}
    static singleton *p;
    static mutex lock_;

public:
    static singleton *instance();
};

singleton *singleton::p = nullptr;

singleton *singleton::instance()
{
    lock_guard<mutex> guard(lock_);
    if (p == nullptr)
        p = new singleton();
    return p;
}

// 双重检查锁模式 DCLP
static pthread_mutex_t _lock = PTHREAD_MUTEX_INITIALIZER;
singleton *singleton::instance()
{
    if (p == nullptr) //第一次检查
    {
        pthread_mutex_lock(&_lock);
        if (p == nullptr) //第二次检查
            p = new singleton();
        pthread_mutex_unlock(&_lock);
    }
    return p;
}

class singleton
{
private:
    singleton() {}
    static singleton *p;
    static mutex lock_;

public:
    singleton *instance();
    // 内嵌垃圾回收类
    class CGar
    {
    public:
        ~CGar()
        {
            if (singleton::p)
                delete singleton::p;
        }
    };
    static CGar Garbo; // 定义静态成员变量，程序结束时，系统自动调用析构函数释放单例对象。
};

singleton *singleton::p = nullptr;
singleton::CGar Garbo;

singleton *singleton::instance()
{
    if (p == nullptr)
    {
        lock_guard<mutex> guard(lock_);
        if (p == nullptr)
            p = new singleton();
    }
    return p;
}
/*大多数情况下对instance调用看到p非空，从而直接返回。若未初始化则获得锁，然后再次检查（双重检查锁）。
第二次检查必要，因为另一个线程可能在第一次检查后获得锁并初始化p。 __内存读写乱序执行（编译器）__。$p = new singleton() $ 将分为三步： 
1. 分配能存储singleton对象的内存 2. 再被分配内存上构造singleton对象 3. 让p指向被分配内存只能保证1最先执行，仅当1，2在3之前执行才正确。
singleton *tmp = static_cast<singleton *>(operator new(sizeof singleton));
new (p) singleton();
p = tmp;
*/

//静态局部变量仅在C++ 11后正确，当一个线程正在初始化一个变量时，其他线程必须等待初始化完成。Effective C++
singleton *
singleton::instance()
{
    static singleton p;
    return &p;
};
#endif
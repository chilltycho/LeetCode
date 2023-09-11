/*
智能指针的设计与实现
智能指针类将一个计数器与类指向的对象相关联，引用计数跟踪该类有多少个对象共享同一指针。
每次创建类的新对象时，初始化指针并将引用计数置为1；
当对象作为另一对象的副本而创建时，拷贝构造函数拷贝指针并增加与之相应的引用计数；
对一个对象进行赋值时，赋值操作符减少左操作数所指对象的引用计数（如果引用计数为减至0，则删除对象），并增加右操作数所指对象的引用计数；
调用析构函数时，构造函数减少引用计数（如果引用计数减至0，则删除基础对象）。
所有的智能指针都会重载 -> 和 *
操作符。智能指针还有许多其他功能，比较有用的是自动销毁。
*/
#include <cassert>
#include <iostream>
using namespace std;

template <typename T> class SP {
public:
  T *_ptr = nullptr;
  int *_count = 0;

public:
  SP(T *ptr = nullptr) : _ptr(ptr) {
    if (_ptr)
      _count = new int(1);
    else
      _count = new int(0);
  }

  SP(const SP &ptr) {
    if (this->_ptr != ptr._ptr) // 检测自复制
    {
      this->_ptr = ptr._ptr;
      this->_count = ptr._count;
      ++(*this->_count);
    }
  }

  SP &operator=(const SP &rhs) {
    if (this->_ptr == rhs._ptr) // 检测自赋值
      return *this;
    if (this->_ptr) {
      --(*this->_count);
      if (*this->_count == 0) {
        delete this->_ptr;
        delete this->_count;
        cout << "release" << endl;
      }
    }
    this->_ptr = rhs._ptr;
    this->_count = rhs._count;
    ++(*this->_count);
    return *this;
  }

  T &operator*() {
    if (this->_ptr == nullptr)
      throw("");
    return *(this->_ptr);
  }

  T *operator->() {
    if (this->_ptr == nullptr)
      throw("");
    return this->_ptr;
  }

  ~SP() {
    --(*this->_count);
    if (*this->_count <= 0) {
      delete this->_ptr;
      delete this->_count;
      cout << "release" << endl;
    }
  }
};

int main() {
  SP<int> s(new int(1));
  SP<int> ss(new int(2));
  SP<int> sss{};
  s = ss;
  {
    SP<int> s2(s);
    s2 = ss;
  }
  *s;
  SP<int> s1;
  //*s1;
}

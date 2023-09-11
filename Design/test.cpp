#include <cstddef>
#include <iostream>
using namespace std;

template <typename T> class SP {
public:
  T *ptr_;
  int *count_;

public:
  SP(T *ptr = nullptr) : ptr_(ptr) {
    cout << " ctor called" << endl;
    if (ptr) {
      count_ = new int(1);
    } else {
      count_ = new int(0);
    }
  }

  SP(const SP &ptr) {
    cout << " copy ctor called " << endl;
    if (this->ptr_ != ptr.ptr_) {
      this->ptr_ = ptr.ptr_;
      this->count_ = ptr.count_;
      ++(*this->count_);
    }
  }

  SP &operator=(const SP &rhs) {
    cout << " operator= called" << endl;
    if (this->ptr_ == rhs.ptr_) {
      return *this;
    }
    if (this->ptr_) {
      --(*this->count_);
      if (*this->count_ == 0) {
        delete this->ptr_;
        delete this->count_;
        this->ptr_ = nullptr;
        this->count_ = nullptr;
        cout << " released " << endl;
      }
    }
    this->ptr_ = rhs.ptr_;
    this->count_ = rhs.count_;
    ++(*this->count_);
    return *this;
  }

  T &operator*() {
    if (!this->ptr_) {
      throw("");
    }
    return *(this->ptr_);
  }

  T *operator->() {
    if (!this->ptr_) {
      throw("");
    }
    return this->ptr_;
  }

  ~SP() {
    --(*this->count_);
    if (*this->count_ <= 0) {
      delete this->count_;
      delete this->ptr_;
      cout << " released " << endl;
    }
  }
};

int main() {
  SP<int> s(new int(1));
  SP<int> s1(s);
  cout << s1.ptr_ << endl;
}
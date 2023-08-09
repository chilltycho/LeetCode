#include <cstring>
#include <iostream>
using namespace std;

template <typename T> class MyVec {
public:
  MyVec();
  MyVec(size_t len, T element);
  MyVec(const MyVec<T> &vec);
  ~MyVec();

  MyVec<T> &operator=(const MyVec<T> &);
  T &operator[](size_t);
  void push_back(T);
  void pop_back();
  void insert(size_t, T);
  void clear();
  void print();

private:
  T *m_ptrElement;
  size_t m_length;
  size_t m_capacity;
};

template <typename T> MyVec<T>::~MyVec() {
  delete[] m_ptrElement;
  m_ptrElement = nullptr;
}

template <typename T> MyVec<T>::MyVec() {
  m_capacity = 16;
  m_length = 0;
  this->m_ptrElement = new T[m_capacity];
}

template <typename T> void MyVec<T>::print() {
  for (size_t i = 0; i < m_length; ++i)
    cout << m_ptrElement[i] << ' ';
  cout << endl;
}

template <typename T> MyVec<T>::MyVec(size_t len, T element) {
  m_capacity = len * 2;
  m_length = len;
  m_ptrElement = new T[m_capacity];
  for (size_t i = 0; i < m_length; ++i)
    m_ptrElement[i] = element;
}

template <typename T> MyVec<T>::MyVec(const MyVec<T> &vec) {
  m_capacity = vec.m_capacity;
  m_length = vec.m_length;
  m_ptrElement = new T[m_capacity];
  memcpy(m_ptrElement, vec.m_ptrElement, m_length * sizeof(T));
}

template <typename T> MyVec<T> &MyVec<T>::operator=(const MyVec<T> &vec) {
  if (this == &vec)
    return *this;
  m_capacity = vec.m_capacity;
  m_length = vec.m_length;
  delete[] m_ptrElement;
  m_ptrElement = new T[vec.m_capacity];
  memcpy(m_ptrElement, vec.m_ptrElement, sizeof(T) * vec.m_length);
  return *this;
}

template <typename T> T &MyVec<T>::operator[](size_t idx) {
  if (idx >= m_length)
    throw out_of_range("out of range");
  return m_ptrElement[idx];
}

template <typename T> void MyVec<T>::push_back(T ele) {
  if (m_ptrElement == nullptr) {
    m_capacity = 16;
    m_length = 0;
    m_ptrElement = new T[m_capacity];
  }
  if (m_length == m_capacity) {
    auto ptrNew = new T[m_capacity * 2 + 1];
    memcpy(ptrNew, m_ptrElement, sizeof(T) * m_length);
    delete[] m_ptrElement;
    m_ptrElement = ptrNew;
  }
  m_ptrElement[m_length++] = ele;
}

template <typename T> void MyVec<T>::pop_back() {
  if (m_length == 0)
    throw out_of_range("pop back on empty vector");
  --m_length;
}

int main() {
  MyVec<int> vi;
  for (int i = 0; i < 10; ++i)
    vi.push_back(i);
  vi.print();
  vi.pop_back();
  vi.print();
}


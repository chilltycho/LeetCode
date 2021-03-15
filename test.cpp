#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Base
{
public:
    Base() {}
    virtual void fun1()
    {
        cout << "Base::fun1()" << endl;
    }
    virtual void fun2()
    {
        cout << "Base::fun2()" << endl;
    }
    virtual void fun3(){ cout << "Base::fun3()" << endl; }
    ~Base() {}
};

class Derived : public Base
{
public:
    Derived() {}
    void fun1()
    {
        cout << "Derived::fun1()" << endl;
    }
    void fun2()
    {
        cout << "Derived::fun2()" << endl;
    }
    ~Derived() {}
};

typedef void (*Fun)();

Fun getAddr(void *obj, unsigned int offset)
{
    cout << "===========" << endl;
    // 64位操作系统，占8字节。通过*(unsigned long*)obj取出前8个字节，即vptr指针
    void *vptr_addr = (void *)*(unsigned long *)obj;
    printf("vptr_addr:%p\n", vptr_addr);

    //通过vptr指针访问virtual table, 虚表中每个元素（虚函数指针）在64位下8个字节，
    void *func_addr = (void *)*((unsigned long *)vptr_addr + offset);
    printf("func_addr:%p\n", func_addr);
    return (Fun)func_addr;
}

int main()
{
    Base ptr;
    Derived d;
    Base *pt = new Derived();
    Base &pp = ptr;
    Base &p = d;
    cout << "基类对象直接调用" << endl;
    ptr.fun1();
    cout << "基类对象调用基类实例" << endl;
    pp.fun1();
    cout << "基类指针指向派生类实例并调用虚函数" << endl;
    pt->fun1();
    cout << "基类引用指向派生类实例并调用虚函数" << endl;
    p.fun1();

    Fun f1 = getAddr(pt, 0); //手动查找vptr 和 vtable
    (*f1)();
    Fun f2 = getAddr(pt, 2);
    (*f2)();
    delete pt;
}
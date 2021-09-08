#include <stdio.h>
#include <stdlib.h>
// 虚表结构
struct base_vtbl
{
    void (*jump)();
};

// 基类
struct Base
{
    struct base_vtbl *vptr;
};

void base_jump()
{
    printf("base jump\n");
}

// 基类虚表
struct base_vtbl base_table = {base_jump};

// 基类构造函数
struct Base *new_base()
{
    struct Base *tmp = (struct Base *)malloc(sizeof(struct Base));
    tmp->vptr = &base_table;
}
//=========

// 子类
struct Derived
{
    struct Base super;
    int high;
};

void derived_jump()
{
    printf("derived jump\n");
}

// 子类虚表
struct base_vtbl derived_table = {derived_jump};

// 子类构造函数
struct Derived *new_derived(int h)
{
    struct Derived *tmp = (struct Derived *)malloc(sizeof(struct Derived));
    tmp->super.vptr = &derived_table;
    tmp->high = h;
    return tmp;
}

int main()
{
    struct Base *b = new_base();
    b->vptr->jump();

    struct Derived *d = new_derived(1);
    b = (struct Base *)d;
    b->vptr->jump();
}

#if 0
#include <stdio.h>
/// 重定义一个函数指针类型
typedef void (*pf) ();

/**
 * @brief 父类 
 */ 
typedef struct _A
{
    pf _f;
}A;

/**
 * @brief 子类
 */
typedef struct _B
{ 
    A _b; ///< 在子类中定义一个基类的对象即可实现对父类的继承。 
}B;

void FunA() 
{
    printf("%s\n","Base A::fun()");
}

void FunB() 
{
    printf("%s\n","Derived B::fun()");
}


int main() 
{
    A a;
    B b;

    a._f = FunA;
    b._b._f = FunB;

    A *pa = &a;
    pa->_f();
    pa = (A *)&b;   /// 让父类指针指向子类的对象,由于类型不匹配所以要进行强转 
    pa->_f();
    return 0;
}
#endif
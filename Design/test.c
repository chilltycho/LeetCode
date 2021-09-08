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
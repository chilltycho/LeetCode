#include <cstdlib>
//二叉搜索树
typedef struct BiTNode
{
    int data;                        //节点数据
    struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;
// 二叉树T中是否存在key，若成功，p指向该节点，f为指向T双亲，初始为nullptr
bool SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if (!T)
    {
        *p = f;
        return false;
    }
    else if (key == T->data)
    {
        *p = T;
        return true;
    }
    else if (key < T->data)
        return SearchBST(T->lchild, key, T, p);
    else
        return SearchBST(T->rchild, key, T, p);
}

// 插入，T中不存在key时，插入，否则返回false
bool InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if (!SearchBST(*T, key, nullptr, &p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = nullptr;
        if (!p)
            *T = s;
        else if (key < p->data)
            p->lchild = s;
        else
            p->rchild = s;
        return true;
    }
    else
        return false;
}

// 删除
bool deleteBST(BiTree *T, int key)
{
    if (!*T)
        return false;
    else
    {
        if (key == (*T)->data)
            return Delete(T);
        else if (key < (*T)->data)
            return deleteBST(&(*T)->lchild, key);
        else
            return deleteBST(&(*T)->rchild, key);
    }
}

bool Delete(BiTree *p)
{
    BiTree q, s;
    if ((*p)->rchild == nullptr) //右子树空，只需连接左子树
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else if ((*p)->lchild == nullptr) // 左子树空，只需连接右子树
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else
    {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild) //转左，向右走到尽头（找待测节点前驱）
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data; //s指向被删节点直接前驱
        if (q != *p)
            q->rchild = s->lchild; //重接q右子树
        else
            q->lchild = s->lchild; //重接q左子树
        free(s);
    }
    return true;
}
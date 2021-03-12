/* 平衡因子|BF|<=1
在构建二叉排序树过程中，每当插入一个节点时，先检查是否因插入而破坏了树的平衡性，若是
找出最小不平衡子树。在保持二叉排序树特性前提下，调整最小不平衡子树中各节点之间链接
关系，进行相应旋转，使之成为新平衡子树。
*/
// 当最小不平衡子树根节点BF大于1(左边过多)，右旋。小于-1就左旋。

typedef struct BiTNode
{
    int data;
    int bf;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 対以p为根的二叉排序树作右旋处理
void R_Rotate(BiTree *p)
{
    BiTree L; // 新根节点
    L = (*p)->lchild;
    (*p)->lchild = L->rchild;
    L->rchild = (*p);
    *p = L;
}

// 左旋节点
void L_Rotate(BiTree *p)
{
    BiTree R;         //R指向P右子树根节点
    R = (*p)->rchild; //R左子树挂接为P右子树
    (*p)->rchild = R->lchild;
    R->lchild = (*p);
    *p = R; //p指向新根节点
}

#define LH +1 //左高
#define EH 0  //等高
#define RH -1 //右高
// 对以指针T所指节点为根的二叉树作左平衡
void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild; //L指向T的左子树根节点
    switch (L->bf)
    {// 检查T左子树平衡度，作相应平衡处理
    case LH: 
        (*T)->bf = L->bf = EH;
        R_Rotate(T);
        break;
    case RH:
        Lr = L->rchild;
        switch (Lr->bf)
        {
        case LH:
            (*T)->bf = RH;
            L->bf = EH;
            break;
        case EH:
            (*T)->bf = L->bf = EH;
            break;
        case RH:
            (*T)->bf = EH;
            break;
        }
        Lr->bf = EH;
        L_Rotate(&(*T)->lchild);
        R_Rotate(T);
    }
}
// 二叉树存储结构

//顺序存储结构

#define Maxsize 100
int SqBiTree[100];

//链式存储结构
typedef struct BitNode
{
    int data;
    struct BitData *lchild,*rchild;     //左右孩子指针
}BitNode;

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

//队列的链式存储结构
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;

typedef struct
{
//队头、队尾
    QNode *Front;
    QNode *Rear;
}LinkQueue;

//链队的初始化
LinkQueue InitQueue( LinkQueue &Q)
{
//构造一个空队列Q
    Q.Front = Q.Rear = new QNode;
    Q.Front->next = NULL;
    return Q;

}

//链队的入队
void EnQueue(LinkQueue &Q, int e)
{
//插入元素e为Q的新的队尾元素
    QNode *p = new QNode;
    p->data = e;
    p->next=NULL;
    Q.Rear->next = p;
    Q.Rear = p;
}
//链队的出队     //就是删除队头
void DeQueue(LinkQueue &Q)
{
    if(Q.Front == Q.Rear)
    {
        cout << "出队失败";
        return ;
    }
    QNode *p = new QNode;
    p=Q.Front->next;    //p指向队头元素
    Q.Front->next = p->next;    //队头往后挪一个
    if(Q.Rear==p)   //最后一个元素被删，队尾指向头结点
    {
        Q.Rear=Q.Front;
    }
    delete p;
}
//去链队的队头
int GetHead(LinkQueue Q)
{
//返回队头元素
    if(Q.Front!=Q.Rear)
    {
        return Q.Front->next->data;
    }
}

int main()
{

	return 0;
}

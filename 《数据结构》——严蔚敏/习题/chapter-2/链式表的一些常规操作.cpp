#include <iostream>
#include <iomanip>

using namespace std;

typedef struct slist
{
    int data;
    struct slist *next;
}L;

int num=0;

//创建链表节点
L *create_node( int i)
{
    L *p = new L;
    p->data = i;
    p->next = NULL;
    return p;
}
//尾插法
void tail_insert( L *pH, L *New)
{
    L *p = new L;
    p = pH;
    while(p->next)
    {
        p = p->next;
    }
    p->next = New;
}

//遍历列表
void Print(L *a)
{
    L *p = new L; p=a->next;    //第一个结点是无效结点
    while(p->next)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << p->data<< endl;
}

//有序链表合并
void Add(L *a,L *b, L *c )
{
   L *pa = new L; pa=a->next;
   L *pb = new L; pb=b->next;
   L *pc = new L; pc=c;
   while(pa &&pb)   //a b 均未到达链尾
   {
       if(pa->data <= pb->data)
       {
           pc->next = pa;
           pc = pa;
           pa = pa->next;
       }
       else
      {
           pc->next = pb;
           pc = pb;
           pb = pb->next;
       }
   }
//有一个到头了
    pc->next = pa?pa:pb;
    delete pa,pb;
    //return pc;
}

void Overturn(L *a)
{
// p为当前节点， pre为它前面的一个节点
    L *pre = new L; pre=a->next;
    L *p = new L; p=pre->next;
    L *temp = new L;
//头结点变成了最后一个
    pre->next=NULL;

    while(p)
    {
        temp = p;
        p=p->next;
        temp->next = pre;
        pre = temp;
    }
    a->next=pre;
}

int main()
{
    L *a = new L;
    a->data = 0;
    a->next = NULL;
    L *b = new L;
    b->data = 0;
    b->next = NULL;
    L *c = new L;
    c->data = 0;
    c->next = NULL;
    L *d = new L;
    d->data = 0;
    d->next = NULL;

    int aaa[5]={1,7,4,-3,6};
    int bbb[5]={1,3,5,6,8};
    for(int i=0; i<5; i++)  //a 0 2 4 6 8
    {
        tail_insert(a,create_node(aaa[i]));
        tail_insert(b,create_node(bbb[i]));
    }


    cout << "a初始值： ";  Print(a) ;
    //cout << "b初始值： ";  Print(b) ;
    Overturn(a);
    cout << "a初始值： ";  Print(a) ;










    return 0;
}


#include <iostream>

using namespace std;

typedef struct slist
{
    int data;
    struct slist *next;
}L;

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
void Add(L *a,L *b,L *c )
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

    for(int i=1; i<=5; i++)  //a 0 2 4 6 8
    {
        tail_insert(a,create_node(i*2));
    }
    for(int i=1; i<=5; i++)  //b 1 3 5 7 9
    {
        tail_insert(b,create_node(i*2+1));
    }

    Print(a);
    Print(b);
    Add(a,b,c );
    Print(c);






    return 0;
}


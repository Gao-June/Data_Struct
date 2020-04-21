/*
题目：
    设计一个算法将一个带头结点的单链表A分解为两个具有相同结构的链表B和C，其中B表
    的节点为A表中值小于0的结点，C表的节点为A表中值大于0的结点。
*/


void depart(L *a, L *b, L *c)
{
    L *pa = a->next;    L *pb = b;    L *pc = c;
    L *temp;

    while(pa->next)
    {
        if(pa->data > 0)
        {
            temp = pa;
            pa = pa->next;
            pb->next = temp;
            pb=temp;
        }
        else
        {
            temp = pa;
            pa = pa->next;
            pc->next = temp;
            pc=temp;
        }
    }
    if(pa->data > 0)
    {
        temp = pa;
        pa = pa->next;
        pb->next = temp;
        pb=temp;
    }
    else
    {
        temp = pa;
        pa = pa->next;
        pc->next = temp;
        pc=temp;
    }

}

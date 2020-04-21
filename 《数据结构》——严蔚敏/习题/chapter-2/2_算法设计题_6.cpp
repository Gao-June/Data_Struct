/*
    设计一个算法，将链表中所有结点的链接方向“原地”逆转，即要求仅利用原表的存储空间，换句话说，
    要求算法空间复杂度为O(1)
*/
//还有一种写法，每次都将结点插在头结点之后
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
        pre = tmp;
    }
    a->next=pre;
}


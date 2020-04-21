/*
题目：
    已知两个链表A 和 B分别表示两个集合，其元素递增排列。
    请设计一个算法，用于求出A和B的交集，并存放在A中
想法：
    由于A B都是递增，对A B遍历，取相同的元素
*/

void Sets(L *a, L *b)
{
    L *pa = new L; pa=a->next;
    L *pb = new L; pb=b->next;
    L *p=new L; p=a;p->next=NULL;    //交集合在p这里

    while(pa && pb)
    {
        if(pa->data < pb->data)
        {
            pa=pa->next;
        }
        else if(pa->data > pb->data)
        {
            pb=pb->next;
        }
        else
        {
            p->next = pa;
            p = p->next;
            pa = pa->next;
            //pb = pb->next;    //可以不写，下次循环会判断
        }
    }
    p->next=NULL;
    delete pa,pb;
}











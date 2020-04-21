/*
题目：
    已知两个链表A和B分别表示两个集合，其元素递增排列。
    请设计算法求出两个集合A和B的差集（即仅由在A中出现而不在B中出现的元素所构成的集合），并以同样的形式存储，同时返回该集合的元素个数。
想法：
    删除链表中相同项就行了
    num 要放到全局变量里面
*/


int Difference(L *La, L *Lb)
{
    int num=0;
//pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的第一个结点
    L *pa=La->next;
    L *pb=Lb->next;

    L *pre=La;          //pre为La中pa所指结点的前驱结点的指针
    while(pa&&pb)
    {
        if(pa->data < pb->data)  //A链表中当前结点指针后移
        {
            pre=pa;
            pa=pa->next;
            num++;
        }

        else if(pa->data>pb->data)   //B链表中当前结点指针后移
        {
            pb=pb->next;
        }
        else     //处理A，B中元素值相同的结点，应删除
        {
            pre->next = pa->next;
            L *u=pa;
            pa=pa->next;
            //delete u;     //可以直接跳过去
        }
    }
    return num;
}


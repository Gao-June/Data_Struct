/*
  将两个递增的有序链表合并为一个递增的有序链表。
  要求结果链表仍使用原来两个链表的存储空间，不另外占用其他的存储空间。表中不允许有重复的数据。
*/
void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc)
{
//pa和pb分别是链表La和Lb的工作指针,初始化为相应链表的第一个结点
    pa=La->next;  pb=Lb->next;
    Lc=pc=La;  //用La的头结点作为Lc的头结点
    while(pa && pb)
    {
        //取较小者La中的元素，将pa链接在pc的后面，pa指针后移
        if(pa->data<pb->data)
        {
            pc->next=pa;pc=pa;pa=pa->next;
        }
        //取较小者Lb中的元素，将pb链接在pc的后面，pb指针后移
        else if(pa->data>pb->data)
        {
            pc->next=pb; pc=pb; pb=pb->next;
        }
        else //相等时取La中的元素，删除Lb中的元素
        {
            pc->next=pa;pc=pa;pa=pa->next;
            q=pb->next;delete pb ;pb =q;
        }
     }
    pc->next=pa?pa:pb;    //插入剩余段
    delete Lb;            //释放Lb的头结点
}

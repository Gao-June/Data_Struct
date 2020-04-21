/*
  将两个非递减的有序链表合并为一个非递增的有序链表。
  要求结果链表仍然使用原来两个链表的存储空间，不另外占用其他的存储空间。表中允许有重复项。
*/

//因为 a,b都是非递减，所以每次比较 a,b取小的，头插法插在c中，得到的c就是非递增
void Adda( L *a, L *b, L *c)
{
    L *pa = new L; pa=a->next;      //第一个数据是空数据
    L *pb = new L; pb=b->next;
    L *pc = new L; pc=c;
    L *temp = new L; temp->next=NULL; //中间变量

    while(pa || pb) //不用 ->next，因为当下位置的值也要用到
    {
        if(!pa ) //pa空，或 pb<=pa 只用插pb
        {
            temp = pb;
            pb = pb->next;  //后移
            temp->next=pc->next;
            pc->next=temp;

        }
        else if(pb->data <= pa->data)
        {
            temp = pb;
            pb = pb->next;  //后移
            temp->next=pc->next;
            pc->next=temp;

        }
        else if(pa->data <=pb->data)
        {
            temp = pa;
            pa = pa->next;  //后移
            temp->next=pc->next;
            pc->next=temp;

        }
        else if(!pb  ) //pb空，或 pa<=pb 只用插pa
        {
            temp = pa;
            pa = pa->next;  //后移
            temp->next=pc->next;
            pc->next=temp;

        }
    }

}












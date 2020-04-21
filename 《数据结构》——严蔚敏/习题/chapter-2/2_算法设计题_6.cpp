/*
    设计一个算法，通过一趟遍历，确定长度为n的单链表中值最大的结点
*/

int Find_max(L *a, int n)
{
    int num=1;
//初始情况p指向第一个，temp指向第二个位置
    L *p = new L; p=a->next;
    L *temp = new L; temp = p->next;

    for(int i=2; i<=n; i++)
    {
        if(p->data < temp->data)
        {
            num = i;
            p = temp;
        }
        temp = temp->next;
    }
    return num;
}







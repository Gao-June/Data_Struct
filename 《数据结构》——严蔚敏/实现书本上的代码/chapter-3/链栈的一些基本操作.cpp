//引入链栈的概念，是因为顺序栈容易溢出！


//链栈的存储结构
typedef struct StackNode
{
    int data;
    struct StackNode *next;
}SN;

//链栈初始化
SN *InitStack( SN &s)
{
//创建一个空栈，栈顶指针制空
    s=NULL;
}

//入栈
SN Push( SN *S, int e)
{
    SN *p = new SN;
    p->data = e;
    p->next = S;
    S=p;
}

//出栈    将该元素传给e
void Pop(SN *S, int e)
{
    if(S)
    {
        cout << "栈空！";
        return;
    }
    SN *p = new SN;
    e = S->data;
    p=S;
    S = S->next;
    delete p;
}

//取栈顶元素
int GetPop(SN *S)
{
    if(S)
    {
        return S->data;
    }
}


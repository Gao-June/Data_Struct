//和顺序线性表差不多

#include <iostream>

using namespace std;

#define Maxsize 100

//栈的数据结构
typedef struct{
    int *bottom;
    int *top;
    int stacksize;
}SqStack;

//栈的初始化
void init_stack( SqStack &S)    //使用了引用 & ,就直接给 void算了
{
    S.bottom = new int[Maxsize]();    //加个 ()，初始为0
    if(!S.bottom)
    {
        cout << "初始化失败";
        return;
    }
    S.top=S.bottom;
    S.stacksize = Maxsize;
}

void Push_stack( SqStack &s, int e)		//入栈操作
{
	int increasize;
	if( s.top - s.bottom == s.stacksize)		//判断栈是否溢出
	{
		cout << "栈满了";
	}
	*(s.top++) = e;		//栈顶指针上移一位，让数据 e 入栈，注意顺序不能颠倒，否则栈顶指针就不熟指向栈顶元素前一位了

}

void Pop_stack( SqStack &s, int &e)	//出栈操作, 将栈顶元素给e
{
	if( s.top == s.bottom)
	{
		return;
	}
	else
	{
		//--s.top;	//通过 e 返回栈顶元素
		e = *--s.top;	//实际上此元素没有真正清除，仍在 s.top中，但是 如果插入元素，就会被覆盖

	}
}

//取栈顶元素
int GetTop(SqStack s)
{
    if(s.top!=s.bottom)
    {
        return *(s.top-1);
    }
}

int main()
{
    SqStack S;
    init_stack( S);
    for(int i=1; i<=10; i++)
    {
        Push_stack( S, i);		//入栈操作
    }

    for(int i=1; i<=10; i++)
    {
        //GetTop(S);
        int num;
        Pop_stack( S, num);     //出栈
        cout << num << "  ";
    }





    return 0;
}

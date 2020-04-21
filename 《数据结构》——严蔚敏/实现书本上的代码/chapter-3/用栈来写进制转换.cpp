//eg.十进制 转 八进制

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct
{
	int *bottom;		//栈底
	int *top;			//栈顶
}sqStack ;

void InitStack( sqStack &s)		//创造空栈
{
	//s.bottom = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	s.bottom = new int[100];	//利用c++的特性开辟内存空间

	if(!s.bottom)
	{
		cout << " ...分配内存失败 " << endl;
		exit(0);
	}
	else
	{
		cout << "...create successfully! " << endl << endl;
		s.top = s.bottom ;	//创造空栈

	}
}

void Push_stack( sqStack &s, int e)		//入栈操作
{
	int increasize;

	*(s.top++) = e;		//栈顶指针上移一位，让数据 e 入栈，注意顺序不能颠倒，否则栈顶指针就不熟指向栈顶元素前一位了

}

void Pop_stack( sqStack &s, int &e)	//出栈操作, 将栈顶元素给e
{
	if( s.top == s.bottom)
	{
		return;
	}
	else
	{
		e = *--s.top;	//实际上此元素没有真正清除，仍在 s.top中，但是 如果插入元素，就会被覆盖
	}
}

void conversion(int N)
{
//对于任意非负整数N，求其八进制
    sqStack S;
    InitStack(S);
    while(N)
    {
        Push_stack(S,N%8);
        N/=8;
    }
    while(S.top != S.bottom)
    {
        int e;
        Pop_stack(S,e);
        cout << e;
    }
}

int main()
{
    int n=20;
    conversion(n);


	return 0;
}

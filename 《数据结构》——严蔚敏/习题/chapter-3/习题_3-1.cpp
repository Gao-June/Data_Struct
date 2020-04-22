/*
    试编写双栈初始化，判断栈空、栈满、进栈和出栈等算法的函数
*/

#include <iostream>
#include <iomanip>

using namespace std;

//双栈数据结构定义
typedef struct
{
    int top[2],bot[2];  //栈顶和栈底指针
    int *V;     //栈数组
    int m;      //栈最大容量
}DblStack;

//栈初始化
void Init(DblStack S)
{
    int m=100;
    S.top[0]=1;
    S.top[1]=m;
}

//入栈操作
//i为栈号，i=0表示左栈，i=1为右栈，x是入栈元素。入栈成功返回1，失败返回0
int Push(DblStack S, int i, int x)
{
    if(i<0||i>1)
    {
        cout<<"栈号输入不对"<<endl;
        exit(0);
    }
    if(S.top[1]-S.top[0]==1)
    {
        cout<<"栈已满"<<endl;
        return(0);
    }
    switch(i)
    {
        case 0:
        {
            S.V[++S.top[0]]=x; return(1);
            break;
        }
        case 1:
        {
            S.V[--S.top[1]]=x; return(1);
        }
    }

}


//出栈操作
//退栈。i代表栈号，i=0时为左栈，i=1时为右栈。退栈成功时返回退栈元素
//否则返回-1
ElemType pop(stk S,int i)
{
    if(i<0 || i>1)
    {
        cout<<"栈号输入错误"<<endl;
        exit(0);
    }
    switch(i)
    {
        case 0:
        {
            if(S.top[0]==-1)
            {cout<<"栈空"<<endl;
                return（-1）；
            }
            else
            {
                return (S.V[S.top[0]--]);
            }
        }
        case 1:
        {
            if(S.top[1]==m
            {
                cout<<"栈空"<<endl;
                return(-1);
            }
            else
            {
                return(S.V[S.top[1]++]);}
            }
   }//switch
}//算法结束


//判断栈空
int Empty()
{
    return (S.top[0]==-1 && S.top[1]==m);
}




//本书都是以结构体形式描述的

#include <iostream>
#include <string>
#include <cstdlib>      // exit(-1) 非正常退出程序
#include <iomanip>      // setw()


using namespace std;
#define Size 100

//顺序表的存储结构
typedef struct
{
    int *Elem;
    int Length;
}SqList;

//顺序表的初始化，构造一个空的顺序表
SqList initialize_list( SqList &L)
{
//为顺序表分配一个大小为 Size 的数组空间
    L.Elem = new int[Size];
    if(!L.Elem)     //内存分配失败
    {
        cout << "内存分配失败！";
        exit(-1);
    }
    L.Length=0;
    return L;
}

//顺序表的赋值，给顺序表第i个数据元素赋值e
void GetElem(SqList &L, int i, int e)
{
    if(i<0 || i>L.Length)
    {
        cout << "超过区间";
        return;
    }
    L.Elem[i]=e;
    L.Length++;     //注意，我这里的长度每次都会先指向下一个位置
}

//顺序表的查找 查找e是否在顺序表中，若在 返回下标，否则返回 -1
int LocateElem(SqList &L, int e)
{
    for(int i=0; i< L.Length; i++)
    {
        if(L.Elem[i] == e)
        {
            return i;
        }
    }
    return -1;
}
//顺序表的插入 将新元素e插入到下标i处
void ListInsert(SqList &L, int i, int e)
{
//检查是否越界
    if(i<0 || i>L.Length || L.Length==Size)
    {
        cout << "越界了！";
        return;
    }
    GetElem(L, L.Length, e);
    for(int j=L.Length-1; j>=i+1; j--)
    {
        swap(L.Elem[j],L.Elem[j-1]);
    }
}
//顺序表的删除 将下标i处的值删除
void ListDelete(SqList &L, int i)
{
//越界
    if(i<0 || i>=L.Length)
    {
        cout << "越界了！";
        return;
    }
    for(int j=i+1; j<L.Length; j++)
    {
        L.Elem[j-1] = L.Elem[j];
    }
    L.Length--;
}


int main()
{
//初始化
    SqList L;
    initialize_list(L);
//赋值
    for(int i=0; i<10; i++)
    {
        GetElem(L, i, i);
    }
    for(int i=0; i<10; i++)
    {
        cout << L.Elem[i] << setw(3);
    }
    cout << endl;
//查找
    cout << "位置 " << 7 << " 在 " << LocateElem(L, 7) <<endl;
//插值
    ListInsert(L, 4, 5);
    for(int i=0; i<L.Length; i++)
    {
        cout << L.Elem[i] << setw(3);
    }
    cout << endl;
//删除
    ListDelete(L, 7);
    for(int i=0; i<L.Length; i++)
    {
        cout << L.Elem[i] << setw(3);
    }
    cout << endl;

	return 0;
}



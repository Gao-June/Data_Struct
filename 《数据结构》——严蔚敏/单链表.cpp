

#include <iostream>
#include <cstdlib>		//malloc()	分配内存空间   ---- (与之对应的就是)free 
#include <cstring>		//memset()	清除脏数据 

using namespace std;

typedef struct slist	//结构体，放数据项 和指向下一个链表的指针 
{
	int id;
	struct slist *next;
}L;		//创建一个该结构体类型变量 L 

//创建新节点
L *create_node (int data)			//指针函数，返回的是一个指针 
{
//给每个结点分配结构体一样的空间大小
	L *p=NULL;
	p = (L *)malloc(sizeof(L));
	
	if(NULL == p)
	{
		cout << "malloc error!" << endl; 
	}

//由于结构体在未初始化的时候一样是脏数据，所以要清理脏数据
	memset(p,0,sizeof(L));
//初始化第一个结点
	p->id = data;
	p->next = NULL;	//将结点后继指针设置为null 
	
	return p;
} 

//链表的尾插
void tail_insert( L *pH, L *New)	//把 New插到 pH的尾部 
{
//获取当前位置
	L *p = pH;
//如果当前位置的下一个结点不为空
	while(NULL != p->next)
	{
		//移动到下一结点
		p = p->next; 
	} 
//到尾结点了
//直接把新插入的节点赋值给NULL这个位置
	p->next = New; 
} 

//链表的头插
void top_insert( L *pH, L *New )	//把 New插到 pH的头部
{
	L *p = pH;
	New->next = p->next;
	p->next = New;
} 

//链表的遍历
void print_node(L *pH)		//没有考虑头结点的 data 
{
//获取当前的位置
	L *p = pH;
//获取第一个节点的位置
	p = p->next;
//开始遍历
	while(NULL != p->next)
	{
		//打印节点数据
		cout << "id :  " << p->id << endl; 
		p = p->next;
	} 
	//打印最后一个节点
	cout <<  "id :  " << p->id << endl;
} 

//删除链表中的节点	(需要考虑该节点在不在对后位置)
int detele_list_node(L *pH, int data)
{
//获取当前头结点的位置
	L *p = pH;
	L *prev = NULL;		//放当前节点的前一个节点
	
	while(NULL != p->next)
	{
		//保存当前节点的前一个节点的指针
		prev = p;
		//当前指针后移
		p = p->next;
		
		if(p->id == data)
		{
			if(p->next==NULL)	//最后一个节点 
			{
				prev->next = NULL;
				free(p);
			}
			else
			{
				prev->next = p->next;
				free(p);
			}
			return 0;
		}
	} 
	cout << "没有找到要删除的节点" << endl;
	return -1;
	 
} 

//链表翻转
void trave_list(L *pH)
{
//保存第一个节点的位置
	L *p = pH->next;
	L *pback;	//用来放节点p的下一个节点;
	if(p->next == NULL || p==NULL)
	{
		return;
	}
	
	while(p->next != NULL)
	{
		pback = p->next;
		if(p==pH->next)    //如果是第一个结点
		{
			//第一个有效结点就是最后一个节点
			p->next = NULL; 
		} 
		else
		{
			p->next = pH->next;		//利用pH进行转换 
		}
		pH->next = p;	//头部连接
		 p = pback;		//走向下一节点 
	}
	top_insert(pH,p);	//插入最后一个节点 
	
} 


int main()
{
	L *header = create_node(0);
	for(int i=1; i<10; i++)
	{
		tail_insert(header,create_node(i));
	}
	print_node(header);
	cout << endl;
	
	detele_list_node(header,5);
	
	print_node(header);
	cout << endl;
	
	trave_list(header);
	print_node(header);
	cout << endl;
	
	
	return 0;
}
















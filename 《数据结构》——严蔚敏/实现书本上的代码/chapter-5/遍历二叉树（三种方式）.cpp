
#include <iostream>

using namespace std;

void preorder(int *arr, int len, int i)		//前序遍历 	根-左-右 
{
	if( i>=len )
	{
		return;
	}
	cout << arr[i] << " ";		//先输出根节点
	preorder(arr,len,i*2+1);	//输出左子树
	preorder(arr,len,i*2+2);	//输出右子树 
	
} 

void inorder(int *arr,int len, int i)		//中序遍历 		左-根-右 
{
	if(i >= len)
	{
		return;
	}
	inorder(arr,len,i*2+1);
	cout << arr[i] << " " ;
	inorder(arr,len,i*2+2);
} 

void aftorder(int *arr,int len, int i)		//后序遍历 		左-右 -根 
{
	if(i >= len)
	{
		return;
	}
	aftorder(arr,len,i*2+1);
	aftorder(arr,len,i*2+2);
	cout << arr[i] << " " ;
}



int main()
{
	int  aa[]={78,56,34,43,4,1,15,2,23};
	int len=sizeof(aa)/sizeof(aa[0]);
	
	cout << endl;
	preorder(aa,len,0) ;
	cout << endl;
	inorder(aa,len,0);
	cout << endl;
	aftorder(aa,len,0);
	cout << endl;
	



	return 0;
}



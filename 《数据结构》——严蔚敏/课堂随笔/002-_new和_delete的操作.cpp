#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int *p1 = new int(3);       //p1初始值 3
    int *pp = new int(44); 
    int *p2 = new int[3];       //未初始化，值到处跑
    int *p3 = new int[3]();     //初始化，值是 0 0 0

    
    if(p1)
    {
    	cout << *p1 << setw(3);
	}
	if(!pp)
	{
		cout <<" "<< *pp << setw(3);
	}
    cout << endl;
    for(int i=0; i<3; i++)
    {
        cout << *p2++ << setw(3);
    }
    cout << endl;
    for(int i=0; i<3; i++)
    {
        cout << *p3++ << setw(3);
    }
    cout << endl;
//注：delete只是释放了堆空间，并没有使指针指向NULL，
//不过不用管了
cout << "delete 之后 " <<endl;
    delete p1;
    delete []p2;
    delete []p3;
    cout << *p1 << setw(3);
    cout << endl;
    for(int i=0; i<3; i++)
    {
        cout << *p2++ << setw(3);
    }
    cout << endl;
    for(int i=0; i<3; i++)
    {
        cout << *p3++ << setw(3);
    }
    cout << endl;

	return 0;
}

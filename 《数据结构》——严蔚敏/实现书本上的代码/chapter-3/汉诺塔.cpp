/*
    已知有n个盘子，三根柱子分别为 A B C，试写出将A中的n个盘子全部放到C的步骤
*/


#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void Hanoi_tower(int n,string From, string temp, string To)
{
    if(n==1)
    {
        cout << "把 " << n <<"从 " << From << " 放到 " << To << endl;
        return;
    }
    else
    {
        Hanoi_tower(n-1, From, To, temp);
        cout << "把 " << n <<"从 " << From << " 放到 " << To << endl;
        Hanoi_tower(n-1, temp, From, To);
    }
}

int main()
{
    int n=3;
    Hanoi_tower(n,"A","B","C");



	return 0;
}

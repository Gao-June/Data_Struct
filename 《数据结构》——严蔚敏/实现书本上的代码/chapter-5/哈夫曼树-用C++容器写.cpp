/*
	哈夫曼树主要步骤：
	1-排序	可以直接放在 <set> 的 multiset中，会自动排序且允许重复项
	2-把最小的两个数加起来，且把和值放到累加器中	可以创建一个全局变量存
	3-把两个最小的数加起来的和，放到容器中
*/

#include <iostream>
#include <set>	//multiset()

using namespace std;

int n,sum;
multiset<int> aa;

int main()
{
	multiset<int>::iterator p;
	cin >> n;
	for(int i=0; i<n ;i++)		//初始化
	{
		int x;
		cin >> x;
		aa.insert(x);
	}

	cout << endl << "进入容器后： " << endl;
	for(p=aa.begin(); p!=aa.end(); p++  )
	{
		cout << *p << " ";
	}
	cout << endl;


	while(aa.size()!=1)
	{
		p=aa.begin();
		int i=*p, j=i;
		aa.erase(aa.begin());

		p=aa.begin();
		i=*p, j+=i;
		aa.erase(aa.begin());

		sum+=j;
		aa.insert(j);



		for(p=aa.begin(); p!=aa.end(); p++  )
		{
			cout << *p << " ";
		}
		cout <<endl << "   sum = "<< sum<< endl;
	}

	cout << "哈夫曼树权值为： " << sum;



	return 0;
}















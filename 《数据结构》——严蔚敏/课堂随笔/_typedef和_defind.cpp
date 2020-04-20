#include <iostream>
#include <iomanip>      // setw()

typedef int aa;         //效果差不多，推荐使用 typedef
#define bb int          //[注]1-bb写在前面  2-没有分号

using namespace std;

int main()
{
    aa x=3;
    bb y=4;
    cout << x << setw(3) << y;

	return 0;
}

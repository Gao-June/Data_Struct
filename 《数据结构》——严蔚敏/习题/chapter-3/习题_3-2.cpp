//判断回文数

#include <iostream>
#include <string>

using namespace std;

bool Judge(string s)
{
    int len=s.size();
    for(int i=len/2,j=0; j<=i; j++)
    {
        if(s[j]==s[len-1-j])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s="abcdba";
    int len=s.size();
    if( Judge(s) )
    {
        cout << "是回文数 " << endl;
    }
    else
    {
        cout << "不是回文数 " << endl;
    }
}

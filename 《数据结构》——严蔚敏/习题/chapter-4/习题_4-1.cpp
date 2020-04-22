//以下标为0开始

//next[0]=-1,若前面配有匹配项next[i]=0
void GetNext(string s, int *next)
{
    int i=0,j=-1;
    next[0]=-1;
    int len=s.size();

    while(i<len-1)
    {
        if(j==-1 || s[i]==s[j])
        {
            ++i,++j;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}


void GetNextval(string s, int *next)
{
    int i=0,j=-1;
    next[0]=-1;
    int len=s.size();

    while(i<len-1)
    {
        if(j==-1 || s[i]==s[j])
        {
            ++i,++j;
            if(s[i] != s[j])
            {
                next[i]=j;
            }
            else
            {
                next[i] = next[j];
            }
        }
        else
        {
            j = next[j];
        }
    }
}

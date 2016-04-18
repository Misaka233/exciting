#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[200010],mmax[200010];//max数组从max[i]表示从i到最右边l的最大值
void solve()
{
    int m,d,p,t=0,l=0;
    char s[1];
    scanf("%d%d",&m,&d);
    while(m--)
    {
        scanf("%s%d",s,&p);
        if(s[0]=='A')
        {

            a[++l]=(t+p)%d;
            for(int i=l;i>0;i--)
            {
                if(mmax[i]<a[l]) mmax[i]=a[l];
                else break;
            }
        }
        else
        {
            t=mmax[l-p+1];
            printf("%d\n",t);
        }
    }
}
int main()
{
    solve();
    return 0;
}

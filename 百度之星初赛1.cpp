#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
struct misaka
{
    int num;
    int  flag;
    int  ans;
}a[100000];
bool cmp(misaka a,misaka b)
{
    return a.num<b.num;
}
bool cmp1(misaka a,misaka b)
{
    return a.flag<b.flag;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(a,-1,sizeof(a));
        for(int i=1;i<=n;i++)
        {
        scanf("%d",&a[i].num);
        a[i].flag=i;
        }
        sort(a+1,a+n+1,cmp);
        int temp=(n+1)/2;
        for(int i=1;i<=n;i++)
        {
            if(i<=temp) a[i].ans=i;
            else a[i].ans=n-i+1;
        }
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<n;i++)
        {
            printf("%d ",a[i].ans);
        }
        printf("%d\n",a[n].ans);
    }

    return 0;
}

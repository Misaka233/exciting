#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
double a[15];
int b[15];
bool flag[15];
int n,ans,full;
void dfs(int ii)
{
    flag[ii]=1;
    full+=a[ii];
    int co=0;
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0&&full+a[i]<=20)
            co=1;
    }
    if(co==0)
    {
        full=0;
        ans++;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=ii&&flag[i]==0&&full+a[i]<=20)
        {
            dfs(i);
        }
    }

}
bool cmp(double a,double b)
{
    return a>b;
}
int main()
{
    while(~scanf("%d",&n)){
    ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    full=0;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        flag[i]=1;
        dfs(i);
        if(ans==0) ans+=1;
        b[i]=ans;
        ans=0;
    }
    int ak=1000;
    for(int i=1;i<=n;i++)
    {
        if(b[i]<ak) ak=b[i];
        //cout<<b[i]<<" ";
    }
    printf("%d\n",ak);
    }
    return 0;
}

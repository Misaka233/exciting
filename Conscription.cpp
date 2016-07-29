//最大生成树
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=55000;
int F[maxn];
struct misaka
{
    int u,v,w;
}e[maxn];
int tol;
bool cmp(misaka a,misaka b)
{
    return a.w>b.w;
}
int find(int x)
{
    if(F[x]==x) return x;
    else return F[x]=find(F[x]);
}
int kr(int n)
{

    sort(e,e+tol,cmp);
    for(int i=0;i<n;i++)
    {
        F[i]=i;
    }
    int ans=0;
    for(int i=0;i<tol;i++)
    {
        int u=e[i].u;
        int v=e[i].v;
        int w=e[i].w;
        int t1=find(u);
        int t2=find(v);
        if(t1!=t2)
        {
            ans+=w;
            F[t1]=t2;
        }
    }
    return ans;
}
int main()
{
    int t,n,m,r;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&r);
        tol=r;
        for(int i=0;i<r;i++)
        {
            int x;
            scanf("%d%d%d",&e[i].u,&x,&e[i].w);
            e[i].v=x+n;
        }
        int ans=kr(m+n);
        cout<<10000*(m+n)-ans<<endl;
    }
    return 0;
}

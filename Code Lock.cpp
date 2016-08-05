#include<bits/stdc++.h>
using namespace std;
#define INF 99999999
const int maxn =600;
const int maxm =360000;
const int oo = 1<<29;
int f[11000000];
#define mod 1000000007
#define LL __int64
int find(int x)
{
    while(x!=f[x])x=f[x];
    return x;
}
LL mul(LL a,LL b)
{
    if(b==0)return 1;
    if(b==1)return a;
    LL c=mul(a,b/2);
    c=(c*c)%mod;
    if(b&1)c=(c*a)%mod;
    return c;
}
int main()
{
    int n,m,a,b,i;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<=n;i++)f[i]=i;
        LL ans=n;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            a=find(a-1);
            b=find(b);
            if(a==b)continue;
            f[b]=a;
            ans--;
        }
        cout<<mul(26,ans)<<endl;
    }
    return 0;
}


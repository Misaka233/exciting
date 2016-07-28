#include<bits/stdc++.h>
using namespace std;
long long f[100],n,m,ans,fc,k;
void dfs(int i,int n,int sum)
{
    if(sum==0)
    {
        if(n==0) ans++;
        return ;
    }
    if(i<0||1ll*n*f[i]<sum)
        return ;
    dfs(i-1,n,sum);
    while(n>0&&sum>=f[i])
    {
        sum-=f[i];
        n--;
        dfs(i-1,n,sum);
    }
}
int main()
{
    f[0]=1;
    f[1]=2;
    for(fc=2;;fc++)
    {
        f[fc]=f[fc-1]+f[fc-2];
        if(1e9<=f[fc])
            break;
    }
    int q;
    cin>>q;
    while(q--)
    {
        cin>>n>>k;
        ans=0;
        dfs(fc-1,k,n);
        cout<<ans<<endl;
    }
    return 0;
}

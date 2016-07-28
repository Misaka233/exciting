#include<bits/stdc++.h>
using namespace std;
const int maxn=1007;
const int mod=1e9+7;
long long a[maxn];
long long dp[maxn][maxn];
int main()
{
    int t,n,m,s;
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n>>m>>s;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
        }
        if(s-a[1]>0) dp[1][s-a[1]]=1;
        if(s+a[1]<=n) dp[1][s+a[1]]=1;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j-a[i+1]>0)
                {
                    dp[i+1][j-a[i+1]]=(dp[i+1][j-a[i+1]]+dp[i][j])%mod;
                }
                if(j+a[i+1]<=n)
                {
                    dp[i+1][j+a[i+1]]=(dp[i+1][j+a[i+1]]+dp[i][j])%mod;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            printf("%I64d ",dp[m][i]);
        }
        cout<<dp[m][n]<<endl;
    }
    return 0;
}

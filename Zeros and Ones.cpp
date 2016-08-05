#include <cstdio>
#include <cstring>
typedef long long LL;
LL dp[70][70][101];
LL pow_mod(LL a,LL p,LL n){
    if(p == 0)  return 1;
    LL ans = pow_mod(a,p/2,n);
    ans = ans * ans % n;
    if(p%2 == 1)    ans = ans * a % n;
    return ans;
}

int main(){
    int nkase;
    scanf("%d",&nkase);
    for(int kase = 1;kase <= nkase;kase++){
        int n,k;
        scanf("%d%d",&n,&k);
        if((n&1) || k == 0){
            printf("Case %d: 0\n",kase);
            continue;
        }
        for(int i = 0;i <= n;i++)
        for(int j = 0;j <= n;j++)
        for(int t = 0;t < k;t++)    dp[i][j][t] = 0LL;
        dp[0][0][0] = 1LL;
        for(int i = 0;i <= n-1;i++)
        for(int j = 0;j <= i;j++)
        for(int t = 0;t < k;t++)    if(dp[i][j][t]){
            if(i+1 != n)    dp[i+1][j][t] += dp[i][j][t];
            LL tmp = pow_mod(2,i,k);
            LL mod = (tmp+t) % k;
            dp[i+1][j+1][(int)mod] += dp[i][j][t];
        }
        printf("Case %d: %lld\n",kase,dp[n][n/2][0]);
    }
    return 0;
}

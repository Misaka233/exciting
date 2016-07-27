#include<bits/stdc++.h>
using namespace std;
const int maxn=1500;
char s[maxn];
int N,P,lft,rht,base,mid;
double dp[maxn][maxn],pro;
double dfs(int l,int r)
{
    if(l<0||r<0) return 0;
    if(dp[l][r]>-0.5) return dp[l][r];
    double ans=dp[l][r]=lft-l+r*pro;
    if(l+r)
    {
        double pl=(double)(l)/(double)(l+r);
        double pr=(double)(r)/(double)(l+r);
        ans=min(ans,pro*(pl*dfs(l-1,r)+pr*dfs(l,r-1))+(l-pro)*(pl*(dfs(l-1,r)-(1-pro))+pr*dfs(l,r-1)));
    }
    return ans;
}
int main()
{
    scanf("%d%d%s",&N,&P,&s+1);
    pro=(double)(100-P)/100;
    for(int i=0;i<=N;i++) for(int j=0;j<N;j++) dp[i][j]=-1;
    for(int i=1;i<=N;i++) if(s[i]=='2')
    {
        mid=i;
        break;
    }
    for(int i=1;1<mid;i++) if(s[i]=='0') ++lft;else ++base;
    for(int i=mid+1;i<=N;i++) if(s[i]=='0') ++rht;
    printf("%.6lf\n",dfs(lft,rht)+base);
    return 0;
}


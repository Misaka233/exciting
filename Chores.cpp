#include<iostream>
#include<cstdio>

using namespace std;

int dp[10001];

void read(){
//    ifstream cin("in.txt");
    int i,j,k,s,t,p;
    int n;
    scanf("%d",&n);
    int ans=0;
    for(i=1;i<=n;i++)
    {
        cin>>j>>k;
        p=0;
        for(s=1;s<=k;s++)
        {
            scanf("%d",&t);
            p=max(p,dp[t]);
        }
        dp[i]=p+j;
        ans=max(dp[i],ans);
    }
    cout<<ans<<endl;
}

int main(){
    read();
    return 0;
}


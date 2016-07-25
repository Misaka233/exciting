#include<bits/stdc++.h>
using namespace std;
string s;
int l,k;
int dp[200010][30];
int call(int pos,int cnt,int mask)
{
    int x=__builtin_popcount(mask);
    if(pos<0)
    {
        if(!x) return 0;
        if(x==k) return 1;
        return 500000;
    }
    if(x>k) return 500000;
    int id=s[pos]-'a';
    int &ret=dp[pos][x];
    if(ret!=-1) return ret;
    ret=500000;
    if(x==k)
    {
        if(mask&(1<<id)) ret=min(ret,call(pos-1,x,mask));
        ret=min(ret,call(pos-1,x,0|(1<<id))+1);
    }
    else
        ret=min(ret,call(pos-1,x,mask|(1<<id)));
    return ret;
}
int main()
{
    int a[200010];
    int cnt;
    cin>>k;
    cin>>s;
    l=s.length();
    cnt=l-1;
    memset(dp,-1,sizeof(dp));
    for(int i=l-1;i>=0;i--)
    {
        int ans=call(i,0,0);
        if(ans==500000) a[cnt--]=-1;
        else a[cnt--]=ans;
    }
    for(int i=0;i<l;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

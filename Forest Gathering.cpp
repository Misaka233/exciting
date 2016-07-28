#include<bits/stdc++.h>
using namespace std;
const int maxn=100007;
long long N,W,L,H[maxn],R[maxn];
bool judge(long long x)
{
    long long sum=0;
    for(int i=1;i<=N;i++)
    {
        if((H[i]+R[i]*x)>=L) sum+=H[i]+R[i]*x;
        if(sum>W)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>N>>W>>L;
    for(int i=1;i<=N;i++)
    {
        scanf("%I64d%I64d",&H[i],&R[i]);
    }
    long long l=0,r=1e18,mid,ans;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(judge(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}

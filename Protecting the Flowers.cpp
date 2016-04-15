#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct misaka
{
    int t,d;
}cow[100010];
bool cmp(misaka cow1 , misaka cow2)
{
    return cow1.t*cow2.d<cow2.t*cow1.d;
}
int main()
{
    int n;
    long long ans=0;
    long long ct=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&cow[i].t,&cow[i].d);
        cow[i].t*=2;
    }
    sort(cow,cow+n,cmp);
    for(int i=0;i<n;i++)
    {
        ans+=ct*cow[i].d;;
        ct+=cow[i].t;
    }
    cout<<ans<<endl;
    return 0;
}

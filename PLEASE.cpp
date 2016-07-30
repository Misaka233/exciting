/************************************************
Author        :DarkTong
Created Time  :2016/7/15 19:27:41
File Name     :E.cpp
*************************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define INF 0x3f3f3f3f
#define esp 1e-9
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int maxn = 100000 + 100;
LL aa[maxn];

LL quick_mod(LL t,LL n)
{
    LL ans=1;
    while(n)
    {
        if(n&1) ans=ans*t%MOD;
        t=t*t%MOD;
        n>>=1;
    }
    return ans;
}
LL Inv(LL x)
{
    return quick_mod(x, MOD-2);
}



int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    LL inv3 = Inv(3);
    LL inv2 = Inv(2);

    int n, f=1, f2=0;
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld", &aa[i]);
        if(aa[i]%2==0) f=0;
        if(aa[i]>1) f2=1;
    }

    if(!f2)
    {
        puts("0/1");
        return 0;
    }


    LL b=1, a=1;
    b=quick_mod(2, aa[1]);
    for(int i=2;i<=n;++i)
    {
        b=quick_mod(b, aa[i]);
    }
    b=b*inv2%MOD;

    if(f)
    {
        a=((b-1+MOD)*inv3%MOD);
    }
    else
    {
        a=((b-2+MOD)*inv3%MOD+1)%MOD;
    }
    printf("%lld/%lld\n", a, b);

    return 0;
}

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

long long pow(long long a,int n)
{
    long long ret=1;
    long long temp=a;
    while(n)
    {
        if(n&1)ret*=temp;
        temp*=temp;
        n>>=1;
    }
    return ret;
}
int main()
{
    long long K;
    long long ans;
    while(scanf("%I64d",&K),K)
    {
        ans=0;
        long long temp=(long long)sqrt(K);
        if(temp*temp==K)ans+=(temp-1)/2;
        for(int z=3;z<31;z++)
        {
            for(long long x=1;;x++)
            {
                long long u=pow(x,z);
                if(u*2>=K)break;
                for(long long y=x+1;;y++)
                {
                    long long v=pow(y,z);
                    if(u+v+x*y*z>K)break;
                    if(u+v+x*y*z==K)ans++;
                }
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

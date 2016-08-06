#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF){
            if(n==0)return puts("0 0");
            n--;
    for(long long i=1;;i++)
    {
        long long cnt = i*6;
        if(n>=cnt)n-=cnt;
        else
        {
            if(n<i)
            {
                printf("%lld %lld\n",i*2-1-n,2+2*n);
                break;
            }
            n-=i;
            if(n<i)
            {
                printf("%lld %lld\n",i-2-2*n,2*i);
                break;
            }
            n-=i;
            if(n<i)
            {
                printf("%lld %lld\n",-1-i-n,2*i-2*n-2);
                break;
            }
            n-=i;
            if(n<i)
            {
                printf("%lld %lld\n",-2*i+1+n,-2+(-2)*n);
                break;
            }
            n-=i;
            if(n<i)
            {
                printf("%lld %lld\n",2-i+2*n,-2*i);
                break;
            }
            n-=i;
            printf("%lld %lld\n",i+n+1,2-2*i+2*n);
            break;

        }
    }
    }
    return 0;
}

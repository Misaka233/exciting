#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
long long bk;
long long bx;
long long Pow(long long m,long long n)
{
    long long b = 1;
    while (n > 0)
    {
          if (n & 1)
             b = b*m;
          n = n >> 1 ;
          m = m*m;
    }
    return b;
}
int main()
{
    long long x,y,k,co,ans;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>k;
        co=1;
        ans=0;
        while(k)
        {
            bx=x%2;
            if(bx==0)
            {
                bk=k%2;
                if(bk==1)
                {
                    ans+=Pow(2,co-1);
                }
                k/=2;
            }
            co++;
            x/=2;
        }
        cout<<ans<<endl;
    }

    return 0;
}

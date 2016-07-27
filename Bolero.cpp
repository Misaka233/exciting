#include<bits/stdc++.h>
using namespace std;
const int maxn=100002;
int n,m;
int p,k,g;
double sum,ans;
int percent[101];
struct misaka
{
    int s,d;
}num1[maxn];
struct misaka233
{
    int s,d,c;
}num2[maxn];
bool cmp1(misaka a,misaka b)
{
    return a.d<b.d;
}
bool cmp2(misaka233 a,misaka233 b)
{
    return a.c<b.c;
}
int main()
{
    int i,j;
    ans=0;
    for(int i=1;i<=100;i++)
    {
        percent[i]=100007;
    }
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&num1[i].s,&num1[i].d);
        ans=ans+num1[i].s*(100-num1[i].d);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&k,&p);
        percent[p]=min(percent[p],k);
    }
    sort(num1,num1+n,cmp1);
    for(int i=1;i<=100;i++)
    {
        if(percent[i]>n) continue;
        sum=0;g=0;j=0;
        while(j<n&&num1[j].d<=i)
        {
            sum+=num1[j++].s*(100-i);
            g++;
        }
        if(sum<ans)
        {
            if(g<percent[i])
            {
                for(int q=j;q<n;q++)
                {
                    num2[q-j].d=num1[q].d;
                    num2[q-j].s=num1[q].s;
                    num2[q-j].c=(num1[q].d-i)*num1[q].s;
                }
                sort(num2,num2+n-j,cmp2);
                for(int q=0;q<n-j;q++)
                {
                    if(g<percent[i])
                    {
                        sum+=num2[q].s*(100-i);
                        g++;
                    }
                    else
                    {
                        sum+=num2[q].s*(100-num2[q].d);
                    }
                }
            }
            else
            {
                for(;j<n;j++) sum+=num1[j].s*(100-num1[j].d);
            }
           if(sum<ans) ans=sum;
        }
    }
    printf("%.2lf\n",ans/100.00);
    return 0;
}

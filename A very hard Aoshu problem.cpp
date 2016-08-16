
#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;

int a[20];
int n;

bool solve(int s1,int s2,int t)
{
    int aa,b;
    aa=0;
    b=0;
    int temp=a[1];
    int p=1;
    for(int i=1;i<t;i++)
    {
        if(s1&(1<<(i-1)))
        {
            aa+=temp;
            temp=a[i+1];
        }
        else
        {
            temp*=10;
            temp+=a[i+1];
        }
    }
    aa+=temp;
    temp=a[t+1];
    for(int i=t+1;i<n;i++)
    {

        int qq=i-t-1;
        if(s2&(1<<qq))
        {
            b+=temp;
            temp=a[i+1];
        }
        else
        {
            temp*=10;
            temp+=a[i+1];
        }
    }
    b+=temp;
    if(aa==b)return true;
    else return false;
}
char str[30];
int main()
{
    //freopen("D.in","r",stdin);
   // freopen("D.out","w",stdout);
    while(scanf("%s",&str))
    {
        if(strcmp(str,"END")==0)break;
        int ans=0;
        n=strlen(str);
        for(int i=0;i<n;i++)
           a[i+1]=str[i]-'0';
        for(int i=1;i<n;i++)
        {
            int t1=(1<<(i-1));
            int t2=(1<<(n-i-1));
            for(int s1=0;s1<t1;s1++)
              for(int s2=0;s2<t2;s2++)
                if(solve(s1,s2,i))
                   ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

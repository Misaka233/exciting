#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int s1,s2,s3,s4,s5,s6;
    while(scanf("%d%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5,&s6)&&(s1+s2+s3+s4+s5+s6))
    {
        int boxnum=0;
        boxnum+=s6;
        boxnum+=s5;
        s1=max(0,s1-s5*11);
        boxnum+=s4;
        if(s2>=s4*5)
        {
            s2-=s4*5;
        }
        else
        {
            s1=max(0,s1-4*(s4*5-s2));
            s2=0;
        }
        boxnum+=(s3+3)/4;
        s3%=4;
        if(s3)
        {
            if(s2>=7-2*s3)
            {
                s2-=7-2*s3;
                s1=max(0,s1-8+s3);
            }
            else
            {
                s1=max(0,s1-(36-9*s3-s2*4));
                s2=0;
            }
        }
        boxnum+=(s2+8)/9;
        s2%=9;
        if(s2)
        {
            s1=max(0,s1-(36-s2*4));
        }
        boxnum+=(s1+35)/36;
        printf("%d\n",boxnum);
    }
    return 0;
}

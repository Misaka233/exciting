#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b,c,d;
    for(b=-100000;a<=100000;a++)
    {
        for(d=-100000;c<=100000;c++)
        {
            a=b+9;
            c=d+14;
            if(a+c==12&&b+d==2)
            {
                cout<<a<<" "<<b<<" "<<c<<" "<<d<<" ";
            }
        }
    }
    return 0;
}

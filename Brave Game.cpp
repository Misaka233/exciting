#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
    int c;
    scanf("%d",&c);
    while(c--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n%(m+1)==0) printf("second\n");
        else printf("first\n");
    }
    return 0;
}

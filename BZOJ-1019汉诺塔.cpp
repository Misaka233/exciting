
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

const int maxn=30+10;
long long f[3][maxn];
int g[3][maxn];
int from[7],to[7];

int main()
{
    int n; cin>>n;
    for(int i=0;i<6;i++)
    {
        char s[5];
        scanf("%s",s);
        from[i]=s[0]-'A';
        to[i]=s[1]-'A';
    }
    f[0][1]=f[1][1]=f[2][1]=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(from[j]==i) { g[i][1]=to[j]; break; }
        }
    }
    for(int i=2;i<n+1;i++) {
        for(int x=0;x<3;x++) {
            int y=g[x][i-1];
            int z=0+1+2-x-y;
            if(g[y][i-1]==z) f[x][i]=f[x][i-1]+1+f[y][i-1],g[x][i]=z;
            else f[x][i]=f[x][i-1]+1+f[y][i-1]+1+f[x][i-1],g[x][i]=y;
        }
    }
    printf("%lld\n",f[0][n]);
}

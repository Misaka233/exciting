#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=107;
double map[maxn][maxn];
int n,m,u,v;
double w;
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(map[i][j]<map[i][k]*map[k][j])
                    map[i][j]=map[i][k]*map[k][j];
            }
        }
    }
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
        {
            map[i][i]=1;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%lf",&u,&v,&w);
            map[u][v]=map[v][u]=w/100.0;
        }
        floyd();
        printf("%.6lf percent\n",map[1][n]*100);
    }
    return 0;
}

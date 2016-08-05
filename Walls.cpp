#include <iostream>
#include <cstdio>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
int n,m,club[300];
int town[300];
map<int,int> exist;
int dis[300][300];
vector<int> region[300];
void floyd()
{
    for(int k=1;k<=m;k++)
    for(int i=1;i<=m;i++)
    for(int j=1;j<=m;j++)
    {
        if(dis[i][j]>dis[i][k]+dis[k][j])
            dis[i][j]=dis[i][k]+dis[k][j];
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&m)!=EOF)
    {
        int ans=100000000;
        memset(dis,63,sizeof(dis));
        for(int i=1;i<=m;i++)
            dis[i][i]=0;
        exist.clear();
        scanf("%d",&n);
        int num;
        scanf("%d",&num);
        for(int i=0;i<num;i++)
            scanf("%d",&club[i]);
        for(int i=1;i<=n;i++)
            region[i].clear();
        for(int area=1;area<=m;area++)
        {
            int temp;
            scanf("%d",&temp);
            for(int i=0;i<temp;i++)
            {
                scanf("%d",&town[i]);
                region[town[i]].push_back(area);
            }
            for(int i=0;i<temp-1;i++)
            {
                int tt;
                if(town[i]<town[i+1])
                    tt=town[i]*1000+town[i+1];
                else tt=town[i+1]*1000+town[i];
                int t=exist[tt];
                if(t)
                    dis[t][area]=dis[area][t]=1;
                else exist[tt]=area;
            }
            int tt;
            if(town[0]<town[temp-1])
                tt=town[0]*1000+town[temp-1];
            else tt=town[temp-1]*1000+town[0];
            int t=exist[tt];
            if(t)
                dis[t][area]=dis[area][t]=1;
            else exist[tt]=area;
        }
        floyd();
        for(int i=1;i<=m;i++)
        {
            int tt=0;
            for(int j=0;j<num;j++)
            {
                int temp=1000000000;
                for(int k=0;k<region[club[j]].size();k++)
                {
                    temp=min(temp,dis[region[club[j]][k]][i]);
                }
                tt+=temp;
            }
            ans=min(tt,ans);
        }
        printf("%d\n",ans);
    }
}

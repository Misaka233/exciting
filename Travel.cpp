/*
题目大意：
   去掉给定的边，看每一个点是否能从别的点到达！
    如果能够到达，则求出对于每一个点到其他所有的点最短距离之和，将这些和相加就是最后的结果
解法：
    对每个顶点求一次最短路，然后用sum[i]将各个顶点的最短路的和保存起来！
    对将要删除的每个顶点，如果求最短路u能够到达v,则再就一遍v,分别记为sum_u,sum_v
    那么答案即为：sum[1]+...+sum[n]+sum_u+sum_v-sum[u]-sum[v];
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 250;
const int INF=99999999;
struct Node
{
    int v,next,w;
    bool operator < (const Node &a) const
    {
        return w > a.w;
    }
} Edge[2000002],t1,t2;
int dis[N],vis[N],head[N],cnt,n,m,sum[N],num[3002];
void addEdge(int u,int v,int w)
{
    Edge[cnt].v = v;
    Edge[cnt].next = head[u];
    Edge[cnt].w = w;
    head[u]=cnt++;
}
void dijstra(int  st)
{
    priority_queue<Node> q;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n+1;i++)dis[i]=INF;
    for(int i = head[st] ; i != -1 ; i = Edge[i].next)
    {
        int v = Edge[i].v;
        if(Edge[i].w<dis[v])
        {
            dis[v] = Edge[i].w;
            t1.w = dis[v];
            t1.v =  v;
            q.push(t1);
        }
    }
    dis[st]=0;//此句没加错了2次，囧~~~
    vis[st] = 1;
    while(!q.empty())
    {
        t1 = q.top();
        q.pop();
        int u = t1.v;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i != -1; i = Edge[i].next)
        {
            int v = Edge[i].v;
            if(!vis[v] && dis[v]>dis[u]+Edge[i].w)
            {
                dis[v] =dis[u]+Edge[i].w;
                t2.v = v;
                t2.w = dis[v];
                q.push(t2);
            }
        }
    }
   return;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        memset(sum,0,sizeof(sum));
        memset(num,-1,sizeof(num));
        cnt=0;
        int ans=0,res;
        int u,v;
        for(j=1; j<=m; j++)
        {
            cin>>u>>v;
            num[j]=cnt;
            addEdge(u,v,1);
            addEdge(v,u,1);
        }
        for(i=1;i<=n;i++)
        {
            dijstra(i);
            for(j=1;j<=n;j++)sum[i]+=dis[j];
            ans+=sum[i];
        }
        for(i=1;i<=m;i++)
        {
            if(ans>=INF)
            {
                printf("INF\n");continue;
            }
            Edge[num[i]^1].w=Edge[num[i]].w=INF;
            res=0;
            dijstra(Edge[num[i]].v);
            for(j=1;j<=n;j++)res+=dis[j];
            if(res>=INF)
            {
                printf("INF\n");
            }else
            {
                 dijstra(Edge[num[i]^1].v);
                 for(j=1;j<=n;j++)res+=dis[j];
                 if(res>=INF)printf("INF\n");
                 else printf("%d\n",ans+res-(sum[Edge[num[i]].v]+sum[Edge[num[i]^1].v]));
            }
            Edge[num[i]^1].w=Edge[num[i]].w=1;
        }
    }
    return 0;
}



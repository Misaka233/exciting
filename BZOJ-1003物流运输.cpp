#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MAXN=110;
const int INF=0x3f3f3f3f;
int N,M,K,D;
struct Edge
{
    int v;
    int cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
    E[v].push_back(Edge(u,w));
}
int vis[MAXN];//在队列标志
int cnt[MAXN];//每个点的入队列次数
int dist[MAXN];
int f[MAXN];
int visable[MAXN][MAXN];
int SPFA(int L,int R)
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=M;i++)dist[i]=INF;
    for(int i=L;i<=R;i++)
        for(int j=1;j<=M;j++)
            if(visable[i][j]) vis[j]=2;
    vis[1]=true;
    dist[1]=0;
    queue<int>que;
    while(!que.empty())que.pop();
    que.push(1);
    memset(cnt,0,sizeof(cnt));
    cnt[1]=1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[u][i].v;
            if(vis[v]!=2&&dist[v]>dist[u]+E[u][i].cost)
            {
                dist[v]=dist[u]+E[u][i].cost;
                if(!vis[v])
                {
                    vis[v]=true;
                    que.push(v);
                    if(++cnt[v]>M)return false;
            //cnt[i]为入队列次数，用来判定是否存在负环回路
                }
            }
        }
    }
    return dist[M];
}
int main()
{
    int l,r,d,u,v,w;
    scanf("%d%d%d%d",&N,&M,&K,&D);
    for(int i=1;i<=D;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }
    scanf("%d",&d);
    for(int i=1;i<=d;i++)
    {
        scanf("%d%d%d",&u,&l,&r);
        for(int j=l;j<=r;j++) visable[j][u]=1;
    }
    for(int i=1;i<=N;i++)
    {
        f[i]=SPFA(1,i);
        if(f[i]<INF) f[i]*=i;
        for(int j=1;j<i;j++)
        {
            int cost=SPFA(j+1,i);
            if(cost==INF) continue;
            f[i]=min(f[i],f[j]+cost*(i-j)+K);
        }
    }
    cout<<f[N]<<endl;
    return 0;
}

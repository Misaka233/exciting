#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=1000000;
struct node
{
    int v,c;
    node(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator<(const node &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};

vector<Edge>e[MAXN];
bool must[MAXN];
bool vis[MAXN];
int dist[MAXN];
int path[100][100];
void Dijkstra(int n,int start)//点的编号从1开始
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)dist[i]=INF;
    priority_queue<node>que;
    while(!que.empty()) que.pop();
    dist[start]=0;
    que.push(node(start,0));
    node tmp;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<e[u].size();i++)
        {
            int v=e[tmp.v][i].v;
            int cost=e[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                que.push(node(v,dist[v]));
            }
        }
    }
}
void init()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            path[i][j]=INF;
        }
    }
}
int main()
{
    init();
    int id,u,v,cost,s,t;
    int bian=0;
    while(scanf("%d%d%d%d",&id,&u,&v,&cost)!=EOF)
    {
        e[u].push_back(Edge(v,cost,id+1));
        bian++;
    }
    scanf("%d%d",&s,&t);
    while(scanf("%d|",&k)!=EOF)
    {
        must[k]=true;
    }
    for(int i=0;i<NN;i++)
    {
        fol(i,)
    }

    return 0;
}

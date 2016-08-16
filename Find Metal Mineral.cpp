#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Node
{
    int now,next,val;
}tree[20005];

int dp[10005][15];
int head[10005];
int n,s,k,len;

void add(int x,int y,int w)//建树
{
    tree[len].now = y;
    tree[len].val = w;
    tree[len].next = head[x];
    head[x] = len++;
}

void dfs(int root,int p)
{
    int i,j,l,son;
    for(i = head[root];i!=-1;i = tree[i].next)
    {
        son = tree[i].now;
        if(son == p)
        continue;
        dfs(son,root);
        for(j = k;j>=0;j--)
        {
            dp[root][j]+=dp[son][0]+2*tree[i].val;//先将dp[son][0]放进背包，由于dp[son][0]是表示用一个机器人去走完所有子树，最后又回到pos这个节点，所以花费要乘以2
            for(l = 1;l<=j;l++)//在这里找到比dp[son][0]更优的方案，分组背包
            dp[root][j] = min(dp[root][j],dp[root][j-l]+dp[son][l]+l*tree[i].val);
        }
    }
}

int main()
{
    int i,x,y,w;
    while(~scanf("%d%d%d",&n,&s,&k))
    {
        len = 0;
        memset(head,-1,sizeof(head));
        memset(dp,0,sizeof(dp));
        for(i = 1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            add(x,y,w);
            add(y,x,w);
        }
        dfs(s,-1);
        printf("%d\n",dp[s][k]);
    }

    return 0;
}


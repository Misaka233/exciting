#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
const int MAXN=100010;
int rmq[2*MAXN];//rmq����
struct ST
{
    int mm[2*MAXN];
    int dp[2*MAXN][20];//��Сֵ��Ӧ���±�
    void init(int n)
    {
    mm[0] = -1;
    for(int i = 1;i <= n;i++)
    {
    mm[i] = ((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
    dp[i][0] = i;
    }
    for(int j = 1; j <= mm[n];j++)
        for(int i = 1; i + (1<<j) - 1 <= n; i++)
            dp[i][j] = rmq[dp[i][j-1]] < rmq[dp[i+(1<<(j-1))][j-1]]?dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
    }
    int query(int a,int b)//��ѯ[a,b]֮����Сֵ���±�
    {
        if(a > b)swap(a,b);
        int k = mm[b-a+1];
        return rmq[dp[a][k]] <= rmq[dp[b-(1<<k)+1][k]]?dp[a][k]:dp[b-(1<<k)+1][k];
    }
};
//�ߵĽṹ�嶨��
struct Node
{
    int to,next;
};
struct lca2rmq
{
    int n;
    Node edge[2*MAXN];
    int tol;
    int head[MAXN];
    bool vis[MAXN];
    int F[2*MAXN];
    int P[2*MAXN];
    int cnt;
    ST st;
    void init(int n)
    {
        this->n=n;
        tol=0;
        memset(head,-1,sizeof(head));
    }
    void addedge(int a,int b)
    {
        edge[tol].to=b;
        edge[tol].next=head[a];
        head[a]=tol++;
        edge[tol].to=a;
        edge[tol].next=head[b];
        head[b]=tol++;
    }
    int query(int a,int b)
    {
        return F[st.query(P[a],P[b])];
    }
    void dfs(int a,int lev)
    {
        vis[a]=true;
        ++cnt;//�ȼӣ���֤F���к�rmq���д�1��ʼ
        F[cnt]=a;//ŷ�����У���Ŵ�1��ʼ����2*n-1��Ԫ��
        rmq[cnt]=lev;//rmq�������������
        P[a]=cnt;
        for(int i=head[a];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(vis[v])continue;
            dfs(v,lev+1);
            ++cnt;
            F[cnt]=a;
            rmq[cnt]=lev;
        }
    }
     void solve(int root)
    {
        memset(vis,false,sizeof(vis));
        cnt=0;
        dfs(root,0);
        st.init(2*n-1);
    }
}lca;
bool flag[MAXN];
map<string,int>mp;
int deep[MAXN];
vector<int>vec[MAXN];
void bfs(int root)
{
    memset(deep,0,sizeof(deep));
    queue<int>q;
    while(!q.empty())q.pop();
    deep[root]=1;
    q.push(root);
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        int sz=vec[tmp].size();
        for(int i=0;i<sz;i++)
        {
            if(deep[vec[tmp][i]]==0)
            {
                deep[vec[tmp][i]]=deep[tmp]+1;
                q.push(vec[tmp][i]);
            }
        }
    }
}

int main()
{
    int T;
    int N,m;
    int u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&m);
        memset(flag,false,sizeof(flag));
        lca.init(N);
        string str1,str2;
        int id=0;
        mp.clear();
        for(int i=1;i<=N;i++)vec[i].clear();
        for(int i=1;i<N;i++)
        {
            cin>>str1>>str2;
            if(mp[str1]==0)mp[str1]=++id;
            if(mp[str2]==0)mp[str2]=++id;
            u=mp[str1];
            v=mp[str2];
            vec[v].push_back(u);
            lca.addedge(v,u);
            flag[u]=true;
        }
        int root;
        for(int i=1;i<=N;i++)
          if(!flag[i])
          {
              root=i;
              break;
          }
        lca.solve(root);
        bfs(root);
        while(m--)
        {
            cin>>str1>>str2;
            u=mp[str1];
            v=mp[str2];
            int tmp=lca.query(u,v);

            int ans=deep[u]-deep[tmp];
            if(tmp!=v)ans++;
            printf("%d\n",ans);
        }

    }
    return 0;
}

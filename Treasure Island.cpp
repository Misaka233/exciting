#include<bits/stdc++.h>
using namespace std;



char sc[55][55];
int a[55][55],n,m,s,vis[55][55];

int dx[]={-1,0,0,1,-1};
int dy[]={-1,1,-1,0,0};

void dfs(int x,int y)
{
    vis[x][y]=1;
    s++;
    for(int i=1;i<=4;i++)  {
       int xx=x+dx[i],yy=y+dy[i];
       if(a[xx][yy]&&!vis[xx][yy]) dfs(xx,yy);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        int x,y,cnt=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",sc[i]+1);
            for(int j=1;j<=m;j++) if(sc[i][j]=='.') {a[i][j]=1;x=i;y=j;}
                     else if(sc[i][j]=='?') a[i][j]=2;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        if(a[i][j]==1&&!vis[i][j]){
            s=0;cnt++;
            dfs(i,j);
        }
        if(cnt>1) {printf("Impossible\n");continue;}
        int s0=s,ok=0;
        for(int i=1;i<=n&&!ok;i++)  for(int j=1;j<=m&&!ok;j++)
        if(a[i][j]==2){
            memset(vis,0,sizeof(vis));
            a[i][j]=0;
            s=0;
            dfs(x,y);
            if(s==s0) ;
            else if(s==s0-1)  ok=1;
            else a[i][j]=1;
        }
        if(ok) {printf("Ambiguous\n");continue;}
        for(int i=1;i<=n;i++) {
                for(int j=1;j<=m;j++)
                if(a[i][j]) printf(".");
                else printf("#");
        printf("\n");
        }
    }
    return 0;
}


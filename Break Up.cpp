#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e3+5;
const int INF = 1e9+7;
typedef long long LL;
int s,t,n,m;
int a[N*30],b[N*30],c[N*30];
vector<int>g[N];
bool ban[30*N];
int dfn[N],low[N],clk,bel[N],cnt;
stack<int>st;
void targin(int u,int f){
  dfn[u]=low[u]=++clk;
  bool flag=0;st.push(u);
  for(int i=0;i<g[u].size();++i){
      if(ban[g[u][i]])continue;
      int v=u==a[g[u][i]]?b[g[u][i]]:a[g[u][i]];
      if(v==f&&!flag){flag=1;continue;}
      if(!dfn[v]){
        targin(v,u);
        low[u]=min(low[u],low[v]);
      }
      else low[u]=min(low[u],dfn[v]);
  }
  if(dfn[u]==low[u]){
    ++cnt;int x;
    do{
      x=st.top();
      st.pop();
      bel[x]=cnt;
    }while(x!=u);
  }
}
int path[N*2];
int vis[N];
bool find_pre(int u,int d){
  vis[u]=d;
  if(u==t)return true;
  for(int i=0;i<g[u].size();++i){
    int v=u==a[g[u][i]]?b[g[u][i]]:a[g[u][i]];
    if(vis[v])continue;
    path[d]=g[u][i];
    if(find_pre(v,d+1))return true;
  }
  return false;
}
vector<int>G[N];
int find_brige(int u,int f,int id){
   if(bel[t]==u)return id;
   for(int i=0;i<G[u].size();++i){
     int x=bel[a[G[u][i]]],y=bel[b[G[u][i]]];
     int v=u==x?y:x;
     if(v==f)continue;
     int tmp=id;if(c[G[u][i]]<c[id])tmp=G[u][i];
     tmp=find_brige(v,u,tmp);
     if(tmp)return tmp;
   }
   return 0;
}
int main(){
    c[0]=INF;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;++i){
       scanf("%d%d%d",&a[i],&b[i],&c[i]);
       if(a[i]!=b[i])
        g[a[i]].push_back(i),g[b[i]].push_back(i);
    }
    if(!find_pre(s,1)){printf("0\n0\n");return 0;}
    int ans1=-1,id;
    int ans2=-1,id1,id2;
    for(int i=1;i<vis[t];++i){
      ban[path[i]]=true;
      memset(dfn,0,sizeof(dfn));cnt=clk=0;
      for(int j=1;j<=n;++j)if(!dfn[j])targin(j,0);
      if(bel[s]==bel[t]){ban[path[i]]=false;continue;}
      for(int j=0;j<N;++j)G[j].clear();
      for(int j=1;j<=m;++j){
         if(ban[j]||bel[a[j]]==bel[b[j]])continue;
         G[bel[a[j]]].push_back(j);
         G[bel[b[j]]].push_back(j);
      }
      int cur=find_brige(bel[s],0,0);
      if(!cur){
        if(ans1==-1||ans1>c[path[i]])
          ans1=c[path[i]],id=path[i];
      }
      else{
         if(ans2==-1||ans2>c[path[i]]+c[cur]){
           ans2=c[path[i]]+c[cur];
           id1=cur;id2=path[i];
         }
      }
      ban[path[i]]=false;
    }
    if(ans1==-1&&ans2==-1)printf("-1\n");
    else if(ans1!=-1&&ans2==-1){
       printf("%d\n1\n%d\n",ans1,id);
    }
    else if(ans1==-1&&ans2!=-1){
       printf("%d\n2\n%d %d\n",ans2,id1,id2);
    }
    else{
      if(ans1<=ans2)printf("%d\n1\n%d\n",ans1,id);
      else printf("%d\n2\n%d %d\n",ans2,id1,id2);
    }
    return 0;
}

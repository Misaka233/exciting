#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=205;

int n,m,g[maxn][maxn];
int linker[maxn],used[maxn];
bool dfs(int u)
{
    for(int v = 1; v <=n;v++)
    if(g[u][v] && !used[v])
    {
        used[v] = true;
        if(linker[v] == -1 || dfs(linker[v]))
        {
            linker[v] = u;
            return true;
        }
    }
    return false;
}
int hungary()
{
    int res = 0;
    memset(linker,-1,sizeof(linker));
    for(int u = 1;u <=n;u++)
    {
        memset(used,false,sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}
int main(){
	int i,j,num,tmp;
	while(~scanf("%d%d",&n,&m)){
		memset(g,0,sizeof(g));

		for(i=1;i<=n;i++){
			scanf("%d",&num);
			for(j=1;j<=num;j++){
				scanf("%d",&tmp);
				g[i][tmp]=1;
			}
		}

		printf("%d\n",hungary());
	}
	return 0;
}

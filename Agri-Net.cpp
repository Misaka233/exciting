#include <iostream>
#include<cstdio>
using namespace std;
const int MAXV=101;
const int inf=1<<30;

int map[MAXV][MAXV],n;

void prim(){
    int i,j,d[MAXV],vis[MAXV],mi,v;
    for(i=1;i<=n;i++){
        d[i]=map[1][i];
        vis[i]=0;
    }
    for(i=1;i<=n;i++){
        mi=inf;
        for(j=1;j<=n;j++)
            if(!vis[j] && d[j]<mi){
                mi=d[j];
                v=j;
            }
        vis[v]=1;
        for(j=1;j<=n;j++)
            if(!vis[j] && d[j]>map[v][j])
                d[j]=map[v][j];
    }
    for(d[0]=0,i=1;i<=n;i++) d[0]+=d[i];

    printf("%d\n",d[0]);
}

int main(){
    int i,j;
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&map[i][j]);
        prim();
    }
    return 0;
}

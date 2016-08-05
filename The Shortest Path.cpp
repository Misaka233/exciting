#include<iostream>
#include<cstdio>
const int N=100;
const int inf=10000000;
using namespace std;

int edge[N][N];
int n,m;
struct Matrix{
    int map[N][N];
};
struct ReMatrix{
    int Map[N];
};

Matrix matrix[N];
ReMatrix rematrix[N];

void cmp(const int &a,const int &b){
//判断矩阵是否相等
    for(int i=1;i<=m;i++){
        if(rematrix[0].Map[i]!=rematrix[b].Map[i])
            return ;
    }
    edge[a][b]=1;
}

void CreateMap(const int &p,const int &q){
    for(int i=1;i<=m;i++){
        rematrix[0].Map[i]=0;
        for(int j=1;j<=m;j++){
            rematrix[0].Map[i]+=matrix[p].map[i][j]*rematrix[q].Map[j];  //就是两个矩阵相乘。。
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=p&&i!=q)cmp(p,i);
    }
}


void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            //if(i==k||edge[i][k]==inf)continue; //加了就ＷＡ了
            for(int j=1;j<=n;j++){
                //if(j==k||edge[j][k]==inf)continue;
                if(edge[i][j]>edge[i][k]+edge[k][j]){
                    edge[i][j]=edge[i][k]+edge[k][j];
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
        for(int i=1;i<=n;i++){
            edge[i][i]=0;
            for(int j=i+1;j<=n;j++){
                edge[i][j]=edge[j][i]=inf;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                rematrix[i].Map[j]=0;
                for(int k=1;k<=m;k++){
                    scanf("%d",&matrix[i].map[j][k]);
                    rematrix[i].Map[j]+=matrix[i].map[j][k]*k;  //化二维数组为一维数组，矩阵优化
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                else CreateMap(i,j);
            }
        }
        floyd();
        int t;
        scanf("%d",&t);
        while(t--){
            int v0,v;
            scanf("%d%d",&v0,&v);
            if(edge[v0][v]<inf){
                printf("%d\n",edge[v0][v]);
            }else
                printf("Sorry\n");
        }
    }
    return 0;
}

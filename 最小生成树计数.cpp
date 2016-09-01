#include<iostream>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<cstdlib>  
#include<algorithm>  
#include<vector>  
using namespace std;  
   
const int N=111;  
const int M=1111;  
const int mod=31011;  
   
struct Edges  
{  
    int a,b,c;  
    bool operator<(const Edges & x)const  
    {  
        return c<x.c;  
    }  
} edge[M];  
   
int n,m;  
int f[N],U[N],vist[N];//f,U都是并查集，U是每组边临时使用  
int G[N][N],C[N][N];//G顶点之间的关系，C为生成树计数用的Kirchhoff矩阵  
   
vector<int>V[N];//记录每个连通分量  
   
int Find(int x,int f[])  
{  
    if(x==f[x])  
        return x;  
    else  
        return Find(f[x],f);  
}  
   
int det(int a[][N],int n)//生成树计数:Matrix-Tree定理  
{  
    for(int i=0; i<n; i++)  
        for(int j=0; j<n; j++)  
            a[i][j]%=mod;  
    int ret=1;  
    for(int i=1; i<n; i++)  
    {  
        for(int j=i+1; j<n; j++)  
            while(a[j][i])  
            {  
                int t=a[i][i]/a[j][i];  
                for(int k=i; k<n; k++)  
                    a[i][k]=(a[i][k]-a[j][k]*t)%mod;  
                for(int k=i; k<n; k++)  
                    swap(a[i][k],a[j][k]);  
                ret=-ret;  
            }  
        if(a[i][i]==0)  
            return 0;  
        ret=ret*a[i][i]%mod;  
    }  
    if(ret<0)  
        ret=-ret;  
    return (ret+mod)%mod;  
}  
   
void Solve()  
{  
    sort(edge,edge+m);//按权值排序  
    for(int i=1; i<=n; i++)//初始化并查集  
    {  
        f[i]=i;  
        vist[i]=0;  
    }  
   
    int Edge=-1;//记录相同的权值的边  
    int ans=1;  
    for(int k=0; k<=m; k++)  
    {  
        if(edge[k].c!=Edge||k==m)//一组相等的边,即权值都为Edge的边加完  
        {  
            for(int i=1; i<=n; i++)  
            {  
                if(vist[i])  
                {  
                    int u=Find(i,U);  
                    V[u].push_back(i);  
                    vist[i]=0;  
                }  
            }  
            for(int i=1; i<=n; i++) //枚举每个连通分量  
            {  
                if(V[i].size()>1)  
                {  
                    for(int a=1; a<=n; a++)  
                        for(int b=1; b<=n; b++)  
                            C[a][b]=0;  
                    int len=V[i].size();  
                    for(int a=0; a<len; a++) //构建Kirchhoff矩阵C  
                        for(int b=a+1; b<len; b++)  
                        {  
                            int a1=V[i][a];  
                            int b1=V[i][b];  
                            C[a][b]=(C[b][a]-=G[a1][b1]);  
                            C[a][a]+=G[a1][b1];//连通分量的度  
                            C[b][b]+=G[a1][b1];  
                        }  
                    int ret=(int)det(C,len);  
                    ans=(ans*ret)%mod;//对V中的每一个连通块求生成树个数再相乘  
                    for(int a=0; a<len; a++)  
                        f[V[i][a]]=i;  
                }  
            }  
            for(int i=1; i<=n; i++)  
            {  
                U[i]=f[i]=Find(i,f);  
                V[i].clear();  
            }  
            if(k==m)  
                break;  
            Edge=edge[k].c;  
        }  
   
        int a=edge[k].a;  
        int b=edge[k].b;  
        int a1=Find(a,f);  
        int b1=Find(b,f);  
        if(a1==b1)  
            continue;  
        vist[a1]=vist[b1]=1;  
        U[Find(a1,U)]=Find(b1,U);//并查集操作  
        G[a1][b1]++;  
        G[b1][a1]++;  
    }  
   
    int flag=0;  
    for(int i=2; i<=n&&!flag; i++)  
        if(U[i]!=U[i-1])  
            flag=1;  
    if(m==0)  
        flag=1;  
    printf("%d\n",flag?0:ans%mod);  
   
}  
   
int main()  
{  
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);  
    while(~scanf("%d%d",&n,&m))  
    {  
        memset(G,0,sizeof(G));  
        for(int i=1; i<=n; i++)  
            V[i].clear();  
        for(int i=0; i<m; i++)  
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);  
        Solve();  
    }  
    return 0;  
}  

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
int f[N],U[N],vist[N];//f,U���ǲ��鼯��U��ÿ�����ʱʹ��  
int G[N][N],C[N][N];//G����֮��Ĺ�ϵ��CΪ�����������õ�Kirchhoff����  
   
vector<int>V[N];//��¼ÿ����ͨ����  
   
int Find(int x,int f[])  
{  
    if(x==f[x])  
        return x;  
    else  
        return Find(f[x],f);  
}  
   
int det(int a[][N],int n)//����������:Matrix-Tree����  
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
    sort(edge,edge+m);//��Ȩֵ����  
    for(int i=1; i<=n; i++)//��ʼ�����鼯  
    {  
        f[i]=i;  
        vist[i]=0;  
    }  
   
    int Edge=-1;//��¼��ͬ��Ȩֵ�ı�  
    int ans=1;  
    for(int k=0; k<=m; k++)  
    {  
        if(edge[k].c!=Edge||k==m)//һ����ȵı�,��Ȩֵ��ΪEdge�ı߼���  
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
            for(int i=1; i<=n; i++) //ö��ÿ����ͨ����  
            {  
                if(V[i].size()>1)  
                {  
                    for(int a=1; a<=n; a++)  
                        for(int b=1; b<=n; b++)  
                            C[a][b]=0;  
                    int len=V[i].size();  
                    for(int a=0; a<len; a++) //����Kirchhoff����C  
                        for(int b=a+1; b<len; b++)  
                        {  
                            int a1=V[i][a];  
                            int b1=V[i][b];  
                            C[a][b]=(C[b][a]-=G[a1][b1]);  
                            C[a][a]+=G[a1][b1];//��ͨ�����Ķ�  
                            C[b][b]+=G[a1][b1];  
                        }  
                    int ret=(int)det(C,len);  
                    ans=(ans*ret)%mod;//��V�е�ÿһ����ͨ�������������������  
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
        U[Find(a1,U)]=Find(b1,U);//���鼯����  
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

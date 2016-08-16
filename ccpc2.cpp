//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cctype>
#include<string>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<map>
#include<set>
using namespace std;
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back(x)
typedef long long LL;
//typedef unsigned __int64 ULL;
/* ****************** */
const int INF = 100011122;
const double INFF = 1e100;
const double eps = 1e-8;
const int mod = 1000000007;
const int NN = 110;
const int MM = 5000010;
/* ****************** */

int pri[NN], a[NN];
bool vis[10010];
int gss[NN][NN];

void init()
{
    int i, j, n = 10000, tol = 0;
    memset(vis, false, sizeof(vis));
    for(i = 2; i < n; i ++)
    {
        if(!vis[i])
        {
            pri[tol++] = i;
            if(tol == 100) return;
            for(j = i + i; j < n; j += i)
                vis[j] = true;
        }
    }
}
//返回行列式的秩，编号都从0开始
int gauss(int n,int m)
{
    int i, j, k, kk, pca;
   // int temp;
    for(i = 0, j = 0; i < n && j < m; i ++, j ++)
    {
        pca = i;
        for(k = i + 1; k < n; k ++)
        {
            if(abs(gss[k][j]) > abs(gss[pca][j]))
                pca = k;
        }
        if(pca != i)
        {
            for(k = j; k < m; k ++)
            {
                swap(gss[i][k], gss[pca][k]);
            }
        }
        if(gss[i][j] == 0)
        {
            i--;
            continue;
        }
        for(k = i + 1; k < n; k ++)
        {
          //  temp = gss[k][j]/gss[i][j];
            if(gss[k][j]==0) continue;
            gss[k][j] = 0;
            for(kk = j + 1; kk < m; kk ++)
            {
               // gss[k][kk] -= gss[i][kk]*temp;
               gss[k][kk] ^= gss[i][kk];
            }
        }
    }
    return i;
}

int main()
{
    init();
    LL A, B, limit = 10000000000000000LL;
    int ans;
    int t, m, n, i, j,T;
    cin>>T;
    int cas=0;
    n=100;
    while(T--)
    {
    	cas++;
    	scanf("%d",&m);
        for(i = 0; i < m; i ++)
        {
            scanf("%d", &t);
            for(j = 0; j < n; j ++)
            {
                gss[j][i] = 0;
                while(t%pri[j] == 0)
                {
                    gss[j][i] ++;
                    t /= pri[j];
                }
                gss[j][i] %= 2;
            }
        }
		printf("Case #%d:\n",cas);
        ans = m - gauss(n, m);

        A = B = 0;
        for(int i = 0; i < ans; i ++)
        {
            A <<= 1;
            A%=mod;
            B <<= 1;
            B ++;
            A += B/limit;
            B %= limit;
        }
        if(A == 0)
            printf("%lld\n",B);
        else
        {
            printf("%lld",A);
            printf("%016lld\n",B);
        }
    }
    return 0;
}


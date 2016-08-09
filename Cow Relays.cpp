#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define MAXN 1005
#define MAXM 500005
#define INF 1000000000
using namespace std;
int k, m, s, t;
int ans[MAXN][MAXN], mp[MAXN][MAXN], tmp[MAXN][MAXN], dis[MAXN][MAXN];
int used[MAXN], v[MAXN], num;
void floyd(int c[][MAXN], int a[][MAXN], int b[][MAXN])
{
    for(int k = 0; k < num; k++)
        for(int i = 0; i < num; i++)
            for(int j = 0; j < num; j++)
                if(c[v[i]][v[j]] > a[v[i]][v[k]] + b[v[k]][v[j]])
                    c[v[i]][v[j]] = a[v[i]][v[k]] + b[v[k]][v[j]];
}
void copy(int a[][MAXN], int b[][MAXN])
{
    for(int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
        {
            a[v[i]][v[j]] = b[v[i]][v[j]];
            b[v[i]][v[j]] = INF;
        }
}
void slove(int k)
{
    while(k)
    {
        if(k & 1)
        {
            floyd(dis, ans, mp);
            copy(ans, dis);
        }
        floyd(tmp, mp, mp);
        copy(mp, tmp);
        k >>= 1;
    }
}
int main()
{
    int x, y, w;
    scanf("%d%d%d%d", &k, &m, &s, &t);
    for(int i = 0; i <= 1000; i++)
    {
        for(int j = 0; j <= 1000; j++)
        {
            mp[i][j] = INF;
            tmp[i][j] = INF;
            dis[i][j] = INF;
            ans[i][j] = INF;
        }
        ans[i][i] = 0;
    }
    num = 0;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &w, &x, &y);
        if(!used[x])
        {
            used[x] = 1;
            v[num++] = x;
        }
        if(!used[y])
        {
            used[y] = 1;
            v[num++] = y;
        }
        if(mp[x][y] > w)
            mp[x][y] = mp[y][x] = w;
    }
    slove(k);
    printf("%d\n", ans[s][t]);
    return 0;
}


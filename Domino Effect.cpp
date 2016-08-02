#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAXN =  0x3f3f3f3f;
const int  MINN =  -0x3f3f3f3f;
const double eps = 1e-9;
const int dir[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{-1,1},{1,1},{1,-1},{-1,-1}};
const int MAX = 500+10;
int dist[MAX], S[MAX], edge[MAX][MAX], n, m;
void dijkstra(int v0)
{
    int i, j;
    for (i = 1; i <= n; ++i)
    {
        S[i] = 0; dist[i] = edge[v0][i];
    }
    S[v0] = 1;
    for (i = 1; i < n; ++i)
    {
        int Min = MAXN, u;
        for (j = 1; j <= n; ++j)
        {
            if (S[j] == 0 && Min > dist[j])
            {
                Min = dist[j]; u = j;
            }
        }
        S[u] = 1;
        for (j = 1; j <= n; ++j)
        {
            if (S[j] == 0 && edge[u][j] != MAXN)
            {
                int tmp = edge[u][j] + dist[u];
                if (tmp < dist[j])
                {
                    dist[j] = tmp;
                }
            }
        }
    }
    double Max1 = MINN*1.0, Max2 = MINN * 1.0;
    int index, index1, index2;
    for (i = 2; i <= n; ++i)
        if (Max1 < dist[i]) {Max1 = 1.0 * dist[i]; index = i;}
    for (i = 1; i <= n; ++i)
    {
        for (j = i+1; j <= n; ++j)
        {
            if (edge[i][j] != MAXN)
            {
                double tmp = (dist[i] + dist[j] + edge[i][j]) / 2.0;
                if (tmp > Max2)
                {
                    Max2 = tmp; index1 = i; index2 = j;
                }
            }
        }
    }
    if (n == 1) {Max1 = 0.0; index = 1;}
    if (Max2 > Max1)
    {
        printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n", Max2, index1, index2);
    }
    else
    {
        printf("The last domino falls after %.1f seconds, at key domino %d.\n", Max1, index);
    }
}
int main()
{
    int i, j, u, w, v, t = 1;
    while (~scanf("%d%d", &n, &m) && (n||m))
    {
        printf("System #%d\n", t); t++;
        memset(edge, 0, sizeof(edge));
        for (i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            edge[v][u] = edge[u][v] = w;
        }
        for (i = 1; i <= n; ++i)
        {
            for (j = i; j <= n; ++j)
            {
                if (j == i) edge[i][j] = 0;
                else if (edge[i][j] == 0) edge[i][j] = edge[j][i] = MAXN;
            }
        }
        dijkstra(1);
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 220;

const double INF = 1e60;

int n;
double G[maxn][maxn], d[maxn];

struct Pos {
    int x, y;
}num[maxn];

double calc(int i, int j) {
    return (sqrt(pow((double)num[i].x-num[j].x, 2)+pow((double)num[i].y-num[j].y, 2)));
}

double dijkstra() {
    bool vis[maxn];

    memset(vis, false, sizeof(vis));

    for(int i=0; i<n; i++) {
        d[i] = G[0][i];
    }

    d[0] = 0;
    vis[0] = true;

    for(int i=0; i<n-1; i++) {
        double m = INF; int x;
        for(int y=0; y<n; y++) if(!vis[y] && m >= d[y]) m = d[x=y];
        vis[x] = true;
        for(int y=0; y<n; y++){
            if(!vis[y]) {
                double maxx = max(d[x], G[x][y]);
                if(d[y] > maxx) d[y] = maxx;
            }
        }
    }

    return d[1];
}

int main() {
    int cnt = 0;
    while(scanf("%d", &n) == 1) {
        if(n == 0) break;

        for(int i=0; i<n; i++) scanf("%d%d", &num[i].x, &num[i].y);

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                G[i][j] = G[j][i] = calc(i, j);
            }
            G[i][i] = 0;
        }

        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++cnt, dijkstra());
    }

    return 0;
}

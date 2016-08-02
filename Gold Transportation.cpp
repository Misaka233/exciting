/*并查集 按边长从小到大排序 如果满足每个连通分量金矿的和小于等于存储的容量 那么就break输出*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 210;
int f[maxn], ra[maxn], rb[maxn];

struct edge
{
	int u, v, w;
	edge(){}
	edge(int u, int v, int w): u(u), v(v), w(w){}
}e[40000];
int a[maxn];
int b[maxn];

int find(int x)
{
	if(x != f[x])
		return f[x] = find(f[x]);
	return f[x];
}

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

int main()
{
	int n;
	while(scanf("%d", &n) && n)
	{

		int sum1 = 0, sum2 = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum1 += a[i];
		}
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
			sum2 += b[i];
		}
		for(int i = 0; i <= n; i++)
		f[i] = i, ra[i] = a[i], rb[i] = b[i];
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
		}
		sort(e, e+m, cmp);
		int ans = 1<<30;
		for(int i = 0; i < m; i++)
		{
			int u = e[i].u;
			int v = e[i].v;
			int x = find(u);
			int y = find(v);
			if(x != y)
			{
				f[x] = y;
				ra[y] += ra[x];
				rb[y] += rb[x];
			}
			int j;
			for(j = 1; j <= n; j++)
			{
				int x = find(j);
				if(ra[x] > rb[x])
					break;
			}
			if(j > n)
			{
				ans = e[i].w;
				break;
			}
		}
		if(ans == 1<<30)
		{
			puts("No Solution");
			continue;
		}
		printf("%d\n", ans);
	}
	return 0;
}

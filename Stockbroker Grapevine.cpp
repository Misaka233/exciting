#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 105;
const int MAX = 0xfffffff;

int n;
int edge[N][N];

void floyd()
{
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (edge[i][j] > edge[i][k] + edge[k][j])
				{
					edge[i][j] = edge[i][k] + edge[k][j];
				}
			}
		}
	}
}

int main()
{
	int m, mate, dis;
	while (scanf("%d", &n) != EOF && n)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i != j) edge[i][j] = MAX;
				else edge[i][j] = 0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &m);
			for (int j = 0; j < m; ++j)
			{
				scanf("%d%d", &mate, &dis);
				--mate;
				edge[i][mate] = dis;
			}
		}
		floyd();
		int ans, tmin, pnt;
		bool disjoint;
		ans = MAX;
		for (int i = 0; i < n; ++i)
		{
			tmin = -1;
			disjoint = false;
			for (int j = 0; j < n && !disjoint; ++j)
			{
				if (i != j && edge[i][j] == MAX) disjoint = true;
				if (i != j && edge[i][j] > tmin) tmin = edge[i][j];
			}
			if (!disjoint && tmin < ans)
			{
				disjoint = false;
				ans = tmin;
				pnt = i;
			}
		}
		if (ans == MAX) printf("disjoint\n");
		else printf("%d %d\n", pnt + 1, ans);
	}
	return 0;
}

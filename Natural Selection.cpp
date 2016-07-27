#include<bits/stdc++.h>
using namespace std;
int N, M;
int grid[105][105];
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &grid[i][j]);
		}
	}
	int ans1, ans2;
	int s1, s2, s3, s4, mins, tmps;
	mins = 1<<30;
	for (int i = 0; i < M; ++i)
	{
		for (int j = i + 1; j < M; ++j)
		{
			s1 = 0; s2 = 0; s3 = 0; s4 = 0;
			for (int k = 0; k < N; ++k)
			{
				if (grid[k][i] == 0)
				{
					if (grid[k][j] == 0)
						++s1;
					else
						++s2;
				}
				else
				{
					if (grid[k][j] == 0)
						++s3;
					else
						++s4;
				}
			}
			tmps = max(s1, s2); tmps = max(tmps, s3); tmps = max(tmps, s4);
			if (tmps < mins)
			{
				ans1 = i + 1; ans2 = j + 1;
				mins = tmps;
			}
		}
	}
	printf("%d\n%d %d\n", mins, ans1, ans2);
	return 0;
}

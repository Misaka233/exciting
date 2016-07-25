#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define maxn 200005
int main()
{

	int N, M;
	cin >> N >> M;
	int cnt = 0;
	bool flag = true;
	vector<string> a(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (a[i][j] == '#')
				continue;
			cnt = 0;
			if (i != 0 && a[i - 1][j] != '#')
				++cnt;
			if (i != N - 1 && a[i + 1][j] != '#')
				++cnt;
			if (j != 0 && a[i][j - 1] != '#')
				++cnt;
			if (j != M - 1 && a[i][j + 1] != '#')
				++cnt;
			if (cnt >= 3)
			{
				cout << "YES" << endl;
				return 0;
			}
			if (cnt == 1)
				flag = false;
		}
	}
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}

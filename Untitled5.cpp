#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct misaka
{
	int l, w;
}data[5010];
bool use[5010];
bool operator < (const misaka a, const misaka b)
{
	if(a.l == b.l)
		return a.w < b.w;
	return a.l < b.l;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(use, 0, sizeof(use));
		int n, count = 0;
		misaka last;
		cin>>n;
		for(int i = 0; i < n; ++i)
		{
			cin>>data[i].l>>data[i].w;
		}
		sort(data, data + n); //木棒排序
		for(int i = 0; i < n; ++i) //对第i个木棒 求递增子序列
		{
			last.w = data[i].w; //记录新序列的开始
			if(!use[i])
			{
				for(int j = i + 1; j < n; j++)
				{
					if(last.w <= data[j].w && !use[j])
					{
						use[j] = 1; //用到则标记为1
						last.w = data[j].w; //队尾元素
					}
				}
				count++; //子序列结束后，时间加1.计算第i + 1个木棒
			}
		}
		cout<<count<<endl;
	}
	return 0;
}

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
		sort(data, data + n); //ľ������
		for(int i = 0; i < n; ++i) //�Ե�i��ľ�� �����������
		{
			last.w = data[i].w; //��¼�����еĿ�ʼ
			if(!use[i])
			{
				for(int j = i + 1; j < n; j++)
				{
					if(last.w <= data[j].w && !use[j])
					{
						use[j] = 1; //�õ�����Ϊ1
						last.w = data[j].w; //��βԪ��
					}
				}
				count++; //�����н�����ʱ���1.�����i + 1��ľ��
			}
		}
		cout<<count<<endl;
	}
	return 0;
}

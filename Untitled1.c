#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int maxn=50010;
int list[maxn];
int maxm,minn;

struct node
{
	int l;
	int r;
	int max;
	int min;
}a[maxn*4];

int Max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}

int Min(int x,int y)
{
	if(x<y)
		return x;
	else
		return y;
}

void build(int l,int r,int root)
{
	a[root].l=l;
	a[root].r=r;
	if(l==r)
	{
		a[root].max=list[l];
		a[root].min=list[l];
		return;
	}
	int mid=(l+r)/2;//注意mid的值会改变，故直接在函数中定义
	build(l,mid,root*2);
	build(mid+1,r,root*2+1);
	a[root].max=Max(a[root*2].max,a[root*2+1].max);
	a[root].min=Min(a[root*2].min,a[root*2+1].min);
}

void find(int l,int r,int root)
{
	if(a[root].l==l&&a[root].r==r)
	{
		maxm=Max(maxm,a[root].max);
		minn=Min(minn,a[root].min);
		return;
	}
	int mid=(a[root].l+a[root].r)/2;
	if(mid<=l)
		find(l,r,root*2+1);
	else if(mid>=r)
		find(l,r,root*2);
	else
	{
		find(l,mid,root*2);
		find(mid+1,r,root*2+1);
	}
}

int main()
{
	int N,Q;
	int i;
	int start,end;
	scanf("%d%d",&N,&Q);
	memset(list,0,sizeof(list));
	for(i=1;i<=N;i++)
	{
		cin>>list[i];
	}
	build(1,N,1);
	while(Q--)
	{
		maxm=0;
		minn=1e9+1;
		cin>>start>>end;
		find(start,end,1);
		cout<<(maxm-minn)<<endl;
	}
	return 0;
}

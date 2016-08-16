#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long lld;
const int MOD=10003;
vector<lld> v[MOD+10];
int num,n,i,N[15];

void insert(lld x)
{
	int key=x%MOD;
	for(i=0;i<v[key].size();i++)
		if(v[key][i]==x)	return;
	v[key].push_back(x);
	num++;
}

void dfs(int a,int b,int c,int id) //三个木棍的枚举，参数分别是a,b,c及当前已用去得数量
{
	if(id==n)
	{
		if(a<=b&&b<=c&&a+b>c)
			insert(a*1000000000000LL+b*1000000+c);
		return ;
	}
	dfs(a+N[id],b,c,id+1);
	dfs(a,b+N[id],c,id+1);
	dfs(a,b,c+N[id],id+1);
}

int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;i++)	scanf("%d",N+i);
		for(i=0;i<MOD;i++)	v[i].clear();
		
		num=0;dfs(0,0,0,0);
		
		printf("%d\n",num);
	}
	return 0;
}



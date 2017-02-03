#include <iostream>
#include <algorithm>
using namespace std;

int t,n;
int a[20];
int save[20]; 
int index;
int used[20];
int sign;

int cmp(const int &a, const int& b)
{
	return a > b;
}

void dfs(int k, int sum)
{
	if(sum > t)
	{
		return ;
	}
	if(sum == t)
	{
		sign = 1;
		for(int i=0; i<index-1; i++)
		{
			cout<<save[i]<<"+";
		}
		cout<<save[index-1]<<endl;
		return ;
	}
	int last = -1;
	for(int i=k+1; i<=n; i++)
	{
		if(a[i] != last)           //��ǰ�������ܸ���һ��������������ֵһ������Ȼ������ظ�
		{
			save[index++] = a[i];
			last = a[i];            //last���浱ǰ���������
			dfs(i,sum+a[i]);
			index--;
		}
	}
}

int main()
{
	int i;
	while(cin>>t>>n,t+n)
	{
		index = 0;
		sign = 0;
		for(i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1,cmp); //��������
		printf("Sums of %d:\n",t);
		dfs(0,0);
		if(!sign)
		{
			cout<<"NONE"<<endl;
		}
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int>>Q;
int main()
{
	int n,k,a;
	char op;
	while(~scanf("%d%d",&n,&k))
	{
		while(!Q.empty()) Q.pop();
		for(int i=1;i<=n;i++)
		{
			cin>>op;
			if(op=='I')
			{
				cin>>a;
				Q.push(a);
				if(Q.size()>k)
					Q.pop();
			}
			else
		 		cout<<Q.top()<<endl;
		}
		
	}
	return 0;
}


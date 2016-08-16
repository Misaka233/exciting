#include<iostream>
#include<cstdio>
using namespace std;
int main() 
{
	int a,t,cas=0;
	cin>>t;
	 
	while(t--)
	{
		
		cas++;
		int n;
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			sum+=a;
		}
		printf("Case #%d: %d\n",cas,sum/2);
	}
}

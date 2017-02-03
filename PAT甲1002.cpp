#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

double s[1005];
int main()
{
	int i,k,a,cnt=0;
	double an;
	cin>>k;
	for(i=0;i<k;i++)
	{
		cin>>a>>an;
		if(s[a]==0) cnt++;
		s[a]+=an;
	}
	cin>>k;
	for(i=0;i<k;i++)
	{
		cin>>a>>an;
		if(s[a]==0) cnt++;
		s[a]+=an;
	}
	cout<<cnt<<" ";
	for(i=1005;i>=0;i--)
	{
		if(cnt==1) break;
		if(s[i]!=0)
		{  
			cnt--;
			cout<<i<<" "<<s[i]<<" ";
		}
	}
	while(i>=0)
	{
		if(s[i]!=0)
		{  
			cout<<i<<" "<<s[i];
		}
		i--;
	}
	return 0;
}

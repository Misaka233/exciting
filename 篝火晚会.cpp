#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
#include<map>
using namespace std;
int n,ans;
int c[50005];
int a[50005],b[50005];
bool vis[50005];
int t1[50005],t2[50005];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
    {
		    cin>>a[i];
		    cin>>b[i];
    }
	c[1]=1;c[2]=a[1];
	vis[c[1]]=vis[c[2]]=1;
	for(int i=2;i<n;i++)
	{
		if(c[i-1]==a[c[i]])c[i+1]=b[c[i]];
		else if(c[i-1]==b[c[i]])c[i+1]=a[c[i]];
		else {puts("-1");return 0;}
		vis[c[i+1]]=1;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){puts("-1");return 0;}
	for(int i=1;i<=n;i++)
	{
		int t=(c[i]-i+n)%n;
		t1[t]++;
		ans=max(ans,t1[t]);
		t=(c[n-i+1]-i+n)%n;
		t2[t]++;
		ans=max(ans,t2[t]);
	}
	printf("%d",n-ans);
	return 0;
}

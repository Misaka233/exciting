#include<bits/stdc++.h>
using namespace std;
const int MAX=30;
int a[MAX],t,k,ans,n;
int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		if (a[i]&1) t=i,k++;
	}
	if (k>1){cout<<0<<'\n';for (int i=0;i<n;i++) for(int j=0;j<a[i];j++) cout<<(char)('a'+i); return 0;}
	for (int i=0;i<n;i++) ans=__gcd(ans,a[i]);
	cout<<ans<<'\n';
	if (ans%2==0) ans/=2;
	for (int i=0;i<ans;i++)
	{
		for (int i=0;i<n;i++) if (a[i]%2==0) for (int j=0;j<a[i]/2/ans;j++) cout<<(char)('a'+i);
		if (k) for (int i=0;i<a[t]/ans;i++) cout<<(char)('a'+t);
		for (int i=n-1;i>=0;i--)if(a[i]%2==0)for (int j=0;j<a[i]/2/ans;j++) cout<<(char)('a'+i);
	}
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;

struct data{
	int x,idx;
}a[maxn];
bool cmp(data k1,data k2){
	return k1.x<k2.x;
}
int q[maxn],b[maxn];
ll sum[maxn];
ll m,A,cf,cm,ans=-1;
ll xp,xl;
int n;

int main(){
	scanf("%d%I64d%I64d%I64d%I64d",&n,&A,&cf,&cm,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].x),a[i].idx=i,q[i]=a[i].x;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i].x,b[i]=a[i].x;

	for(int p=n;p>=0;p--){
		ll left=A*(n-p)-(sum[n]-sum[p]);
		left=m-left;
		if(left<0) break;

		ll l=0,r=A;
		while(l<r){
			ll mid=(l+r+1)>>1;
			int x=lower_bound(b+1,b+p+1,mid)-b-1;
			if(mid*x-sum[x]<=left) l=mid;
			else r=mid-1;
		}

		if(cf*(n-p)+cm*l>ans){
			ans=cf*(n-p)+cm*l;
			xp=p,xl=l;
		}
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=n;i++)
		if(q[i]<xl) q[i]=xl;
	for(int i=n;i>xp;i--) q[a[i].idx]=A;
	for(int i=1;i<=n;i++)
		printf("%d ",q[i]);
	printf("\n");
	return 0;
}

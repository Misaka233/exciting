#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf (1ull<<63)-1
#define N 50005
#define maxn 100005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-9
#define zero(a) fabs(a)<eps
#define LL long long
#define ULL unsigned long long
#define lson (step<<1)
#define rson (step<<1|1)
#define MOD 1000000007
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,a[N],q,sum[N]={0};
struct Node{
	int left,right,lx,rx,mx;
	int all(){
		return sum[right]-sum[left-1];
	}
}L[N*4];
void Push_Up(int step){
	L[step].lx=max(L[lson].lx,L[lson].all()+L[rson].lx);
	L[step].rx=max(L[rson].rx,L[rson].all()+L[lson].rx);
	L[step].mx=max(max(L[lson].mx,L[rson].mx),L[lson].rx+L[rson].lx);
}
void Bulid(int step,int l,int r){
	L[step].left=l;L[step].right=r;
	if(l==r){
		L[step].lx=L[step].rx=L[step].mx=a[l];
		return ;
	}
	int m=(l+r)/2;
	Bulid(lson,l,m);
	Bulid(rson,m+1,r);
	Push_Up(step);
}
int Q_L(int step,int l,int r){
	if(L[step].left==l&&L[step].right==r)
		return L[step].lx;
	int m=(L[step].left+L[step].right)/2;
	if(r<=m) return Q_L(lson,l,r);
	else if(l>m) return Q_L(rson,l,r);
	else return max(Q_L(lson,l,m),max(sum[m]-sum[l-1],sum[m]-sum[l-1]+Q_L(rson,m+1,r)));
}
int Q_R(int step,int l,int r){
	if(L[step].left==l&&L[step].right==r)
		return L[step].rx;
	int m=(L[step].left+L[step].right)/2;
	if(r<=m) return Q_R(lson,l,r);
	else if(l>m) return Q_R(rson,l,r);
	else return max(Q_R(rson,m+1,r),max(sum[r]-sum[m],sum[r]-sum[m]+Q_R(lson,l,m)));
}
int Query(int step,int l,int r){
	if(L[step].left==l&&L[step].right==r)
		return L[step].mx;
	int m=(L[step].left+L[step].right)/2;
	if(r<=m) return Query(lson,l,r);
	else if(l>m) return Query(rson,l,r);
	else return max(max(Query(lson,l,m),Query(rson,m+1,r)),Q_R(lson,l,m)+Q_L(rson,m+1,r));
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++) {scanf("%d",&a[i]);sum[i]=sum[i-1]+a[i];}
		Bulid(1,1,n);
		scanf("%d",&q);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",Query(1,l,r));
		}
	}
	return 0;
}


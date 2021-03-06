#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5,M = 300,S = sqrt(N);
int ret[N],a[N],temp[N],cc[N],fr[N];
vector<int> bb;
struct query
{
	 int index,l,r;
}q[N];
bool cmp(query x,query y)
{
		if(x.l/S!= y.l/S)
			return x.l<y.l;
		else
			return x.r>y.r;
}
void update(int x,int add)
{
	fr[cc[x]]--;
	cc[x]+=add;
	fr[cc[x]]++;
}
int sol()
{
	int um=0,i,j,next,R=0;
	priority_queue<int,vector<int>,greater<int> > q;
	for(i=0;i<bb.size();++i)
		if(cc[bb[i]]>=M)q.push(cc[bb[i]]);
	for(i=1;i<M;++i)
		temp[i]= fr[i];
	for(i=1;i<M;++i)
    {
		if(temp[i]==0)continue;
		if(um!=0)
		{
			next= um+ i;
			--temp[i];
			R+= next;
			if(next>=M)q.push(next);
			else
				temp[next]++;
			um=0;
		}
		if(temp[i]&1)
		{
			um = i;
			--temp[i];
		}
		R+= i*temp[i];
		next= i*2;
		if(next>=M)
			for(j=0;j<temp[i]/2;++j)q.push(next);
		else
			temp[next]+=temp[i]/2;
	}
	if(um!=0)q.push(um);
	while(q.size()>1)
    {
		i= q.top();q.pop();
		j= q.top();q.pop();
		R+= i+j;
		q.push(i+j);
	}
	return R;
}
int main()
{
	int n,i,m,l=1,r=0,u,b,ind;
	cin>>n;
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		temp[a[i]]++;
		if(temp[a[i]]==M)
			bb.push_back(a[i]);
	}
	cin>>m;
	for(i=0;i<m;++i)
		scanf("%d%d",&q[i].l,&q[i].r),q[i].index=i;
	sort(q,q+m,cmp);
	for(i=0;i<m;++i)
    {
		u= q[i].l,b= q[i].r,ind = q[i].index;
		while(r<b)++r,update(a[r],1);
		while(l<u)update(a[l],-1),++l;
		while(b<r)update(a[r],-1),--r;
		while(u<l)--l,update(a[l],1);
		ret[ind]= sol();
	}
	for(i=0;i<m;++i)
		printf("%d\n",ret[i]);
}

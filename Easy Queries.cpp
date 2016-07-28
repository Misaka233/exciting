#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10, M = 2e2+11, inf = 2e9, mod = 1e9+7;
int n, q;
long long ar[N],num[N];
vector< long long > da[4 * N];
void merges(vector<long long> &a, vector<long long> &b, vector<long long> &c)
{
    int lenb = 0 , lenc = 0;
    while(lenb < b.size() && lenc < c.size()) {
        if(b[lenb] == c[lenc]) {
            a.push_back(b[lenb]);
            lenb++, lenc++;
        }else {
        if(b[lenb] < c[lenc]) {
            a.push_back(b[lenb++]);
        } else a.push_back(c[lenc++]);

        }
    }
    while(lenb < b.size()) {
        a.push_back(b[lenb++]);
    }
    while(lenc < c.size()) {
        a.push_back(c[lenc++]);
    }
}

void build(int k,int l,int r) {
    if(r == l) {
        da[k].push_back(ar[l]);
        return ;
    }
    build(k<<1,l,(l+r)/2);build(k<<1|1,(r+l)/2+1,r);
    merges(da[k],da[k<<1],da[k<<1|1]);
}
long long query(int i,int j,long long x,int k,int l,int r) {
    if(i==l&&j==r) return upper_bound(da[k].begin(),da[k].end(),x) - da[k].begin();
    else {
        int mid  = (l+r)>>1;
        if(j<=mid) return query(i,j,x,k<<1,l,mid);
        else if(i>mid) return query(i,j,x,k<<1|1,mid+1,r);
        else return query(i,mid,x,k<<1,l,mid)+query(mid+1,j,x,k<<1|1,mid+1,r);
    }
}

long long solve(int l,int r,int k) {
    int lb = 1, rb = n, ans = 1;
    while(lb<=rb) {
        int mid = (lb+rb)>>1;
        if(query(l,r,num[mid],1,1,n)>=k) rb = mid-1, ans = mid;
        else lb = mid + 1;
    }
    if(query(l,r,num[ans],1,1,n)<k) {
        return -1;
    }
    else return num[ans];
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&ar[i]), num[i] = ar[i];
    sort(num+1,num+n+1);
    build(1,1,n);
    long long pre = 0;
    for(int i=1;i<=q;i++) {
        long long a,b,c,d,k;
        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&k);
        int l = (a*max(pre,0ll)+b) % n + 1;
        int r = (c*max(pre,0ll)+d) % n + 1;
        printf("%d\n",pre = solve(l,r,k));
    }
}

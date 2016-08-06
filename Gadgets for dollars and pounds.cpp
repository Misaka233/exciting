#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,a,n) for(int i =(a); i < (n); i++)
#define fi first
#define se second
#define mp make_pair
const int maxn=200005;
const int INF=0x3fffffff;
int a[maxn],b[maxn];
pair<long long ,int >p1[maxn];
pair<long long ,int>p2[maxn];
int x[1000005],y[1000005];
int t[3][1000005];
int n,m,k1;
long long s,temp1,temp2;
int cj ,ck ;
int f(int day)
{
    cj = 0, ck = 0;
    long long cnt = 0;
    rep(i, 0, k1){
        temp1 =  p1[cj].fi* a[day];
        temp2 =  p2[ck].fi * b[day];
        if(temp1 <= temp2)  {cnt += temp1; cj++;}
        else   {cnt += temp2; ck++;}
        if(cnt > s) return 0;
    }
    return 1;
}
int main (void)
{
    int j = 1, k = 1;
    int aa;
    long long bb;
    a[0] = b[0] = INF;
    cin>>n>>m>>k1>>s;
    rep(i,1,n+1) {
        cin>>a[i];
        if(a[i] >= a[i-1]) a[i] = a[i-1];
        else  x[a[i]] = i;
    }//dollar
    rep(i,1,n+1){
        cin>>b[i];
        if(b[i] >= b[i-1]) b[i] = b[i-1];
        else y[b[i]] = i;
    }//pound

    rep(i,1,m+1) {
        cin>>aa>>bb;
        if(aa == 1){p1[k++] = mp(bb,i);}
        else {p2[j++] = mp(bb,i); }
    }
    p1[0].fi = p2[0].fi = INF;
    sort(p1,p1+k);
    sort(p2,p2+j);

    int l = 1,r = n+1, mid;
    while(l < r){
        mid = (l+r)/2;
        if(f(mid)) r = mid;
        else l = mid+1;
    }
    if(l == n+1) cout<<"-1"<<endl;
    else {
        cout<<l<<endl;
        cj = 0, ck = 0;
        rep(i, 0, k1){//fi ¼ÛÇ® se ºÅÂë
            temp1 = p1[cj].fi * a[l];
            temp2 = p2[ck].fi * b[l];
            if(temp1 <= temp2)   cout<<p1[cj++].se<<' '<<x[a[l]]<<endl;
            else   cout<<p2[ck++].se<<' '<<y[b[l]]<<endl;
        }
    }
    return 0;
}

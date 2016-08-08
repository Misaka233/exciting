#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
#define fi first
#define se second
#define mp make_pair
const int maxn = 200005;
int a[maxn],b[maxn],t[maxn],c[maxn];
int n,m,k,s;
int am[maxn],bm[maxn];
int ida[maxn],idb[maxn];
const int inf = 0x3f3f3f3f;

pii pli[maxn];
int id[maxn];

ll f(int x){
    ll ret = 0;
    for (int i=1;i<=m;i++){
        if (t[i] == 1){
            pli[i].fi = (ll)c[i] * (ll)am[x];

        }
        else{
            pli[i].fi = (ll)c[i] * (ll)bm[x];
        }
        pli[i].se = i;
    }
    sort(pli+1,pli+m+1);
    for (int i=1;i<=k;i++){
        ret += pli[i].fi;
    } 

    return ret;
}


int main(){
    cin>>n>>m>>k>>s;
    am[0] = bm[0] = inf;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if (a[i] < am[i-1]){
            am[i] = a[i];
            ida[i] = i;
        }
        else{
            am[i] = am[i-1];
            ida[i] = ida[i-1];
        }
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        if (b[i] < bm[i-1]){
            bm[i] = b[i];
            idb[i] = i;
        }
        else{
            bm[i] = bm[i-1];
            idb[i] = idb[i-1];
        }
    }
    for (int i=1;i<=m;i++){
        scanf("%d%d",&t[i],&c[i]);
    }

    ll low,high,mid;
    low = 1,high = n;
    ll d = -1;
    while(low <= high){
        mid = (low + high) / (ll)2;
        if (f(mid) <= s){
            high = mid - 1;
            d = mid;
            for (int i=1;i<=k;i++){
                id[i] = pli[i].se;
            }
        }
        else{
            low = mid + 1;
        }
    }
    cout << d <<"\n";
    if (d == (ll)-1)
        return 0;
    int x = (int)d;
    for (int i=1;i<=k;i++){
        printf("%d %d\n",id[i],t[id[i]]==1?ida[x]:idb[x]);
    }

    return 0;
}

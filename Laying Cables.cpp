#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+20, M = 1e6+10, mod = 1e9+7, inf = 2e9;
typedef long long ll;

int n,ans[N];
struct ss{long long x,p;int id;}a[N],lefts[N],rights[N];
vector<ss> G;
bool cmp(ss s1,ss s2) {return s1.x<s2.x;}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d%I64d",&a[i].x,&a[i].p),a[i].id = i;
    sort(a+1,a+n+1,cmp);
    a[0].x=-inf, a[0].p = inf; a[0].id = -1;
    G.push_back(a[0]);
    for(int i=1;i<=n;i++) {
        while(G.back().p<=a[i].p) G.pop_back();
        lefts[i]=G.back();
        G.push_back(a[i]);
    }
    G.clear();
    a[n+1] = (ss) {inf,inf,-1};
    G.push_back(a[n+1]);
    for(int i=n;i>=1;i--) {
        while(G.back().p<=a[i].p) G.pop_back();
        rights[i]=G.back();
        G.push_back(a[i]);
    }

    for(int i=1;i<=n;i++) {
        if(abs(lefts[i].x-a[i].x)==abs(rights[i].x-a[i].x)) {
            if(lefts[i].p>rights[i].p) ans[a[i].id] = lefts[i].id;
            else ans[a[i].id] = rights[i].id;
        }
        else if(abs(lefts[i].x-a[i].x)<abs(rights[i].x-a[i].x)) {
           ans[a[i].id] = lefts[i].id;
        }
        else ans[a[i].id] = rights[i].id;
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    printf("\n");
}


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long int64;
const int MAXN = 1000000;
int n,m,k;
int64 c[MAXN];

struct node{
    int u,v;
    friend bool operator<(const node&a,const node&b){
        if(a.u!=b.u) return a.u<b.u;
        return a.v<b.v;
    }
}arr[MAXN];

inline int lowbit(int x){return x&(-x);}
int64 sum(int x){
    int64 ret=0;
    while(x>0){
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x){
    while(x<=m){
        ++c[x];
        x += lowbit(x);
    }
}

int main(){
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        printf("Test case %d: ",cas++);
        memset(c, 0, sizeof(c));
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<k; ++i) 
            scanf("%d%d",&arr[i].u,&arr[i].v) ;
        sort(arr,arr+k);
        int64 ans=0;
        for(int i=0; i<k; ++i){
            ans += sum(m)-sum(arr[i].v) ;
            add(arr[i].v);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

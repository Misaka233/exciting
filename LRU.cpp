#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;
int cy[maxn];
int fa[maxn];
int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
int cnt = 0;
int tmp = 0;
int Union(int x ,int y){
    int a = Find(x);
    int b = Find(y);
    if(a == b){
        cy[x] = 0;
        if(x == y ) tmp = x;
        cnt ++;
    }
    else cy[x] = y;
    fa[b] = a;
}
int main(){
    int n,t;
    cin >>n;
    for(int i = 0 ; i <= n ; i ++){
        fa[i] = i;
    }
    int f = 0;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&t);
        Union(i+1,t);
        if(t == i+1)
            f = 1;
    }

    printf("%d\n",cnt - f);
    for(int i = 1 ; i <= n ; i ++){
        if(cy[i])
            printf("%d ",cy[i]);
        else if(tmp)
            printf("%d ",tmp);
        else{
            tmp = i;
            printf("%d ",tmp);
        }
    }
}

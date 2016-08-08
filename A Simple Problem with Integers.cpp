#include<cstdio>
using namespace std;
#define maxn 100000+10
typedef long long LL;
struct node{
    int l,r,m;
    LL sum,mark;
}T[maxn<<2];
int a[maxn];
void build(int id,int l,int r){
     T[id].l=l;   T[id].r=r;  T[id].m=(l+r)>>1;  T[id].mark=0;
     if(l==r)   { T[id].sum=a[l]; return;  }
     int m=(l+r)>>1;
     build(id<<1,l,m);  build((id<<1)+1,m+1,r);
     T[id].sum=(T[id<<1].sum+T[(id<<1)+1].sum);
}
void update(int id,int l,int r,int val){
     if(T[id].l==l&&T[id].r==r){
        T[id].mark+=val; return ;
     }
     T[id].sum+=(LL)val*(r-l+1);
     if(T[id].m>=r)
          update(id<<1,l,r,val);
     else if(T[id].m<l)
          update((id<<1)+1,l,r,val);
     else{
          update(id<<1,l,T[id].m,val);
          update((id<<1)+1,T[id].m+1,r,val);
     }
}
LL query(int id,int l,int r){
    if(T[id].l==l&&T[id].r==r)  return T[id].sum+T[id].mark*(LL)(r-l+1);
    if(T[id].mark!=0) {
        T[id<<1].mark+=T[id].mark;
        T[(id<<1)+1].mark+=T[id].mark;
        T[id].sum+=(LL)(T[id].r-T[id].l+1)*T[id].mark;  T[id].mark=0;
    }

    if(T[id].m>=r){
          return query(id<<1,l,r);
    }
    else if(T[id].m<l){
          return query((id<<1)+1,l,r);
    }
    else{
          return query(id<<1,l,T[id].m)+query((id<<1)+1,T[id].m+1,r);
    }
}
int main(){
    int n,Q;  char str[8];   int b,c,d;
    while(scanf("%d%d",&n,&Q)!=EOF){
          for(int i=1;i<=n;i++){
             scanf("%d",&a[i]);
          }
          build(1,1,n);
          for(int i=0;i<Q;i++){
               scanf("%s",str);
               if(str[0]=='Q'){
                    scanf("%d%d",&b,&c);
                    printf("%lld\n",query(1,b,c));
               }
               else if(str[0]=='C'){
                    scanf("%d%d%d",&b,&c,&d);
                    update(1,b,c,d);
               }
          }
    }
    return 0;
}


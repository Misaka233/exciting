#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int maxn = 110;
const int maxw = 4;
typedef unsigned int Mat[maxn][maxw];

const int max_pri = 500;
bool flag[max_pri+1];
int prime[max_pri / 4];
Mat m;

int table_prime(){
    int cnt = 0 , m = sqrt(max_pri+0.5);
    for(int i=2;i<=m;i++) if(!flag[i]) {
        for(int j=i*i ; j<=max_pri ;j+=i) flag[j] = true;
    }
    for(int i=2;i<=max_pri;i++) if(!flag[i])
        prime[cnt++] = i;
    return cnt;
}
int Rank(Mat&m ,int R,int C){ //Çó¾ØÕóµÄÖÈ
    int r=0,c=0,k,i,j,u,v;
    while(r<R && c<C){
        k = r , u=c/32 , v=c%32;
        for(i=r+1;i<R;i++) {
            if(m[i][u]&(1<<v)) {k=i; break; }
        }
        if(m[k][u]&(1<<v)){
            if(k!=r) for(i=0;i<maxw;i++) swap(m[k][i] ,m[r][i]);
            for(i=r+1;i<R;i++) if(m[i][u]&(1<<v)) {
                for(j=0;j<maxw;j++) m[i][j] ^=m[r][j];
            }
            r++;
        }
        c++;
    }
    return r;
}

int main()
{
    int M = table_prime();
    int TT;
    scanf("%d",&TT);
    while(TT--){
        int n , maxp = 0 , u,v;
        LL x;
        scanf("%d",&n);
        memset(m,0,sizeof(m));
        for(int i=0;i<n;i++){
            u = i/32 , v = i%32;
            scanf("%lld" , &x);
            for(int k = 0;k<M;k++){
                while(x%prime[k] == 0) {
                    x /= prime[k];
                    m[k][u] ^= (1<<v);
                    maxp = max(maxp , k+1);
                }
            }
        }

        int free = n - Rank(m,maxp,n);
        LL ans = (1LL << free) - 1;
        printf("%lld\n",ans);
    }
    return 0;
}


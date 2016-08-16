#include<cstdio>  
#include<cstring>  
  
const int N = 1e4 + 5;  
int cnt[N];  
  
int main() {  
    int T, n, w, cas = 0;  
    scanf("%d",&T);  
    while(T--) {  
        scanf("%d", &n);  
        int S_cnt = 0; //有几个不同的s  
        int Max_cnt = 0; //出现次数最多的数出现的次数  
        int Max_s = 0, Min_s = 10005; //s的最大最小值  
        memset(cnt, 0, sizeof(cnt));  
        for(int i = 0; i < n; i++) {  
            scanf("%d",&w);  
            int s = 10000 - (100 - w) * (100 - w);  
            if(s > Max_s) Max_s = s;  
            if(s < Min_s) Min_s = s;  
            if(!cnt[s]) S_cnt++;  
            cnt[s]++;  
            if(cnt[s] > Max_cnt) Max_cnt = cnt[s];  
        }  
        printf("Case #%d:\n", ++cas);  
        if(Max_cnt * S_cnt == n && S_cnt > 1)  
            printf("Bad Mushroom\n");  
        else {  
            int p = 0;  
            for(int i = Min_s; i <= Max_s; i++) {  
                if(cnt[i] == Max_cnt) {  
                    if(p) printf(" ");  
                    printf("%d", i);  
                    p = 1;  
                }  
            }  
            printf("\n");  
        }  
    }  
    return 0;  
}  

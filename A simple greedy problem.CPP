#include<bits/stdc++.h>
using namespace std;
const int INF=1<<31;
const int maxn=1111;
typedef long long ll;

int kase, n, a[maxn], c[maxn], dp[maxn][maxn];
int main(){
    scanf("%d",&kase);
    for(int ks=1;ks<=kase;ks++)
    {
        cin>>n;
        printf("Case #%d: ", ks);
        int ma=0;
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            ma=max(ma, a[i]);
        }
        sort(a,a+n);
        memset(c,0,sizeof(c));

        for(int i=0; i<n; i++){
            int j=a[i];
            while(c[j] && j>0) j--;//j�غ�û��Ҫɱ�ľ���ǰ��һ���غ�
            if(j>0){
                c[j]=a[i]-j+1;//��j�غϿ���B����j-1����������Ҫa-��j-1����
            }
        }
      for(int i=0;i<n;i++)
         cout<<c[i]<<" ";
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=ma;i++)
            {
            for(int j=0;j<=i;j++){
                if(j>0)    dp[i][j] = max(dp[i-1][j-1], dp[i][j]);
                if(c[i] && j+c[i]-1<i)
                    dp[i][j] = max(dp[i][j], dp[i-1][j+c[i]-1]+1);
            }
        }
        int ans=0;
        for(int j=0;j<=ma;j++)    ans = max(dp[ma][j], ans);
        printf("%d\n",ans);
    }
    return 0;
}

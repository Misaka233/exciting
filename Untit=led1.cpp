#include<cstdio>
#include<cstdlib>
#include<math.h>
#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<algorithm>
#include<queue>
#include<vector>
#include<time.h>
#define PI 3.1415926535897932626
using namespace std;
int gcd(int a, int b) {return a % b == 0 ? b : gcd(b, a % b);}
const int INF=1<<30;
typedef long long ll;
const double eps = 1e-6;
const int row=3000;
const int cow=100;
const int MAXN=500000;

int n,m;
long long dp[400][2];
ll ke[400],va[400];

void init(){
    int i,j;
    memset(dp,0,sizeof(dp));
}

int main()
{
    int t,ct=0,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%I64d",&ke[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%I64d",&va[i]);
        }
        init();//0是与前一个数一起出去了，1是没有出去
        dp[1][0]=dp[1][1]=0;
        for(i=2;i<=n;i++){
            if(gcd(ke[i],ke[i-1])!=1)
                dp[i][0]=dp[i-1][1]+va[i]+va[i-1];
            else dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
        }
        cout<<max(dp[n][0],dp[n][1])<<endl;
    }
}

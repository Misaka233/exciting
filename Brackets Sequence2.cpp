/*dp[i][j]表示区间i,j内需要最少补充多少个括号，path[i][j]记录划分的位置*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=150;
const int inf=1<<30;
int len;
int dp[maxn][maxn],path[maxn][maxn];
char s[maxn];
void print(int first,int end)
{
    if(first>end) return ;
    else if(first==end)
    {
        if(s[first]=='('||s[end]==')') printf("()");
        else printf("[]");
    }
    else if(path[first][end]==-1)
    {
        printf("%c",s[first]);
        print(first+1,end-1);
        printf("%c",s[end]);
    }
    else
    {
        print(first,path[first][end]);
        print(path[first][end]+1,end);
    }
}
int main()
{
    scanf("%s",s+1);
    len=strlen(s+1);
    for(int i=1;i<=len;i++) dp[i][i]=1;
    for(int l=2;l<=len;l++)
    {
        for(int i=1;i<=len-l+1;i++)
        {
            int j=i+l-1;
            if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
            {
                dp[i][j]=dp[i+1][j-1];
                path[i][j]=-1;
            }
            else dp[i][j]=inf;
            for(int k=i;k<=j-1;k++)
            {
                if(dp[i][j]>dp[i][k]+dp[k+1][j])
                {
                    dp[i][j]=dp[i][k]+dp[k+1][j];
                    path[i][j]=k;
                }
            }
        }
    }
    print(1,len);
    cout<<endl;
    return 0;
}


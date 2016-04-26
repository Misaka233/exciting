#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[20][20];//位数是i，最高位是j的个数
int A,B;
int t[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,-1u>>1};
void DP()
{
    for(int j=0;j<=9;j++)
    {
        dp[1][j]=1;
    }
    for(int i=2;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                if(abs(j-k)>=2)
                {
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
    }
    for(int j=1;j<=2;j++)
    {
        for(int k=0;k<=9;k++)
        {
            if(abs(j-k)>=2)
            {
                dp[10][j]+=dp[9][k];
            }
        }
    }
}
int solve(int n)
{
    int i,j,k=1,num,last,ans=0;
    while(t[k]<=n)k++;
    k--;
    for(i=1;i<k;i++)
        for(j=1;j<=9;j++)
            ans+=dp[i][j];
    num=n/t[k];
    for(j=1;j<num;j++)
        ans+=dp[k][j];
    n%=t[k];
    last=num;
    for(i=k-1;i>0;i--)
    {
        num=n/t[i];
        for(j=0;j<num;j++)
            if(abs(last-j)>=2)
                ans+=dp[i][j];
        if(abs(num-last)<2)
            break;
        last=num;
        n%=t[i];
    }
    return ans;
}
int main()
{
    DP();
    scanf("%d%d",&A,&B);
    cout<<solve(B+1)-solve(A)<<endl;
    return 0;
}

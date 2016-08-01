#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=100000000;
int N,E,D;
int dp[21][110][110];
int main()
{
    scanf("%d%d%d",&N,&E,&D);
    for(int i=0;i<=N;i++)
        for(int j=0;j<=D;j++)
            for(int k=0;k<=E;k++)
            {
                dp[i][j][k]=INF;
            }
    dp[1][0][0]=0;
    for(int i=1;i<=N;i++)
        for(int j=0;j<D;j++)
            for(int k=0;k<=E;k++)
                if(dp[i][j][k]!=INF)
                {
                    for(int s=0;s+j<=D&&s*s+k<=E;s++)
                        dp[i][j+s][k+s*s]=min(dp[i][j+s][k+s*s],dp[i][j][k]+1);
                    // ���ﻹ��һ����Ҫ��ת��! ��ǰ��ţ�˳������ֵ���һͷ��ţ���ܡ�
                    // ע�������仯����ͷ��ţ�Ѿ�����jȦ����ʼ��������ҲӦ��Ϊj
                     dp[i+1][j][j]=min(dp[i+1][j][j],dp[i][j][k]);
                }

    int ans=INF;
    for(int i=0;i<=E;i++)
    {
        ans=min(ans,dp[N][D][i]);
    }
    printf("%d\n",ans);
    return 0;
}
/*dp[i][j][k]��ʾǰi-1ͷ��ţ���Ѻľ�����������;�볡��
���ڵ�iͷ��ţ�Ѿ�����jȦ���Ѿ�������k�����������裬��ǰ��
ţ������lȦ/���ӵ��ٶ���һ���ӣ���״̬
dp[i][j+l][k+l*l] = dp[i][j][k] + 1����j+l <= D��j+l*l <= E����
��Ȼ��״̬�Ƿ�ת�ƣ�Ҫ�ж�ת�ƺ�������ʱ���Ƿ��С����Σ�ÿͷ��
ţ�������κ�ʱ����ʱ�˳����ֵ���һͷ��ţ���ܣ�
���Ի���һ���ر���ת�Ʒ�ʽ��dp[i+1][j][j] = dp[i][j][k]��
��Ҫ�����������ı仯����Ϊ��i+1ͷ��ţ�ո����ܣ�֮ǰһ��������jȦ��
�����Ѿ����ĵ�������j
*/

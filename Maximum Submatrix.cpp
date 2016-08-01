/*
参考DP求最大子矩阵
一行一行的处理，在某一行时
先扫一遍这一行
如果该列为0，那么这列0的个数+1，否则直接置0.
然后再扫一遍该行记录某列连续0的个数，如果个数相同的几个，构成一个子矩阵，元素个数就是左右位置相减加一乘
这几列连续0的个数。最后和ans比较，复杂度O(n*m)
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
int mat[maxn][maxn];
int h[maxn];
int l[maxn],r[maxn];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        memset(h,0,sizeof(h));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&mat[i][j]);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mat[i][j]==0)
                    h[j]++;
                else
                    h[j]=0;
            }
            for(int j=1;j<=m;j++)
            {
                l[j]=j;
                while(l[j]>1&&h[j]<=h[l[j]-1])
                    l[j]=l[l[j]-1];
            }
            for(int j=m;j>=1;j--)
            {
                r[j]=j;
                while(r[j]<m&&h[j]<=h[r[j]+1])
                    r[j]=r[r[j]+1];
            }
            for(int j=1;j<=m;j++)
            {
                if(ans<h[j]*(r[j]-l[j]+1))
                    ans=h[j]*(r[j]-l[j]+1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

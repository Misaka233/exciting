#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double inf = 100000000;
double map[105][105];
int s[105],e[105],step[105][105],len1,len2;

struct node
{
    double x,y;
} a[105];

void floyd(int n)
{
    int i,j,k;
    for(k = 0; k<=n; k++)
        for(i = 0; i<=n; i++)
            for(j = 0; j<=n; j++)
                if(map[i][j]>map[i][k]+map[k][j])
                {
                    map[i][j]=map[i][k]+map[k][j];
                    step[i][j]=step[i][k]+step[k][j];
                }
}

int main()
{
    int n,i,j,k,len;
    double d,x,y;
    while(~scanf("%d%lf",&n,&d))
    {
        len = 1;
        for(i = 1; i<=n; i++)
        {
            scanf("%lf%lf",&x,&y);
            if(fabs(x)<=7.5 && fabs(y)<=7.5)//只将所有在小岛外的点存入图中
                continue;
            a[len].x = x;
            a[len++].y = y;
        }
        n = len;
        if(n == 1)//只存了一个点，直接判断
        {
            if(d>=42.5)
                printf("42.50 1\n");
            else
                printf("can't be saved\n");
            continue;
        }
        for(i = 0; i<=n; i++)
            for(j = 0; j<=n; j++)
            {
                map[i][j] = inf;
                step[i][j] = 0;
            }
        for(i = 1; i<n; i++)
        {
            for(j = 1; j<n; j++)
            {
                if(j==i)
                {
                    map[i][j] = 0;
                    continue;
                }
                map[i][j] = sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));//枚举所有距离
                step[i][j] = 1;
                if(map[i][j]>d)//步伐不能到达，将该店变为无穷大
                {
                    map[i][j] = inf;
                    step[i][j] = 0;
                }
            }
        }
        len1 = len2 = 0;
        for(i = 1; i<n; i++)
        {
            if(sqrt(a[i].x*a[i].x+a[i].y*a[i].y)<=7.5+d)//起始点必须是从小岛上出发，步伐能到达的点
                s[len1++] = i;
            if((50+a[i].x)<=d || (50-a[i].x)<=d || (50+a[i].y)<=d || (50-a[i].y)<=d)//借速点市所有能到达岸边的点
                e[len2++] = i;
        }
        for(i = 0; i<len1; i++)
        {
            map[0][s[i]] = map[s[i]][0] = sqrt(a[s[i]].x*a[s[i]].x+a[s[i]].y*a[s[i]].y)-7.5;//小岛到起始点的距离
            step[0][s[i]] = step[s[i]][0] = 1;
        }
        for(i = 0; i<len2; i++)
        {
            map[e[i]][n] = map[n][e[i]] = min(min(50+a[e[i]].x,50-a[e[i]].x),min(50+a[e[i]].y,50-a[e[i]].y));//结束点到岸边的最短距离
            step[e[i]][n] = step[n][e[i]] = 1;
        }
        floyd(n);
        if(map[0][n] == inf)
            printf("can't be saved\n");
        else
            printf("%.2f %d\n",map[0][n],step[0][n]);
    }

    return 0;
}

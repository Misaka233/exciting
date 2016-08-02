#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N = 1005;

struct Point
{
    int x,y;
};

Point p[N];
int repaired[N];
int pre[N],rank[N];

int dist(Point A,Point B)
{
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}

void Init(int n)
{
    for(int i=1;i<=n;i++)
    {
        pre[i] = i;
        rank[i] = 1;
    }
}

int Find(int x)
{
    if(pre[x] != x)
        pre[x] = Find(pre[x]);
    return pre[x];
}

void Union(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(rank[x] >= rank[y])
    {
        pre[y] = x;
        rank[x] += rank[y];
    }
    else
    {
        pre[x] = y;
        rank[y] += rank[x];
    }
}

int main()
{
    char ch[5];
    int n,d,x,y;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    int cnt = 0;
    Init(n);
    while(~scanf("%s",ch))
    {
        if(ch[0] == 'O')
        {
            scanf("%d",&x);
            for(int i=0;i<cnt;i++)
            {
                if(dist(p[repaired[i]],p[x]) <= d*d)
                    Union(repaired[i],x);
            }
            repaired[cnt++] = x;
        }
        else
        {
            scanf("%d%d",&x,&y);
            x = Find(x);
            y = Find(y);
            if(x == y) puts("SUCCESS");
            else       puts("FAIL");
        }
    }
    return 0;
}

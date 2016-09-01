#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 100005
#define mem(a) memset(a, 0, sizeof(a))
using namespace std;

int TreeArray[MAXN], Left[MAXN], Right[MAXN], Fork[MAXN];
typedef vector<int> Ve;
vector<Ve>Edge(MAXN);
int N,M;
int key;

void init()//初始化数组和
{
    mem(Left);  mem(Right);
    mem(Fork);  mem(TreeArray);
    for(int i=0;i<MAXN;i++)Edge[i].clear();
}

void DFS(int node)//为每一个node添加一个左值和右值，表示这个节点所
{
    Left[node] = key;
    for(int i=0;i<Edge[node].size();i++)
    {
        key+=1;
        DFS(Edge[node][i]);
    }
    Right[node] = key;
}

int LowBit(int x)//返回的是2^k
{
    return x & (x ^ (x-1));
}

void Edit(int k, int num)//修改节点k，如果是添加一个，代入1，删除一个代入-1
{
    while(k <= N)
    {
        TreeArray[k] += num;
        k += LowBit(k);
    }
}

int GetSum(int k)//得到1...k的和
{
    int sum = 0;
    while(k>=1)
    {
        sum += TreeArray[k];
        k -= LowBit(k);
    }
    return sum;
}

void ReadDataAndDo()
{
    int a,b;
    char ch;
    for(int i=1;i<N;i++)//输入a，b把边存放在容器里面
    {
        scanf("%d%d", &a, &b);
        Edge[a].push_back(b);
    }
    key = 1;    DFS(1);//为每一个节点对应一个左边界和右边界，他自己就存放在左边界里面，而它的管辖范围就是左边界到右边界
    for(int i=1;i<=N;i++)
    {
        Fork[i] = 1;//最初每个Fork上都有一个苹果
        Edit(i,1);//同时更新树状数组的值
    }
    scanf("%d%*c", &M);
    for(int i=0;i<M;i++)
    {
        scanf("%c %d%*c", &ch, &b);
        if(ch == 'Q')//b的子树就是[Left[b], right[b]]
        {
            printf("%d\n", GetSum(Right[b]) - GetSum(Left[b]-1));
        }
        else
        {
            if(Fork[b]) Edit(Left[b],-1);//由于每个节点的编号就是它的左值，所以直接修改左节点
            else Edit(Left[b],1);
            Fork[b] = !Fork[b];//变为相反的状态
        }
    }
}

int main()
{
    while(~scanf("%d", &N))
    {
        init();
        ReadDataAndDo();
    }
    return 0;
}

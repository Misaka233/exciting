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

void init()//��ʼ�������
{
    mem(Left);  mem(Right);
    mem(Fork);  mem(TreeArray);
    for(int i=0;i<MAXN;i++)Edge[i].clear();
}

void DFS(int node)//Ϊÿһ��node���һ����ֵ����ֵ����ʾ����ڵ���
{
    Left[node] = key;
    for(int i=0;i<Edge[node].size();i++)
    {
        key+=1;
        DFS(Edge[node][i]);
    }
    Right[node] = key;
}

int LowBit(int x)//���ص���2^k
{
    return x & (x ^ (x-1));
}

void Edit(int k, int num)//�޸Ľڵ�k����������һ��������1��ɾ��һ������-1
{
    while(k <= N)
    {
        TreeArray[k] += num;
        k += LowBit(k);
    }
}

int GetSum(int k)//�õ�1...k�ĺ�
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
    for(int i=1;i<N;i++)//����a��b�ѱߴ������������
    {
        scanf("%d%d", &a, &b);
        Edge[a].push_back(b);
    }
    key = 1;    DFS(1);//Ϊÿһ���ڵ��Ӧһ����߽���ұ߽磬���Լ��ʹ������߽����棬�����Ĺ�Ͻ��Χ������߽絽�ұ߽�
    for(int i=1;i<=N;i++)
    {
        Fork[i] = 1;//���ÿ��Fork�϶���һ��ƻ��
        Edit(i,1);//ͬʱ������״�����ֵ
    }
    scanf("%d%*c", &M);
    for(int i=0;i<M;i++)
    {
        scanf("%c %d%*c", &ch, &b);
        if(ch == 'Q')//b����������[Left[b], right[b]]
        {
            printf("%d\n", GetSum(Right[b]) - GetSum(Left[b]-1));
        }
        else
        {
            if(Fork[b]) Edit(Left[b],-1);//����ÿ���ڵ�ı�ž���������ֵ������ֱ���޸���ڵ�
            else Edit(Left[b],1);
            Fork[b] = !Fork[b];//��Ϊ�෴��״̬
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

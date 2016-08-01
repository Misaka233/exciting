#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
//lson��rson�ֱ��ʾ��������Ӻ��Ҷ���
//rt��ʾ��ǰ�����ĸ�(root),Ҳ���ǵ�ǰ���ڵĽ��
#define INF 0x3fffffff
__int64 mmin[5000047];
__int64 col[5000047];
__int64 MIN(__int64 a, __int64 b)
{
	if( a < b)
		return a;
	return b;
}
void pushup(int rt)
{
	//sum[rt] = sum[rt<<1] + sum[rt<<1|1];
	mmin[rt]=MIN(mmin[rt<<1], mmin[rt<<1|1]);
}
void pushdown(int rt, int m)
{
	if(col[rt])
	{
		col[rt<<1]+=col[rt];
		col[rt<<1|1]+=col[rt];
		mmin[rt<<1]+=col[rt];
		mmin[rt<<1|1]+=col[rt];
		col[rt]=0;
	}
}
void build(int l, int r, int rt)
{
	col[rt]=0;
	if(l==r)
	{
		scanf("%I64d", &mmin[rt]);
		return ;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
void update(int L, int R, int v, int l, int r, int rt)
{
	if(L<=l && r<=R)
	{
		col[rt]+=v;
		mmin[rt]+=v;
		return ;
	}
	pushdown(rt, r-l+1);
	int m=(l+r)>>1;
	if(L<=m)
		update(L, R, v, lson);
	if(R>m)
		update(L, R, v, rson);
	pushup(rt);
}
__int64 query(int L, int R, int l, int r, int rt)
{//��ѯ����[L��R]�е���Сֵ
	if(L<=l && r<=R)//��ǰ�����ȫ�����ڲ�ѯ������
		return mmin[rt];
	pushdown(rt, r-l+1);
	int m=(l+r)>>1;
	__int64 ret=INF;
	if(L<=m)//������
		ret=MIN(ret, query(L, R, lson));
	if(R>m)//������
		ret=MIN(ret, query(L, R, rson));
	return ret;
}

int main()
{
	int n, m, a, b, c;
	char op;
	scanf("%d", &n);
	build(1, n, 1);
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d%d%c", &a, &b, &op);
		a++;//������ת��Ϊ��1��n
		b++;
		if(a<=b)
		{
			if(op==' ')//��ζ���������������Ĳ���
			{
				scanf("%d", &c);
				if(c==0)
					continue;
				update(a, b, c, 1, n, 1);
			}
			else
				printf("%I64d\n", query(a, b, 1, n, 1));
		}
		else
		{
			if(op==' ')
			{
				scanf("%d", &c);
				if(c==0)
					continue;
				update(a, n, c, 1, n, 1);//�������Ϊa��n��1��b
				update(1, b, c, 1, n, 1);
			}
			else
				printf("%I64d\n", MIN(query(a, n, 1, n, 1), query(1, b, 1, n, 1)));
		}
	}
	return 0;
}

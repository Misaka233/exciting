#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 50000 + 16

typedef struct Range
{
	int a;
	int b;
	int c;
	bool operator < (const Range& other) const
	{
		return b < other.b;
	}
};

Range range[MAX_N];
bool used[MAX_N];
template <class T>
class BinaryIndexedTree
{
public:
	T bit[MAX_N];
	int size;

	BinaryIndexedTree(){}

	void init(int size)
	{
		this->size = size;
		memset(bit, 0, sizeof(bit));
	}

	T sum(int i)
	{
		++i;
		int s = 0;
		while (i > 0)
		{
			s += bit[i];
			i -= (i & -i);
		}
		return s;
	}

	// 求和a[from, to)
	T sum(int from, int to)
	{
		return sum(to - 1) - sum(from - 1);
	}

	void add(int i, T v)
	{
		++i;    // 防止如果i是0的话，下面的循环永远不会终止
		while (i <= size)
		{
			bit[i] += v;
			i += (i & -i);
		}
	}
};

BinaryIndexedTree<int> bit;

int main(int argc, char *argv[])
{

	int n;

	scanf("%d", &n);
	bit.init(MAX_N);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d", &range[i].a, &range[i].b, &range[i].c);
	}

	sort(range, range + n);
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int picked = bit.sum(range[i].a, range[i].b + 1);
		if (picked < range[i].c)
		{
			int remain = range[i].c - picked;
			result += remain;
			int tail = range[i].b;
			while (remain)
			{
				if (used[tail] == false)
				{
					used[tail] = true;
					bit.add(tail, 1);
					--remain;
				}
				--tail;
			}
		}
	}
	printf("%d\n", result);

	return 0;
}

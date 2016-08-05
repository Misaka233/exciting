/*先求最短路，如果花费超出了在求次短路，超出了再求第3短路……
如何每次求出当前的最短路呢？
设当前节点为x，路程为x.dist，
假设从x可以扩展到两个节点i，j，设从i到终点的最短路为d[i]，从j到终点的最短路为d[j]，
若i.dist + d[i] < j.dist + d[j]，则当前的最短路一定会走i而不是j。
d数组可以先对反向图以节点n为源点做一次spfa求出。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

struct Node{
	int v, dist, tot, cost; // 当前节点，当前路程，当前路程加上当前节点到终点的最短路，当前花费
	Node() {}
	Node(int a, int b, int c, int d) : v(a), dist(b), tot(c), cost(d) {}
	bool operator < (const Node &n) const { // 优先队列用，每次取出i.dist+d[i]最小的
		if (tot != n.tot)
			return tot > n.tot;
		return dist < n.dist;
	}
};

struct Edge{
	int to, v, cost;
	Edge(int a, int b, int c) : to(a), v(b), cost(c) {}
};

int n, m, k;
vector<Edge> edges[105];
vector<Edge> redges[105]; // 反向图
int dist[105]; //dist[i]表示从节点i到终点的最短路
int vis[105];
void spfa() { // 求dist数组
	queue<int> q;
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	vis[n] = 1;
	dist[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < redges[current].size(); i++) {
			Edge e = redges[current][i];
			if (dist[current] + e.v < dist[e.to]) {
				dist[e.to] = dist[current] + e.v;
				if (!vis[e.to]) {
					vis[e.to] = 1;
					q.push(e.to);
				}
			}
		}
		vis[current] = 0;
	}
}

priority_queue<Node> q;
int spfaAstar() {
	while (!q.empty()) q.pop();
	if (dist[1] == 0x3f3f3f3f) return -1;
	Node start = Node(1, 0, dist[1], 0);
	q.push(start);
	while (!q.empty()) {
		Node cur = q.top();
		q.pop();
		if (cur.v == n) { // 如果当前节点为终点
			if (cur.cost <= k) return cur.dist; // 符合条件就return
		}
		for (int i = 0; i < edges[cur.v].size(); i++) {
			Edge e = edges[cur.v][i];
			if (cur.cost + e.cost > k) continue; // 很重要的一条剪枝，当前花费加这条路的花费大于k就减掉。
			q.push(Node(e.to, cur.dist + e.v, cur.dist + e.v + dist[e.to], cur.cost + e.cost)); // 将下一个点加入队列
		}
	}
	return -1;
}

int main() {
	while (~scanf("%d %d %d", &k, &n, &m)) {
		int a, b, c, d;
		for (int i = 0; i <= n; i++) {
			edges[i].clear();
			redges[i].clear();
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			edges[a].push_back(Edge(b, c, d));
			redges[b].push_back(Edge(a, c, d)); // 反向图
		}
		spfa();
		int ans = spfaAstar();
		printf("%d\n", ans);
	}
	return 0;
}


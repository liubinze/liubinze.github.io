#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int n, m, l[100005];
ll C;
vector<int> vec[100005];

int cnt, elst[200005];
struct edge {
	int to, nxt;
	ll len;
} e[500005];
inline void add(int u, int v, ll w) {
	e[++cnt].to = v;
	e[cnt].len = w;
	e[cnt].nxt = elst[u];
	elst[u] = cnt;
}

ll dis[200005];
bool vis[200005];
struct node {
	ll dis;
	int id;
	
	inline node() {}
	inline node(ll _dis, int _id) : dis(_dis), id(_id) {}
};
inline bool operator < (node x, node y) {
	return x.dis > y.dis;
}
priority_queue<node> pq;
inline void dijkstra(int s) {
	for (int i = 1; i <= n * 2; i++) dis[i] = 1e18;
	dis[s] = 0;
	pq.push(node(0, s));
	while (!pq.empty()) {
		node u = pq.top();
		pq.pop();
		if (vis[u.id]) continue;
		vis[u.id] = true;
		for (int i = elst[u.id]; i; i = e[i].nxt) {
			int v = e[i].to;
			if (dis[v] > dis[u.id] + e[i].len) dis[v] = dis[u.id] + e[i].len, pq.push(node(dis[v], v));
		}
	}
}

int main() {
	freopen("shortest.in", "r", stdin);
	freopen("shortest.out", "w", stdout);
	scanf("%d %d %lld", &n, &m, &C);
	for (int i = 1; i <= n; i++) scanf("%d", &l[i]), vec[l[i]].push_back(i);
	for (int i = 1; i <= m; i++) {
		int u, v;
		ll w;
		scanf("%d %d %lld", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i < n; i++) {
		if (!vec[i + 1].size()) continue;
		for (auto u : vec[i]) add(u, i + 1 + n, C);
	}
	for (int i = 2; i <= n; i++) {
		if (!vec[i - 1].size()) continue;
		for (auto u : vec[i]) add(u, i - 1 + n, C);
	}
	for (int i = 1; i <= n; i++) add(l[i] + n, i, 0);
	dijkstra(1);
	printf("%lld", dis[n] == 1e18 ? -1 : dis[n]);
	return 0;
}

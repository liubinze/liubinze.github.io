#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 5, M = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m, C, tot;
int l[N], dis[N], dist[N], dish[N], no[N];
bool exi[N], mark[N];

struct graph {
	int tot;
	int End[M << 1], len[M << 1], nxt[M << 1], lst[N];
	
	void add(int u, int v, int w) {
		End[++tot] = v;
		nxt[tot] = lst[u];
		lst[u] = tot;
		len[tot] = w;
	}
};
graph g;

struct node {
	int id, dis;
	
	node() {}
	node(int _id, int _dis) : id(_id), dis(_dis) {}
};
bool operator < (node a, node b) {
	return a.dis > b.dis;
}
priority_queue<node> pq;

struct fuck {
	int id, h;
	
	fuck() {}
	fuck(int _id, int _h) : id(_id), h(_h) {}
};
fuck f[N];
bool operator < (fuck a, fuck b) {
	return a.h < b.h;
}

void dijkstra(int st) {
	memset(dis, inf, sizeof(dis));
	memset(mark, false, sizeof(mark));
	dis[st] = 0;
	pq.push(node(st, 0));
	while (!pq.empty()) {
		node x = pq.top();
		pq.pop();
		if (mark[x.id]) continue;
		mark[x.id] = true;
		for (int i = g.lst[x.id]; i; i = g.nxt[i])
			if (dis[x.id] + g.len[i] <= dis[g.End[i]]) {
				dis[g.End[i]] = g.len[i] + dis[x.id];
				pq.push(node(g.End[i], dis[g.End[i]]));
			}
	}
}

int main() {
	freopen("shortest.in", "r", stdin);
	freopen("shortest.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &C);
	for (int i = 1; i <= n; i++) scanf("%d", &l[i]), exi[l[i]] = true;
	for (int i = 1; i <= n; i++) 
		if (!exi[i]) no[++no[0]] = i;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if (l[u] > l[v]) swap(u, v);
		if (u == v) {
			g.add(u, v, w), g.add(v, u, w);
			continue;
		}
		g.add(u, v, min(w, (l[v] - l[u]) * C)), g.add(v, u, (l[v] - l[u]) * C);
	}
	int ans = inf;
	dijkstra(1);
	ans = min(ans, dis[n]);
	for (int i = 1; i <= n; i++) dist[i] = dis[i];
	for (int i = 1; i <= n; i++)
		if (dis[i] != inf) f[++tot] = fuck(i, l[i]);
	sort(f + 1, f + 1 + tot);
	memset(dish, inf, sizeof(dish));
	for (int i = 1; i < tot; i++) {
		if (f[i + 1].h == f[i].h + 1) {
			dish[f[i].h + 1] = min(dish[f[i].h + 1], C + dis[f[i].id]);
			dish[f[i].h] = min(dish[f[i].h], C + dis[f[i + 1].id]);
			continue;
		}
		int sit = 0;
		for (int j = f[i + 1].h + 1; j < f[i + 1].h; j++) {
			if (!exi[j]) break;
			dish[j] = min(dish[j], C * (j - f[i].h) + dis[f[i].id]);
		}
		for (int j = f[i + 1].h - 1; j > f[i].h; j--) {
			if (!exi[j]) break;
			dish[j] = min(dish[j], C * (f[i + 1].h - j) + dis[f[i + 1].id]);
		}
	}
	for (int j = f[tot].h + 1; j <= n; j++) {
		if (!exi[j]) break;
		dish[j] = min(dish[j], C * (j - f[tot].h) + dis[f[tot].id]);
	}
	ans = min(ans, dish[l[n]]);
	for (int i = 1; i <= n; i++) {
		if (dis[i] != inf) continue;
		dijkstra(i);
		if (dis[n] == inf) continue;
		ans = min(ans, dish[l[i]] + dis[n]);
	}
	if (ans == inf) puts("-1");
	else printf("%d", ans);
	return 0;
}


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
using namespace std;

int n, m, A, B, tot, U[20005], V[20005], ans[5005];
bool vis[5005];
vector<int> G1[5005], G2[5005];

struct node {
	int x, y, id;
} a[5005];
inline bool operator < (node x, node y) {
	return x.y > y.y;
}

int tim, sc, dfn[5005], low[5005], scc[5005], siz[5005];
stack<int> stk;
inline void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	stk.push(u);
	for (auto v : G1[u]) {
		if (!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
		else if (!scc[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		sc++;
		while (stk.top() != u) {
			scc[stk.top()] = sc;
			if (a[stk.top()].x == A) siz[sc]++;
			stk.pop();
		}
		scc[stk.top()] = sc;
		if (a[stk.top()].x == A) siz[sc]++;
		stk.pop();
	}
}

bitset<5005> bs[5005];
inline void dfs(int u) {
	vis[u] = true;
	bs[u].set(u);
	for (auto v : G2[u]) {
		if (!vis[v]) dfs(v);
		bs[u] |= bs[v];
	}
}

int main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	scanf("%d %d %d %d", &n, &m, &A, &B);
	for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].x, &a[i].y), a[i].id = i;
	for (int i = 1; i <= m; i++) {
		int u, v, t;
		scanf("%d %d %d", &u, &v, &t);
		if (t & 1) {
			G1[u].push_back(v);
			U[++tot] = u;
			V[tot] = v;
		}
		else {
			G1[u].push_back(v);
			G1[v].push_back(u);
			U[++tot] = u;
			V[tot] = v;
			U[++tot] = v;
			V[tot] = u;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= tot; i++) {
		int u = U[i], v = V[i];
		if (scc[u] != scc[v]) G2[scc[u]].push_back(scc[v]);
	}
	for (int i = 1; i <= sc; i++)
		if (!vis[i]) dfs(i);
	for (int i = 1; i <= sc; i++)
		for (int j = 1; j <= sc; j++)
			if (bs[i].test(j)) ans[i] += siz[j];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		if (!a[i].x) printf("%d\n", ans[scc[a[i].id]]);
	return 0;
}

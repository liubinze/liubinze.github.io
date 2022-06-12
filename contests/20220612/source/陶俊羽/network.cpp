#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int enode, enext;
} edge[1800003];

int elast[300001], cntEdge = 0;

void addEdge(int u, int v) {
	edge[++ cntEdge].enode = v;
	edge[cntEdge].enext = elast[u];
	elast[u] = cntEdge;
}

int n, m, A, B, u, v, t, ans;
int x[300001], y[300001];
bool Visit[300001];
priority_queue<pair<int, int> > pq;

void DFS(int id) {
	Visit[id] = true;
	if (x[id] == A) ++ ans;
	for (int i = elast[id]; i; i = edge[i].enext)
		if (!Visit[edge[i].enode])
			DFS(edge[i].enode);
}


int main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	scanf("%d %d %d %d", &n, &m, &A, &B);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d %d", &x[i], &y[i]);
		if (!x[i]) pq.push(make_pair(y[i], i));
	}
	for (int i = 1; i <= m; ++ i) {
		scanf("%d %d %d", &u, &v, &t);
		addEdge(u, v);
		if (t == 2) addEdge(v, u);
	}
	while (!pq.empty()) {
		memset(Visit, false, sizeof Visit);
		ans = 0;
		DFS(pq.top().second);
		printf("%d\n", ans);
		pq.pop();
	}
	return 0;
}

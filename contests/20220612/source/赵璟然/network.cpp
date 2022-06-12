#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
const int N = 5e3 + 5, M = 1e4 + 5;

int n, m, A, B;
bool vis[N];
bitset<N> bs[N];
int posx[N], posy[N];

struct ans {
	int x, y, val;
};
ans a[N];
bool operator < (ans a, ans b) {
	return a.y > b.y;
}

struct graph {
	int tot;
	int End[M << 1], nxt[M << 1], lst[N];
	
	void add(int u, int v) {
		End[++tot] = v;
		nxt[tot] = lst[u];
		lst[u] = tot;
	}
};
graph g;

void dfs(int x) {
	bs[x][x] = true;
	vis[x] = true;
	for (int i = g.lst[x]; i; i = g.nxt[i]) {
		if (!vis[g.End[i]]) dfs(g.End[i]);
		bs[x] |= bs[g.End[i]];
	}
}

int main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	scanf("%d %d %d %d", &n, &m, &A, &B);
	for (int i = 1; i <= n; i++) scanf("%d %d", &posx[i], &posy[i]);
	for (int i = 1; i <= m; i++) {
		int opt, u, v;
		scanf("%d %d %d", &u, &v, &opt);
		if (opt == 1) g.add(u, v);
		else g.add(u, v), g.add(v, u);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i);
	for (int i = 1; i <= 3; i++) {
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= n; i++)
			if (!vis[i]) dfs(i);
	}
	for (int i = 1; i <= n; i++)
		if (posx[i] == 0) {
			int cnt = 0;
			for (int j = 1; j <= n; j++)
				if (posx[j] == A && bs[i][j]) cnt++;
			a[i].x = posx[i], a[i].y = posy[i], a[i].val = cnt;
		} else a[i].x = 114514;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		if (a[i].x == 0) printf("%d\n", a[i].val);
	return 0;
}


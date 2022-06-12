#include <bits/stdc++.h>
// WA

using namespace std;

struct Edge {
	int enode, enext;
} edge[1207];

int elast[57], cntEdge = 0;

void addEdge(int u, int v) {
	edge[++ cntEdge].enode = v;
	edge[cntEdge].enext = elast[u];
	elast[u] = cntEdge;
}

int T, n, m;
char ch[29][29];
int link[607];
bool Visit[607];


bool dfs(int u) {
	for (int i = elast[u]; i; i = edge[i].enext) {
		if (!Visit[edge[i].enode]) {
			Visit[edge[i].enode] = true;
			if (link[edge[i].enode] == -1 || dfs(link[edge[i].enode])) {
				link[edge[i].enode] = u;
				return true;
			}
		}
	}
	return false;
}


int main() {
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	scanf("%d", &T);
	while (T --) {
		memset(elast, 0, sizeof elast);
		cntEdge = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++ i) {
			scanf("%s", ch[i] + 1);
			for (int j = 1; j <= m; ++ j) {
				if (ch[i][j] == '*') {
					addEdge(i, j + n);
					addEdge(j + n, i);
				}
			}
		}
		int ans = 0;
		memset(link, -1, sizeof link);
		for (int i = 1; i <= n; ++ i) {
			memset(Visit, false, sizeof Visit);
			ans += dfs(i);
		}
		printf("%d\n", (int)(ceil((double)(ans) / 2)));
	}
	return 0;
}


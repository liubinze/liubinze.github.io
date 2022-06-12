#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n, m, ans = 1e9, cho[35][2];
bool mark[35][35], vis[35][2], qwq[35];

inline int get() {
	int res = 0;
	for (int i = 1; i <= n; i++) qwq[i] = false;
	for (int i = 2; i <= n; i++)
		if (mark[cho[i][0]][cho[i - 1][1]] || mark[cho[i][0]][cho[i][1]]) qwq[i] = true;
	if (mark[cho[1][0]][cho[n][1]] || mark[cho[1][0]][cho[1][1]]) qwq[1] = true;
	for (int i = 1; i <= n; i++)
		if (qwq[i]) res++;
	return res;
}
inline void dfs2(int now) {
	if (now == n + 1) {ans = min(ans, get()); return;}
	for (int i = 1; i <= n; i++)
		if (!vis[i][1]) {
			cho[now][1] = i;
			vis[i][1] = true;
			dfs2(now + 1);
			vis[i][1] = false;
		}
}
inline void dfs(int now) {
	if (now == n + 1) {dfs2(1); return;}
	for (int i = 1; i <= n; i++)
		if (!vis[i][0]) {
			cho[now][0] = i;
			vis[i][0] = true;
			dfs(now + 1);
			vis[i][0] = false;
		}
}


int main() {
	freopen("yy.in", "r", stdin);
	freopen("yy.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		memset(mark, false, sizeof(mark));
		for (int i = 1; i <= m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			mark[x][y] = true;
		}
		ans = 1e9;
		memset(vis, false, sizeof(vis));
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}

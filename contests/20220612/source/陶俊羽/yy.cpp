#include <bits/stdc++.h>

using namespace std;

int T, n, m, x, y, ans;
int val[13];
bool mark[23][23];
bool flag[19];

void DFS(int id, int node, int bg) {
//	cout << "> " << val[node] < " >";
//	for (int i = 1; i <= id; ++ i) cout << "\t";
//	cout << node << "\n";
//	for (int i = 1; i <= id; ++ i) cout << "\t";
//	for (int i = 1; i <= n; ++ i) cout << val[i] << " ";
//	cout << "\n";
	if (id == 2 * n) {
		if (mark[node][bg]) ++ val[min(bg, node)];
		int cnt = 0;
		for (int i = 1; i <= n; ++ i) cnt += (bool)(val[i]);
		if (mark[node][bg]) -- val[min(bg, node)];
		ans = min(ans, cnt);
		return;
	}
	flag[node] = true;
	if (node <= n) {
		for (int i = n + 1; i <= 2 * n; ++ i) {
			if (!flag[i]) {
				if (mark[node][i]) ++ val[node];
				DFS(id + 1, i, bg);
				flag[i] = false;
				if (mark[node][i]) -- val[node];
			}
		}
	} else {
		for (int i = 1; i <= n; ++ i) {
			if (!flag[i]) {
				if (mark[node][i]) ++ val[i];
				DFS(id + 1, i, bg);
				flag[i] = false;
				if (mark[node][i]) -- val[i];
			}
		}
	}
}

int main() {
	freopen("yy.in", "r", stdin);
	freopen("yy.out", "w", stdout);
	scanf("%d", &T);
	while (T --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= 2 * n; ++ i) for (int j = 1; j <= 2 * n; ++ j) mark[i][j] = false;
		for (int i = 1; i <= m; ++ i) {
			scanf("%d %d", &x, &y);
			mark[x][y + n] = mark[y + n][x] = true;
		}
		ans = 0x3f3f3f3f;
		memset(flag, false, sizeof flag);
		memset(val, false, sizeof val);
		for (int i = 1; i <= 2 * n; ++ i)
			DFS(1, i, i);
		printf("%d\n", ans);
	}
	return 0;
}

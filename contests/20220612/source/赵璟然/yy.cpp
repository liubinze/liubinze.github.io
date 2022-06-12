#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;

int T, n, m, res;
int ans[20];
bool mark[20][20], vis[20];

void dfs(int dep) {
	if (dep == 2 * n + 1) {
		int cnt = 0;
		for (int i = 3; i <= 2 * n; i += 2) 
			if (mark[ans[i]][ans[i - 1]] || mark[ans[i]][ans[i + 1]]) cnt++;
		if (mark[ans[1]][ans[2]] || mark[ans[1]][ans[n * 2]]) cnt++;
		res = min(res, cnt);
		return;
	}
	if (dep & 1) {
		for (int i = 1; i <= n; i++)
			if (!vis[i]) {
				vis[i] = true;
				ans[dep] = i;
				dfs(dep + 1);
				vis[i] = false;
			}
	} else {
		for (int i = n + 1; i <= 2 * n; i++)
			if (!vis[i]) {
				vis[i] = true;
				ans[dep] = i;
				dfs(dep + 1);
				vis[i] = false;
			}
	}
}

int main() {
	freopen("yy.in", "r", stdin);
	freopen("yy.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		res = inf;
		memset(mark, false, sizeof(mark));
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			mark[a][b + n] = mark[b + n][a] = true;
		}
		dfs(1);
		printf("%d\n", res);
				
	}
	return 0;
}


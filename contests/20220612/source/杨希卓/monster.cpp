#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#define pii pair<int, int>
#define mp make_pair
#define fir first
#define sec second
using namespace std;

int n, m, ans = 1e9, cnt;
char s[30][30];
bool visn[30], vism[30];
pii mon[905];

inline bool check(int tot) {
	for (int i = 1; i <= cnt; i++)
		if (!visn[mon[i].fir] && !vism[mon[i].sec]) return false;
	return true;
}

inline void dfs(int now, int tot) {
	if (now == n + 1) {
		if (check(tot)) ans = min(ans, tot);
		return;
	}
	dfs(now + 1, tot);
	for (int i = 1; i <= m; i++)
		if (!vism[i]) {
			visn[now] = true;
			vism[i] = true;
			dfs(now + 1, tot + 1);
			visn[now] = false;
			vism[i] = false;
		}
}

int main() {
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%s", s[i] + 1);
			for (int j = 1; j <= m; j++)
				if (s[i][j] == '*') mon[++cnt] = mp(i, j);
		}
		ans = 1e9;
		memset(visn, false, sizeof(visn));
		memset(vism, false, sizeof(vism));
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int T, n, m, cnt;
int vis[N][N], a[N];
int link[N], flag[N];

int en, first[N];
struct edge {
	int e, next;
}ed[N];

void add_edge(int s, int e) {
	en++;
	ed[en].e = e;
	ed[en].next = first[s];
	first[s] = en;
}

int dfs(int u) {
	for (int p = first[u]; p; p = ed[p].next) {
		int v = ed[p].e;
		if (flag[v]) continue;
		flag[v] = 1;
		if (!link[v] || dfs(link[v]) ) {
			link[v] = u;
			return 1;
		}
	}
	return 0;
}

int ans = 2e9;

int main() {
	freopen("yy.in", "r", stdin);
	freopen("yy.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(vis, 0, sizeof vis);
		ans = 1e9;
		cin >> n >>  m;
		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			vis[a][b] = 1;
		}
		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}
		do {
			en = cnt = 0;
			memset(first, 0, sizeof first);
			memset(link, 0, sizeof link);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					int tmp = 0;
					if ((j + 1) % n == 0)  tmp = n;
					else tmp = (j + 1) % n;
					if (vis[i][a[j]] == 0 && vis[i][a[tmp]] == 0) {
						add_edge(i, j);
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				memset(flag, 0, sizeof flag);
				cnt += dfs(i);
			}
			ans = min(ans, n - cnt);
		}while(next_permutation(a + 1, a + n + 1));
		cout << ans << endl;
	}
}

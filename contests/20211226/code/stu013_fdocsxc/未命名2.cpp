#include <cstdio>

int s[100005][11], a[100005];

int main() {
	freopen("removal.in", "r", stdin);
	freopen("removal.out", "w", stdout);
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3) {
		for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= 10; ++ j) s[i][j] = 0;
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", a + i);
			for (int j = 1; j <= 10; ++ j) s[i][j] = s[i - 1][j] + (a[i] == j);
		}
		int pos = 1;
		while (pos <= n) {
			if (n - pos + 1 <= m) break;
			for (int i = 1; i <= 10; ++ i) if (s[n][i] - s[pos - 1][i]) {
				int l = pos, r = n;
				while (l < r) {
					int mid = l + r >> 1;
					if (s[mid][i] - s[pos - 1][i]) r = mid;
					else l = mid + 1;
				}
				if (l - pos <= m) {m -= l - pos, pos = l + 1; break;}
			}
			printf("%d ", a[pos - 1]);
		}
		puts("");
	}
}

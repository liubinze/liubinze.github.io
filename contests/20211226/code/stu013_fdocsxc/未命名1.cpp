#include <cstdio>

int a[5005], dp[5005], nxt[5005];

int main() {
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
	for (int i = n; i; -- i) {
		int mx = 0;
		for (int j = i + 1; j <= n; ++ j) if (a[i] < a[j]) {
			if (dp[j] > dp[mx]) mx = j;
			else if (dp[j] == dp[mx] && (a[j] > a[mx])) mx = j;
		}
		nxt[i] = mx, dp[i] = dp[mx] + 1;
	}
	int pos = 0;
	for (int i = 1; i <= n; ++ i)
		if (dp[i] > dp[pos] || (dp[i] == dp[pos] && a[pos] < a[i])) pos = i;
	printf("%d\n", dp[pos]);
	while (pos) printf("%d ", a[pos]), pos = nxt[pos];
	return 0;
}

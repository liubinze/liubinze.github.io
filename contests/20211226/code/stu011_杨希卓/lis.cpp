#include <cstdio>
#include <iostream>
using namespace std;

int tot, a[5005], dp[5005], pre[5005], ans[5005][5005];

int main() {
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	int n, now = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] >= a[i]) continue;
			if (dp[i] < dp[j] + 1 || dp[i] == dp[j] + 1 && a[pre[i]] < a[j]) dp[i] = dp[j] + 1, pre[i] = j;
		}
	}
	for (int i = 1; i <= n; i++) {
		int th = i;
		while (th) ans[i][++ans[i][0]] = a[th], th = pre[th];
	}
	for (int i = 2; i <= n; i++) {
		if (dp[i] < dp[now]) continue;
		if (dp[i] > dp[now]) {now = i; continue;}
		bool flag = false;
		for (int j = ans[i][0]; j; j--)
			if (ans[i][j] > ans[now][j]) {flag = true; break;}
		if (flag) now = i;
	}
	printf("%d\n", dp[now]);
	for (int i = ans[now][0]; i; i--) printf("%d ", ans[now][i]);
	return 0;
}

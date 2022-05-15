#include <bits/stdc++.h>
using namespace std;
int n, ans, a[5007], dp[5007], vis[5007][2];
bool flag, flag2;
void dfs (int step, int idx) {
	if (step == ans) {
		for (int i = 1; i <= step; i ++) {
			if (vis[i][flag2] > vis[i][!flag2]) {
				flag = 1;
				break;
			}
			else if (vis[i][flag2] < vis[i][!flag2]) {
				break;
			}
		}
		if (flag) {
			flag2 = !flag2;
			flag = 0;
		}
	}
	if (idx >= n) {
		return;
	}
	for (int i = idx + 1; i <= n; i ++) {
		if (a[i] > a[idx]) {
			vis[step + 1][flag2] = a[i];
			dfs (step + 1, i);
		}
	}
}
int main () {
	freopen ("lis.in", "r", stdin);
	freopen ("lis.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf ("%d", &a[i]);
	}
	dp[1] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < i; j ++) {
			if (a[i] > a[j]) {
				dp[i] = max (dp[i], dp[j] + 1);
			}
		}
		ans = max (ans, dp[i]);
	}
	printf ("%d\n", ans);
	dfs (0, 0);
	for (int i = 1; i <= ans; i ++) {
		printf ("%d ", vis[i][!flag2]);
	} 
	return 0;
}

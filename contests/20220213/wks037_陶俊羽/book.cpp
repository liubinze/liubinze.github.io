#include <bits/stdc++.h>

using namespace std;


int m, n;
int arr[1003], sum[1003], dp[1003][1003];

int main() {
	freopen("book.in", "r", stdin);
	freopen("book.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m && j <= i; j ++) {
			dp[i][j] = 0x3f3f3f3f;
			if (j == 1) dp[i][j] = sum[i];
			else for (int k = 1; k < i; k ++) dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sum[i] - sum[k]));
		}
	}
	printf("%d", dp[n][m]);
	return 0;
}

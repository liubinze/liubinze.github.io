#include <bits/stdc++.h>
using namespace std;
int n, m, K, s[1007], dp[1007][11][11];
int main () {
	while (scanf("%d %d %d", &n, &m, &K) == 3) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &s[i]);
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				for(int k = 1; k <= K; k ++) {
					if(s[i] == k) {
						for(int x = 1; x <= K; x ++) {
							dp[i][j][k] += dp[i - 1][j][x];
						}
					}
					else {
						dp[i][j][k] = dp[i - 1][j - 1][k];
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= 10; i ++) {
			ans += dp[n][m][i];
		}
		cout << ans << endl;
	}
	return 0;
}



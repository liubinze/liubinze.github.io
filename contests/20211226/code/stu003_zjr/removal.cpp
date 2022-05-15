#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m, k;
int a[N];
int dp[N][15], from[N][15];

void solve() {
	int x = 1, y = m;
	while (x <= n && y >= 1) {
		printf("%d ", dp[x][y]);
		if (from[x][y] == 1) x++, y--;
		else x++;
	}
} 

int main() {
	//freopen("removal.in", "r", stdin);
	//freopen("removal.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dp[n][0] = a[n];
	for (int i = n - 1; i; i--)
		for (int j = 1; j <= m; j++)
			if (a[i] > dp[i + 1][j - 1]) dp[i][j] = dp[i + 1][j - 1], from[i][j] = 1;
			else if (a[i] < dp[i + 1][j - 1]) dp[i][j] = a[i], from[i][j] = 2;
			else dp[i][j] = a[i], from[i][j] = 2;
	solve();
	return 0;
}


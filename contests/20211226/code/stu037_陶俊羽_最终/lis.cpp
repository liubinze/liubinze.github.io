#include <bits/stdc++.h>

using namespace std;

int n, m, tmp = 0;
int a[5003], dp[5003], ans[5003];

int f(int u, int v) {
	if (ans[u] != 0) {
		int temp = f(ans[u], ans[v]);
		if (temp = 0) {
			if (a[u] > a[v]) temp = 1;
			else if (a[u] < a[v]) temp = 2;
			else temp = 0;
		}
		return temp;
	}
	if (a[u] > a[v]) return 1;
	else if (a[u] < a[v]) return 2;
	return 0;
}

void print(int w) {
	if (ans[w] == 0) printf("%d ", a[w]);
	else {
		print(ans[w]);
		printf("%d ", a[w]);
	}
}

int main() {
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		for (int j = 0; j < i; j ++) {
			if (a[j] < a[i] && dp[j] + 1 >= dp[i]) {
				if (dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1, ans[i] = j;
				else if (f(ans[ans[i]], ans[j]) == 2) ans[i] = j;
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (dp[i] > tmp) tmp = dp[i], m = i;
		else if (dp[i] == tmp) {
			if (f(i, m) == 1) m = i;
		}
	}
	printf("%d\n", dp[m]);
	print(ans[m]);
	printf("%d\n", a[m]);
	return 0;
}


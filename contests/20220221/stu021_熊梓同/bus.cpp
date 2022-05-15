#include <bits/stdc++.h>
using namespace std;
int n, m, c, t[100007], ans;
int main () {
	freopen ("bus.in", "r", stdin);
	freopen ("bus.out", "w", stdout);
	scanf ("%d %d %d", &n, &m, &c);
	if (m >= n) {
		printf ("0");
		return 0;
	}
	for (int i = 1; i <= n; ++ i) {
		scanf ("%d", &t[i]);
	}
	sort (t + 1, t + n + 1);
	if (m * c == n) {
		for (int i = 1; i <= n; i += c) {
			ans = max (ans, t[i + c - 1] - t[i]);
		}
		printf ("%d", ans);
		return 0;
	}
	return 0;
} 

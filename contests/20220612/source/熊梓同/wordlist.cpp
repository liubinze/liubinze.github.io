#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000007];
bool check (int x) {
	int cnt = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		cnt = max (cnt, a[i]);
		if (i == n) {
			ans += cnt * 1ll;
		}
		else if (i % x == 0) {
			ans += cnt * 1ll + 1ll;
			cnt = 0;
		}
		if (ans > m * 1ll) {
			return 0;
		}
	}
	return 1;
}
int solve () {
	int l = 1, r = n, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (check (mid)) {
			r = mid;
		} 
		else {
			l = mid + 1;
		}
	}
	if (!check (l)) l ++;
	return l;
}
int main () {
	freopen ("wordlist.in", "r", stdin);
	freopen ("wordlist.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		scanf ("%d", &a[i]);
	}
	int ans = solve ();
	cout << ans << endl;
	return 0;
}

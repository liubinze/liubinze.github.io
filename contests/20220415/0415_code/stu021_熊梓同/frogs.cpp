#include <bits/stdc++.h>
using namespace std;
long long n, m, cnt, ans, a[10007], mp[100007];
signed main () {
	freopen ("frogs.in", "r", stdin);
	freopen ("frogs.out", "w", stdout);
	scanf ("%lld %lld", &n, &m);
	for (long long i = 1; i <= n; i ++) {
		scanf ("%lld", &a[i]);
	}
	sort (a + 1, a + n + 1);
	for (long long i = 1; i <= n; i ++) {
		if (a[i] == a[i - 1]) continue;
		long long gcd = __gcd (a[i], m);
		gcd = m / gcd;
//		cout << gcd << endl;
		for (long long j = 1; j <= gcd; j ++) {
			mp[j * a[i] % m] ++;
		}
	}
	for (long long i = 1; i <= m; i ++) {
		if (mp[i])
			ans += i;
	}
	printf ("%lld", ans);
//	for (int i = 1; i <= n; i ++) {
//		int gcd = __gcd (a[i], m);
//		gcd = m / gcd;
//		cnt = ((a[i] + a[i] * gcd) / 2) % m * gcd % m;
//		ans = (ans + cnt) % m;
//	}
//	for (int i = 1; i <= n; i ++) {
//		for (int j = 1; j < i; j ++) {
//			long long gcd = __gcd (a[i], a[j]);
//			long long lcm = a[i] * a[j] / gcd;
//		}
//	}
	return 0;
}

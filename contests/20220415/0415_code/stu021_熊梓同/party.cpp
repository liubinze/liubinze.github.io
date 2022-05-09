#include <bits/stdc++.h>
using namespace std;
long long n, p[1000007], a[1000007], cnt, ps;
long long ans1, ans2;
int main () {
	freopen ("party.in", "r", stdin);
	freopen ("party.out", "w", stdout);
	scanf ("%lld", &n);
	for (long long i = 1; i <= n; i ++) {
		scanf ("%lld %lld", &p[i], &a[i]);
		cnt += p[i] * a[i];
		ps += a[i];
	}
	cnt /= ps;
//	cout << cnt;
	long long x = upper_bound (p + 1, p + n + 1, cnt) - p - 1;
	for (long long i = 1; i <= n; i ++) {
		ans1 += abs (p[i] - p[x]) * a[i];
		ans2 += abs (p[i] - p[x + 1]) * a[i];
	}
	printf ("%lld", min (ans1, ans2));
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, m;
long long ans = 0;
int a[10003];

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	freopen("frogs.in", "r", stdin);
	freopen("frogs.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", &a[i]);
		if (a[i] >= m) a[i] %= m;
		a[i] = gcd(a[i], m);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j)
			if (a[j] <= m)
				if (!(a[j] % a[i]))
					a[j] = m + 1;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n && a[i] <= m; ++ i)
		ans += ((long long)(m) / a[i] * (m - a[i])) >> 1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = i + 1; j <= n && a[j] <= m; ++ j) {
			long long k = (long long)(a[i]) * a[j] / gcd(a[i], a[j]);
			ans -= ((long long)(m) / k * (m - k)) >> 1;
		}
	}
	printf("%d", ans);
	return 0;
}

#include <stdio.h>
#include <set>
#define int long long
using namespace std;
const int N = 1e4 + 5;

int n, m;
int a[N];
set<int> se;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

signed main() {
	freopen("frogs.in", "r", stdin);
	freopen("frogs.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] = gcd(a[i], m);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j += a[i]) se.insert(j);
	int ans = 0;
	for (set<int>::iterator it = se.begin(); it != se.end(); it++) ans += *it;
	printf("%lld", ans);
	return 0;
}


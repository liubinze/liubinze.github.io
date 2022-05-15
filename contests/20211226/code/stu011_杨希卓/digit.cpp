#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	freopen("digit.in", "r", stdin);
	freopen("digit.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		ll l, r, u, v, z1, z2, t1 = 0, t2 = 0;
		scanf("%lld %lld", &l, &r);
		u = l % 9;
		if (!u) u = 9;
		v = r % 9;
		if (!v) v = 9;
		z1 = (l - 1) / 9 + 1;
		z2 = (r - 1) / 9 + 1;
		if (z1 == z2) {
			for (ll i = u; i <= v; i++) t1 += i;
			printf("%lld\n", t1);
			continue;
		}
		for (ll i = u; i <= 9; i++) t1 += i;
		for (ll i = 1; i <= v; i++) t2 += i;
		printf("%lld\n", t1 + t2 + (z2 - z1 - 1) * 45);
	}
	return 0;
}

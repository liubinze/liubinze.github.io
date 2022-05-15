#include <bits/stdc++.h>

using namespace std;

int Q;
long long l, r;

inline long long f(long long n) {
	return (n / 9 * 45) + (1 + n % 9) * (n % 9) / 2;
}

int main() {
	freopen("digit.in", "r", stdin);
	freopen("digit.out", "w", stdout);
	scanf("%d", &Q);
	while (Q --) {
		scanf("%lld %lld", &l, &r);
		printf("%lld\n", f(r) - f(l - 1));
	}
	return 0;
}

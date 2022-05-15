#include <bits/stdc++.h>

using namespace std;

unsigned long long n, b[65];
int k, T;

unsigned long long func(unsigned long long n, int k) {
	unsigned long long x = n & (-n);
	unsigned long long y = x + n;
	if (y >= b[k]) y -= b[k];
	return y | ((n ^ y) / x) >> 2;
}

int main() {
	freopen("anti.in", "r", stdin);
	freopen("anti.out", "w", stdout);
	b[0] = 1;
	for (int i = 1; i <= 64; i ++)
		b[i] = b[i - 1] * 2;
	scanf("%d", &T);
	while (T --) {
		scanf("%llu %d", &n, &k);
		printf("%llu\n", func(n, k));
	}
	return 0;
}

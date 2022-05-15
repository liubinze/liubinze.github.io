#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

int div[10000005], p[10000005], r[10000005], f[10000005];

bool is_prime[10000005];
int prime[1000005], minp[10000005];
inline void init(int n) {
	for (int i = 2; i <= n; i++) is_prime[i] = true;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) prime[++prime[0]] = i, minp[i] = i;
		for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
			is_prime[i * prime[j]] = false;
			minp[i * prime[j]] = min(prime[j], minp[i]);
			if (i % prime[j] == 0) break;
		}
	}
}

int main() {
	freopen("gn.in", "r", stdin);
	freopen("gn.out", "w", stdout);
	init(1e7);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, d = 0, tmp, k = 0;
		scanf("%d", &n);
		tmp = n;
		while (tmp > 1) {
			if (p[k] != minp[tmp]) p[++k] = minp[tmp], r[k] = 1;
			else r[k]++;
			tmp /= minp[tmp];
		}
		div[++d] = 1;
		for (int i = 1; i <= k; i++) {
			int now = d, pk = 1;
			for (int j = 1; j <= r[i]; j++) {
				pk *= p[i];
				for (int l = 1; l <= now; l++) div[++d] = pk * div[l];
			}
		}
		for (int i = 1; i <= d; i++) {
			tmp = div[i];
			int nowp = 0, nowr = 0;
			while (tmp > 1) {
				if (nowp != minp[tmp]) {
					f[div[i]] = max(f[div[i]], nowr);
					nowp = minp[tmp];
					nowr = 1;
					f[div[i]] = max(f[div[i]], nowr);
				}
				else nowr++, f[div[i]] = max(f[div[i]], nowr);
				tmp /= minp[tmp];
			}
		}
		ll ans = 0;
		for (int i = 1; i <= d; i++) ans += 1ll * div[i] * f[n / div[i]];
		printf("%lld\n", ans);
	}
	return 0;
}

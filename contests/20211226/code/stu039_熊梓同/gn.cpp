#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 7;
const long long M = 1e6 + 7;
long long n, idx, p[N], ri[N], pi[N], r1[N], p1[N], zys[N], zs[N], ys[N];
bool vis[N];
int main () {
	freopen ("gn.in", "r", stdin);
	freopen ("gn.out", "w", stdout);
	long long T;
	for (long long i = 2; i <= N; i ++) {
		if (!vis[i]) {
			idx ++;
			p[idx] = i;
			ri[i] = r1[i] = 1;
			pi[i] = p1[i] = i;
		}
		for(long long j = 1; j <= idx && i * p[j] <= N; j ++) {
			vis[i * p[j]] = true;
			if (i % p[j] == 0) {
				r1[i * p[j]] = r1[i] + 1;
				p1[i * p[j]] = p[j];
				if(r1[i] + 1 >= ri[i]) {
					pi[i * p[j]] = p[j];
					ri[i * p[j]] = r1[i] + 1;
				}
				else {
					pi[i * p[j]] = pi[i];
					ri[i * p[j]] = ri[i];
				}
				break;
			}
			else {
				r1[i * p[j]] = 1;
				p1[i * p[j]] = p[j];
				if(pi[i] == 1) {
					pi[i * p[j]] = p[j];
					ri[i * p[j]] = 1;
					continue;
				}
				pi[i * p[j]] = pi[i];
				ri[i * p[j]] = ri[i];
			}
		}
	}
	scanf ("%lld", &T);
	while (T --) {
		scanf ("%lld", &n);
		long long tot = 0;
		long long nx = n;
		while(n != 1) {
			zs[tot] = r1[n];
			zys[tot ++] = p1[n];
			for(long long i = 1; i <= zs[tot - 1]; i ++) {
				n /= p1[n];
			}
		}
		long long m = 0;
		ys[m ++] = 1; 
		for (long long i = 0; i < tot; i ++) {
			long long range = m, pk = 1;
			for (long long j = 1; j <= zs[i]; j ++) {
				pk *= zys[i];
				for(long long k = 0; k < range; k ++) {
					ys[m ++] = pk * ys[k];
				}
			}
		}
		long long ans = 0;
		for(long long i = 0; i < m; i ++) {
			ans += ys[i] * ri[nx / ys[i]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

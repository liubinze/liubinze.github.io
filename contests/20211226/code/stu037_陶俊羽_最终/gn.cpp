#include <bits/stdc++.h>

using namespace std;

int T, n;
long long ans;
int prime[664583], minp[10000003], f[10000003], temp[664583], cnt[664583];
bool mark[10000003];

void g(long long m, long long pos) {
	long long M = m;
	if (pos > temp[0]) {
		ans += f[m] * (n / (int)m);
		return;
	}
	for (long long i = 0, j = 1; i <= cnt[pos]; i ++, j *= temp[pos], m *= temp[pos]) {
		f[m] = (f[M] > f[j] ? f[M] : f[j]);
		g(m, pos + 1);
	}
}

int main() {
	freopen("gn.in", "r", stdin);
	freopen("gn.out", "w", stdout);
	for (register int i = 2; i <= 10000000; i ++) {
		if (!mark[i]) minp[i] = prime[++ prime[0]] = i;
		for (int j = 1; j <= prime[0] && i * prime[j] <= 10000000; j ++) {
			int k = i * prime[j];
			mark[k] = true;
			minp[k] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
	for (int i = 1; i <= prime[0]; i ++)
		for (long long j = prime[i],k = 1; j <= 10000000; j *= prime[i], k ++)
			f[j] = k;
	scanf("%d", &T);
	while (T --) {
		ans = temp[0] = 0;
		scanf("%d", &n);
		for (int i = n; i > 1; i /= minp[i]) {
			if (temp[temp[0]] == minp[i]) cnt[temp[0]] ++;
			else {
				temp[++ temp[0]] = minp[i];
				cnt[temp[0]] = 1;
			}
		}
		g(1, 1);
		printf("%lld\n", ans);
	}
	return 0;
}


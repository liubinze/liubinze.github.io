#include <bits/stdc++.h>

using namespace std;

long long T, n, ans;
long long prime[664583], minp[10000003], f[10000003], temp[664583], cnt[664583];
bool mark[10000003];

queue<long long> q;

/*void g(long long m, long long pos) {
	long long M = m;
	if (pos > temp[0]) {
		ans += f[m] * (n / m);
		return;
	}
	for (long long i = 0, j = 1; i <= cnt[pos]; i ++, j *= temp[pos], m *= temp[pos]) {
		f[m] = max(f[M], f[j]);
		g(m, pos + 1);
	}
}*/

int main() {
	//freopen("gn.in", "r", stdin);
	//freopen("gn.out", "w", stdout);
	for (long long i = 2; i <= 10000000; i ++) {
		if (!mark[i]) minp[i] = prime[++ prime[0]] = i;
		for (long long j = 1; j <= prime[0] && i * prime[j] <= 10000000; j ++) {
			mark[i * prime[j]] = true;
			minp[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
	for (long long i = 1; i <= prime[0]; i ++)
		f[prime[i]] = 1;
	q.push(1);
	for (long long pos = 1; pos <= p[0]; pos ++) {
		for (long long i = 0; i ) {
			for ()
		}
	}
	//scanf("%lld", &T);
	T = 100000;
	while (T --) {
		ans = temp[0] = 0;
		//scanf("%lld", &n);
		n = 8648640;
		/*for (long long i = n; i > 1; i /= minp[i]) {
			if (temp[temp[0]] == minp[i]) cnt[temp[0]] ++;
			else {
				temp[++ temp[0]] = minp[i];
				cnt[temp[0]] = 1;
			}
		}
		g(1, 1);*/
		//printf("%lld\n", ans);
	}
	return 0;
}


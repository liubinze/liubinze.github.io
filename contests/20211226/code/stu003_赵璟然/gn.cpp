#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e7 + 5;

int T;
int prime[N];
int p[100], r[100], d[1005];
ll g[N];
bool mark[N];

void euler(int n) {
	for (int i = 2; i <= n; i++) {
		if (!mark[i]) prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
			mark[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int f(int x) {
	int ans = 0;
	for (int i = 1; i <= prime[0]; i++) {
		if (x % prime[i] != 0) continue;
		int cnt = 0;
		while (x % prime[i] == 0) cnt++, x /= prime[i];
		ans = max(ans, cnt);
	}
	return ans;
}

int main() {
	freopen("gn.in", "r", stdin);
	freopen("gn.out", "w", stdout);
	euler(10000000);
	scanf("%d", &T);
	while (T--) {
		ll ans = 0;
		int n, tot = 0, tot2 = 1;
		scanf("%d", &n);
		int ahh = n;
		for (int i = 1; i <= prime[0]; i++)
			if (n % prime[i] == 0) {
				p[++tot] = prime[i];
				r[tot] = 0;
				while (n % prime[i] == 0) r[tot]++, n /= prime[i];
			}
		d[1] = 1;
		for (int i = 1; i <= tot; i++) {
			ll temp = p[i];
			int lst = tot2;
			for (int j = 1; j <= r[i]; j++, temp *= p[i]) 
				for (int k = 1; k <= lst; k++) {
					d[++tot2] = d[k] * temp;
				}
		}
		for (int i = 1; i <= tot2; i++) {
			ans += d[i] * f(ahh / d[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}


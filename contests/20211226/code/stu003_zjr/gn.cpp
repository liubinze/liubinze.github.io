#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e7 + 5;

int T;
int prime[N], f[N];
int p[100], r[100], d[1005];
ll g[N];
bool mark[N];

void euler(int n) {
	for (int i = 2; i <= n; i++) {
		if (!mark[i]) prime[++prime[0]] = i, f[i] = 1;
		for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
			mark[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				f[i * prime[j]] = f[i] + 1;
				break;
			} else f[i * prime[j]] = f[i] * f[prime[j]];
		}
	}
}

int main() {
	//freopen("gn.in", "r", stdin);
	//freopen("gn.out", "w", stdout);
	euler(10000000);
	scanf("%d", &T);
	while (T--) {
		int n, tot = 0, tot2 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= prime[0]; i++)
			if (n % prime[i] == 0) {
				p[++tot] = prime[i];
				while (n % prime[i] == 0) r[tot]++, n /= prime[i];
			}
		for (int i = 1; i <= tot; i++) printf("%d %d\n", p[i], r[i]);
		d[1] = 1;
		for (int i = 1; i <= tot; i++) {
			ll temp = p[i];
			for (int j = 1; j <= r[i]; j++, temp *= p[i]) 
				for (int k = 1; k <= tot2; k++) {
					d[++tot2] = d[k] * temp;
					printf("%d %d\n", temp, d[k]);
				}
		}
		for (int i = 1; i <= tot2; i++) printf("%d\n", d[i]);
	}
	return 0;
}


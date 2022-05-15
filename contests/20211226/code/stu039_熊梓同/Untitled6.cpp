#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;
int n, idx, p[N], ri[N], pi[N], r1[N], p1[N], zys[N], zs[N], ys[N];
bool vis[N];
int main () {
	freopen ("gn.in", "r", stdin);
	freopen ("gn.out", "w", stdout);
	int T;
	for (int i = 2; i <= N; i ++) {
		if (!vis[i]) {
			idx ++;
			p[idx] = i;
			ri[i] = r1[i] = 1;
			pi[i] = p1[i] = i;
		}
		for(int j = 1; j <= idx && i * p[j] <= N; j ++) {
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
	scanf ("%d", &T);
	while (T --) {
		scanf ("%d", &n);
		int tot = 0;
		int nx = n;
		while(n != 1) {
			zs[tot] = r1[n];
			zys[tot ++] = p1[n];
			for(int i = 1; i <= zs[tot - 1]; i ++) {
				n /= p1[n];
			}
		}
		int m = 0;
		ys[m ++] = 1; 
		for (int i = 0; i < tot; i ++) {
			int range = m, pk = 1;
			for (int j = 1; j <= zs[i]; j ++) {
				pk *= zys[i];
				for(int k = 0; k < range; k ++) {
					ys[m ++] = pk * ys[k];
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < m; i ++) {
			ans += ys[i] * ri[nx / ys[i]];
		}
		cout <<ans << endl;
	}
	return 0;
}

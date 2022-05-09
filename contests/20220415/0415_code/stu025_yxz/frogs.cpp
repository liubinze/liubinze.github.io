#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
inline ll gcd(ll x, ll y) {return !y ? x : gcd(y, x % y);}

ll a[10005];
bool vis[50000005];

int main() {
	freopen("frogs.in", "r", stdin);
	freopen("frogs.out", "w", stdout);
	int n;
	ll m, ans = 0;
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		ll g = gcd(m, a[i]);
		for (ll j = g; j < m; j += g) {
			if (j > 5e7) break;
			vis[j] = true;
		}
	}
	for (ll i = 1; i <= 5e7; i++)
		if (vis[i]) ans += i;
	printf("%lld", ans);
	return 0;
}

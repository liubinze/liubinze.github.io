#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
inline ll Abs(ll x) {return x < 0 ? -x : x;}

struct node {
	ll p, a;
} a[1000005];

int main() {
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	int n, k = 1;
	scanf("%d", &n);
	ll sum = 0, ans = 0, now = 0;
	for (int i = 1; i <= n; i++) scanf("%lld %lld", &a[i].p, &a[i].a), sum += a[i].a;
	sum /= 2;
	sum++;
	for (int i = 1; i <= n; i++) {
		now += a[i].a;
		if (now >= sum) {k = i; break;}
	}
	for (int i = 1; i <= n; i++) ans += Abs(a[k].p - a[i].p) * a[i].a;
	printf("%lld", ans);
	return 0;
}

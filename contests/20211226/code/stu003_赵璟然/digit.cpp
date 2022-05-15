#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

int T;

int f(ll x) {
	if (x % 9 == 0) return 9;
	else return x % 9;
}

int main() {
	freopen("digit.in", "r", stdin);
	freopen("digit.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		ll l, r, ans = 0;
		scanf("%lld %lld", &l, &r);
		while (l % 9 != 0) ans += f(l), l++;
		while (r % 9 != 0) r++, ans -= f(r);
		printf("%lld\n", (r - l) * 4ll + ans + ((r - l) / 9ll + 1ll) * 9ll);
	}
	return 0;
} 

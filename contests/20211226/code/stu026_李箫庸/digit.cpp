#include <bits/stdc++.h>

using namespace std;



long long q, l, r, ans;




int main () {
	freopen("digit.in", "r", stdin);
	freopen("digit.out", "w", stdout);
	scanf("%lld", &q);
	while (q --) {
		scanf("%lld%lld", &l, &r);
		ans = 0;
		for (register int i = 0; i <= 8; i ++) {
			ans += ((r - i) / 9  - (l - i) / 9 + ((l - i) % 9 == 0)) * (i == 0 ? 9 : i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

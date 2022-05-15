#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull q, l, r, cnt;
ull ak(ull a) {
	if(a < 10ULL) return a;
	cnt = 0ULL;
	while(a >= 1ULL) {
		cnt += a % 10ULL;
		a /= 10ULL;
	}
	cnt += a;
	if(cnt >= 10ULL) {
		return ak(cnt);
	}
	return cnt;
}
int main () {
	freopen ("digit.in", "r", stdin);
	freopen ("digit.out", "w", stdout);
//	
	scanf ("%llu", &q);
	while (q --) {
		scanf ("%llu %llu", &l, &r);
		if(l <= 9 && r <= 9) {
			printf("%llu\n", (r - l + 1) * (r + l) / 2);
			continue;
		}
		ull ans = 0;
		for(ull i = l; i <= r;) {
			ull k = i;
			ans += ak(k);
			i ++;
		}	
		printf("%llu\n", ans);
	}
	return 0;
}

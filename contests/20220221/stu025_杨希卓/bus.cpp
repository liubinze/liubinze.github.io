#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f;

int n, m, c, t[100005];

inline bool check(int k) {
	int lst = 1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i - lst + 1 == c) {
			lst = i + 1;
			cnt++;
			if (cnt > m) return false;
			continue;
		}
		if (t[i + 1] - t[lst] > k) {
			lst = i + 1;
			cnt++;
			if (cnt > m) return false;
			continue;
		}
	}
	return true;
}

signed main() {
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &c);
	for (int i = 1; i <= n; i++) scanf("%lld", &t[i]);
	t[n + 1] = inf;
	int l = 0, r = 2e9, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld", ans);
	return 0;
}

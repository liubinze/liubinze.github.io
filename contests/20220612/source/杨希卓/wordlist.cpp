#include <cstdio>
#include <iostream>
using namespace std;

int n, w, a[1000005];

inline bool check(int h) {
	int res = 0;
	for (int i = 1, j = h; i <= n; i += h, j = min(j + h, n)) {
		if (i > n) break;
		int mx = 0;
		for (int k = i; k <= j; k++) mx = max(mx, a[k]);
		if (i + h <= n) mx++;
		res += mx;
		if (res > w) return false;
	}
	return true;
}

int main() {
	freopen("wordlist.in", "r", stdin);
	freopen("wordlist.out", "w", stdout);
	scanf("%d %d", &n, &w);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (n <= 5000) {
		for (int i = 1; i <= n; i++)
			if (check(i)) {printf("%d", i); break;}
		return 0;
	}
	int l = 1, r = n, ans = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d", ans);
	return 0;
}

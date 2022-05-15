#include <stdio.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
const int lim = 1e14;

int n, m;
int a[N];

bool check(int x) {
	int tot = 1, cnt = 0;
	for (int i = 1; i <= m; i++) {
		int sum = a[tot];
		if (sum > x) {
			cnt = 0;
			while (sum > x) {
				sum += a[++tot];
				if (tot > n) return false;
			}
		}
		if (sum <= x) {
			while (sum <= x) {
				sum += a[++tot];
				cnt++;
				if (tot > n) {
					if (cnt >= m - i + 1) return true;
					else return false;
				}
			}
			cnt--;
		}
	}
	if (tot < n) return false;
	else return true;
}

int getans(int l, int r) {
	int ans;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	return ans;
}

signed main() {
	freopen("book.in", "r", stdin);
	freopen("book.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	printf("%lld", getans(-lim, lim));
	return 0;
}
/*
4 2
-2 4 -2 0 
*/

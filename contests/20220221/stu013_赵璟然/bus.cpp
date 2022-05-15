#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;

int n, m, c;
int t[N];

bool check(int x) {
	int cow = 2, tim = t[1], tot = 1, car = 1;
	while (cow <= n) {
		if (t[cow] - tim > x) {
			car++, tot = 1, tim = t[cow];
			cow++;
			if (car > m) return false;
			continue;
		}
		if (tot + 1 > c) {
			tot = 1, car++, tim = t[cow];
			cow++;
			if (car > m) return false;
			continue;
		}
		tot++, cow++;
	}
	return true;
}

int getans(int l, int r) {
	int ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
}

int main() {
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
	sort(t + 1, t + 1 + n);
	printf("%d", getans(0, 1000000000));
	return 0;
}

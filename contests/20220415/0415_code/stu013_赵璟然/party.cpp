#include <stdio.h>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e6 + 5;
const int inf = 1e18;

int n, ans, sum;
int p[N], a[N];

signed main() {
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld %lld", &p[i], &a[i]), sum += a[i];
	for (int i = 2; i <= n; i++) ans += a[i] * (p[i] - p[1]);
	for (int i = 2, cnt = a[1], temp = ans; i <= n; i++) {
		temp -= (sum - cnt) * (p[i] - p[i - 1]);
		temp += cnt * (p[i] - p[i - 1]);
		ans = min(ans, temp);
		cnt += a[i];
	}
	printf("%lld", ans);
	return 0;
}

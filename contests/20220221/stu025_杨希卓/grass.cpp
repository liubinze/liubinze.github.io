#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int inf = 1e18;

int b[100005];

struct node {
	int a, t, z;
} tmp, a[100005];
inline bool cmp(node x, node y) {
	return x.a < y.a;
}
inline bool operator < (node x, node y) {
	return x.z < y.z;
}
priority_queue<node> pq;

signed main() {
	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);
	int n, now = 1, tim = 0, lst = 1, ans = 0;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld %lld", &a[i].a, &a[i].t), a[i].z = n - i + 1;
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) b[i] = a[i].a;
	b[n + 1] = inf;
	while (lst <= n) {
		now = upper_bound(b + 1, b + 2 + n, tim) - b - 1;
		if (pq.empty() && now < lst) tim = a[lst].a;
		now = upper_bound(b + 1, b + 2 + n, tim) - b - 1;
		for (int i = lst; i <= now; i++) pq.push(a[i]);
		tmp = pq.top();
		pq.pop();
		ans = max(ans, tim - tmp.a);
		tim += tmp.t;
		lst = now + 1;
	}
	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();
		ans = max(ans, tim - tmp.a);
		tim += tmp.t;
	}
	printf("%lld", ans);
	return 0;
}

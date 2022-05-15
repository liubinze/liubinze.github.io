#include <stdio.h>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e5 + 5;

int n, tot = 1;

struct cow {
	int a, t, id;
};
cow c[N];

bool cmp(cow a, cow b) {
	return a.a < b.a;
}

bool operator < (cow a, cow b) {
	return a.id > b.id;
}

priority_queue<cow> pq;

int getans() {
	int ans = 0, tim = 0;
	while (tot <= n) {
		int st = tot;
		while (c[st].a == c[tot].a && tot <= n) pq.push(c[tot]), tot++;
		tim = c[st].a;
		while (!pq.empty()) {
			cow x = pq.top();
			pq.pop();
			ans = max(ans, tim - x.a);
			tim += x.t;
//			printf("getnas : %lld %lld %lld\n", tim, x.id, ans);
			while (c[tot].a <= tim && tot <= n) pq.push(c[tot]), tot++;
		}
	}
	return ans;
}

signed main() {
	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &c[i].a, &c[i].t);
		c[i].id = i;
	}
	sort(c + 1, c + 1 + n, cmp);
	printf("%lld", getans());
	return 0;
}


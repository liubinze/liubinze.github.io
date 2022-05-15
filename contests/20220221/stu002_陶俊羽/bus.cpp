#include <bits/stdc++.h>


using namespace std;

int n, m, c;
int t[100003];

bool check(int len) {
	int cnt = 1, begin_ = 0;
	for (register int i = 1; i ^ n; ++ i) {
		if (t[i] - t[begin_] > len || i - begin_ >= c) {
			begin_ = i;
			++ cnt;
		}
	}
	return (cnt <= m);
}

int main() {
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &c);
	for (register int i = 0; i ^ n; ++ i) scanf("%d", &t[i]);
	sort(t, t + n);
	int L = 0, R = 1000000000, mid;
	while (L < R) {
		mid = (L + R) >> 1;
		if (check(mid)) R = mid;
		else L = mid + 1;
	}
	printf("%d", L);
	return 0;
}

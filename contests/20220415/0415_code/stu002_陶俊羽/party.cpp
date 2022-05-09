#include <bits/stdc++.h>

using namespace std;

int n;
long long ans = 0x3f3f3f3f3f3f3f3f, temp = 0;
int p[1000003], a[1000003], sum[1000003];

int main() {
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d %d", &p[i], &a[i]);
		temp += (long long)(p[i] - p[1]) * a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	ans = min(ans, temp);
	for (int i = 1; i ^ n; ++ i) {
		temp += ((sum[i] << 1) - sum[n]) * (p[i + 1] - p[i]);
		ans = min(ans, temp);
	}
	printf("%lld", ans);
	return 0;
}

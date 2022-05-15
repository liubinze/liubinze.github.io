#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], sum[100005];
bool check(int x) {
	//puts("1");
	int i = 1, ans = 0, t = 0;
	while (i <= n) {
		ans += a[i];
		if (ans > x) i++;
		else ans = 0, i++, t++; 
	}
	if (t >= m && ans <= x) return 1;
	else return 0;
}
int main() {
	freopen("book.in", "r", stdin);
	freopen("book.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int l = -1e7, r = 1e7;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid - 1 ;
		else l = mid + 1;
	}
	cout << l << endl;
}

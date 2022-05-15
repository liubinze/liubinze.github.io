#include "iostream"
#include "fstream"
#include "algorithm"

using namespace std;



int n, m, c, t[100007], l, r, ans;

bool check(int x) {
	int Min, ans = 1, Minsub;
	Min = t[1];
	Minsub = 1;
	for (register int i = 1; i <= n; i ++) {
		if (t[i] - Min > x) {
			ans ++;
			Min = t[i];
			Minsub = i;
			i --;
			continue;
		}
		if (i - Minsub >= c) {
			ans ++;
			Min = t[i + 1];
			Minsub = i + 1;
		}
	}
	return (ans <= m);
}




int main () {
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &c);
	l = 1;
	r = n;
	for (register int i = 1; i <= n; i ++) {
		scanf("%d", &t[i]);
	}
	sort(t + 1, t + n + 1);
	t[n + 1] = t[n];
	while (true) {
		
		ans = (l + r) / 2;
		if (check(ans)) {
			r = ans;
		}
		else {
			l = ans + 1;
		}
		if (l >= r)
			break;
	}
	cout << l << endl;
	return 0;
}

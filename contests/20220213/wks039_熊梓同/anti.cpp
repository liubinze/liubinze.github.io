#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int T, k;
ull n;
ull func (ull a) {
	ull x = a & (-a);
	return ((a + x) | ((a ^ (a + x)) / x) >> 2);
}
int main () {
	freopen ("anti.in", "r", stdin);
	freopen ("anti.out", "w", stdout);
	
	scanf ("%d", &T);
	while (T --) {
		cin >> n >> k;
		cout << func (n) << endl;
	}
	return 0;
}

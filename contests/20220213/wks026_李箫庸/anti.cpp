#include <bits/stdc++.h>

using namespace std;



unsigned long long n;
int T, k;

unsigned long long lowbit(unsigned long long n) {
	return n & (-n);
}




int main () {
	freopen("anti.in", "r", stdin);
	freopen("anti.out", "w", stdout);
	cin >> T;
	while (T --) {
		cin >> n >> k;
		if (n + lowbit(n) == 0)
			cout << "18446744073709551616" << endl;
		else
			cout << n + lowbit(n) << endl;
	}
}

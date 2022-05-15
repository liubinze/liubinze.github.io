#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull n, mx, xfs, lowbit, s;
int power;

inline ull sum(ull x, ull y) {
	ull dif = mx - x;
	if (y < dif) return x + y;
	return y - dif - 1;
}

int main() {
	freopen("anti.in", "r", stdin);
	freopen("anti.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		cin >> n >> power;
		mx = 1ll << power - 1;
		mx--;
		mx <<= 1;
		mx++;
		xfs = mx - n + 1;
		lowbit = n & xfs;
		s = sum(n, lowbit);
		cout << (s | ((n ^ s) / lowbit) >> 2) << '\n';
	}
	return 0;
}

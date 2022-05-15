#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T;

unsigned ll ahh(unsigned ll n, unsigned ll k) {
	unsigned ll x = n & -n;
	unsigned ll temp = n + x;
	temp %= (1ull << k);
	unsigned ll ans = (temp | ((n ^ temp) / x) >> 2ull);
	return ans % (1ull << k);
}

int main() {
	freopen("anti.in", "r", stdin);
	freopen("anti.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		unsigned ll n, k;
		cin >> n >> k;
		cout << ahh(n, k) << endl;
	}
	return 0;
}


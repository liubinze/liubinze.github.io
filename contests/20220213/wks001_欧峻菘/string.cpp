#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;
rope<char> c, d;
string s;
int n, m, a[200005], ll;
int main() {
	freopen("string.in", "r", stdin);
	freopen("srring.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		c.push_back(s[i]);
	}
//	cout << c << endl;
	while (m--) {
		d.clear();
		int l, r;
		char t;
		cin >> l >> r >> t;
		ll = 0;
		memset(a, 0, sizeof a);
		for (int i = l - 1; i <= r  -1 ; i++) {
		//	cout << c.at(i);
			if (c[i] == t) a[i] = 1;
		}
		for (int i = 0; i < c.size(); i++) {
			if (a[i] != 1) d .push_back(c[i]);
		}
		c = d;
	//	puts("");
	}
	cout << c << endl;
}


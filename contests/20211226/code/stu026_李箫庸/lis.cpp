#include <bits/stdc++.h>

using namespace std;



vector <int> v[5009];
int n, a[5009], f[5009], g[5009], ans, o;

bool c(int a, int b, int l) {
	for (register int i = 0; i < l; i ++) {
		if (v[a][i] != v[b][i]) {
			return (v[a][i] > v[b][i]);
		}
	}
	return true;
}





int main () {
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
	scanf("%d", &n);
	for (register int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	for (register int i = n; i >= 1; i --) {
		int ln = 0, lin = 0;
		for (register int j = n; j > i; j --) {
			if (a[j] > a[i]) {
				if (ln == f[j]) {
					if (a[lin] >= a[j])
						lin = lin;
					else
						lin = j;
				}
				if (ln < f[j]) {
					lin = j;
					ln = f[j];
				}
			}
		}
		f[i] = ln + 1;
		g[i] = lin;
		int len = v[lin].size();
		for (register int j = 0; j < len; j ++) {
			v[i].push_back(v[lin][j]);
		}
		v[i].push_back(a[i]);
	}
	for (register int i = 1; i <= n; i ++) {
//		cout << v[i].size() << ' ';
		if (f[i] > ans) {
			o = i;
		}
		if (f[i] == ans) {
			if (c(o, i, ans));
			else {
				o = i;
			}
		}
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
//	cout << o << endl;
	for (register int i = ans - 1; i >= 0; i --) {
		cout << v[o][i] << ' ';
	}
	cout << endl;
	return 0;
}

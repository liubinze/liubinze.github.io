#include <bits/stdc++.h>

using namespace std;



int n, m, a[200009], Max;




int main () {
	freopen("book.in", "r", stdin);
	freopen("book.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		Max = max(a[i], Max);
	}
	cout << Max << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;



int n, m, a, b, len;
string S1, S2;
char c;




int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> S1;
	len = n;
	while (m --) {
		scanf("%d %d %c", &a, &b, &c);
		if (a >= len)
			continue;
		for (register int i = 0; i < len; i ++) {
			if (i + 1 >= a && i + 1 <= b && S1[i] == c) {
				len --;
				continue;
			}
			S2 += S1[i];
		}
		S1 = S2;
		S2 = "";
	}
	cout << S1 << endl;
	return 0;
}

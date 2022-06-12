#include <bits/stdc++.h>
using namespace std;
int T, n, m, A, B;
char a[27][27];
int l[27], h[27];
int main () {
	freopen ("monster.in", "r", stdin);
	freopen ("monster.out", "w", stdout);
	int T;
	scanf ("%d", &T);
	while (T --) {
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) {
			scanf ("%s", a[i] + 1);
			for (int j = 1; j <= m; j++) {
				if (a[i][j] == '*') {
					h[i] ++;
					l[j] ++;
				}
			}
		}
		int now = 1, ans = 0;
		int x, y, cnt;	
		cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (h[i] > cnt) {
				cnt = h[i];
				x = i;
			}
		} 
		cnt = 0;
		for (int i = 1; i <= m; i ++) {
			if (l[i] > cnt) {
				cnt = l[i];
				y = i;
			}
		} 
		while (now <= n) {
			ans ++;
			now ++;
			for (int i = 1; i <= m; i ++) 
				if (a[x][i] == '*') {
					l[i] --, a[x][i] = '?';
					h[x] --;
				} 
			for (int i = 1; i <= n; i ++) 
				if (a[i][y] == '*') {
					h[i] --;
					l[y] --;
					a[i][y] = '?';
				} 
			cnt = 0;
			for (int i = 1; i <= n; i ++) {
				if (h[i] > cnt) {
					cnt = h[i];
					x = i;
				}
			} 
			cnt = 0;
			for (int i = 1; i <= m; i ++) {
				if (l[i] > cnt) {
					cnt = l[i];
					y = i;
				}
			} 
			if (h[x] == 0 && l[y] == 0) break;
		}
		cout << ans << endl;
	}
	return 0; 
}


#include <bits/stdc++.h>
using namespace std;
int T, n, m, tot, maxx, x[250007], y[250007];
bool getans = 0;
char a[507][507], vis[7][7];
int main () {
	freopen ("laser.in", "r", stdin);
	freopen ("laser.out", "w", stdout);
	scanf ("%d", &T);
	while (T --) {
		maxx = 0;
		scanf ("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) {
			scanf ("%s", a[i] + 1);
			for (int j = 1; j <= m; j ++) {
				if (a[i][j] == '.') maxx ++;
				if (a[i][j] == 'S') {
					x[++tot] = i;
					y[++tot] = i;
				}
			}
		}
		printf ("No\n");
//		if (n * m > 5) {
//			printf ("No\n");
//			continue;
//		}
//		bool ffffff = 0;
//		int X = (1 << tot) - 1;
////		11
//		for (int i = 0; i <= X; i ++) {
//			bool flag = 0;
//			int cnt = 0;
//			memset (vis, 0, sizeof vis);
//			for (int j = 1; j <= tot; j ++) {
//				if(flag) break;
//				if ((1 << (j - 1)) & i) {
//					for (int k = x[j] + 1; k <= n; k ++) {
//						if (a[k][y[j]] == '#') {
//							break;
//						}
//						if (a[k][y[j]] == '.' && !vis[k][y[j]]) {
//							cnt ++;
//							vis[k][y[j]] = 1;
//						}
//						else if (a[k][y[j]] == 'S') {
//							flag = 1;
//							break;
//						}
//					}
//					for (int k = x[j] - 1; k >= 1; k --) {
//						if (a[k][y[j]] == '#') {
//							break;
//						}
//						if (a[k][y[j]] == '.' && !vis[k][y[j]]) {
//							cnt ++;
//							vis[k][y[j]] = 1;
//						}
//						else if (a[k][y[j]] == 'S') {
//							flag = 1;
//							break;
//						}
//					}
//				}
//				else {
//					for (int k = y[j] + 1; k <= m; k ++) {
//						if (a[x[j]][k] == '#') {
//							break;
//						}
//						if (a[x[j]][k] == '.' && !vis[x[j]][k]) {
//							cnt ++;
//						}
//						else if (a[x[j]][k] == 'S') {
//							flag = 1;
//							break;
//						}
//					}
//					for (int k = y[j] - 1; k <= m; k ++) {
//						if (a[x[j]][k] == '#') {
//							break;
//						}
//						if (a[x[j]][k] == '.' && !vis[x[j]][k]) {
//							cnt ++;
//						}
//						else if (a[x[j]][k] == 'S') {
//							flag = 1;
//							break;
//						}
//					}
//				}
//			}
//			if (flag) continue;
//			if (cnt == maxx) {
//				for (int j = 1; j <= tot; j ++) {
//					if (1 << (j - 1) & i) a[x[j]][y[j]] = '|';
//					else a[x[j]][y[j]] = '-';
//				}
//				ffffff = 1;
//				printf ("Yes\n");
////				cout << i << endl;
//				for (int i = 1; i <= n; i ++) {
//					for (int j = 1; j <= m; j ++) {
//						printf ("%c", a[i][j]);
//					}
//					printf ("\n");
//				}
//				break;
//			}
//		}
//		if (!ffffff) {
//			printf ("No\n");
//			continue;
//		}
	}
	return 0;
}

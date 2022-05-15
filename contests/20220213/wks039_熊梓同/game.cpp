#include <bits/stdc++.h>
using namespace std;
int T, n, k, ans[37], mark[37];
int main () {
	freopen ("game.in", "r", stdin);
	freopen ("game.out", "w", stdout);	
	scanf ("%d", &T);
	for (int i = 1, j = 1; i <= 1e9; i *= 2, j ++) {
		ans[j] = i;
//		cout << j << " " << ans[j] << endl; 
	}
	ans[31] = ans[30] * 2;
//	cout << 31 << " " << ans[31] << endl; 
	
	while (T --) {
		scanf ("%d %d", &n, &k);
		if (k == 0) {
			printf ("YES\n0\n");
			continue;
		} 
		else if (k % 2 == 0) {
			printf ("NO\n");
			continue;
		}
		int cnt = 0, m;
		for (int i = 1; ; i ++) {
			cnt += ans[i];
			if (cnt >= k) {
				m = i;
				break;
			}
		}
//		cout << cnt << " " << m <<endl;
		if (cnt == k) {
			int tot = 1;
			printf ("YES\n%d\n", cnt);
			for (int i = 1; i <= m; i ++) {
				printf ("%d ", tot);
				tot += ans[i];
			}
			printf ("\n");
		}
		else if ((cnt - k) / 2 + k > n) {
			printf ("NO\n");
		}
		else {
			printf ("YES\n%d\n", cnt);
			memset (mark, 0, sizeof (mark));
			int g = (cnt - k) / 2;
			int x = upper_bound (ans + 1, ans + 32, g) - ans;
			for (int i = x; i >= 1; i --) {
				if (g >= ans[i]) {
					mark[i] ++;
					g -= ans[i];
				}
			}
			int y = k + 1;
			x = 1;
			for (int i = 1; i <= m; i ++) {
				if (mark[i]) {
					printf ("%d ", y);
					y += ans[i];
				}
				else {
					printf ("%d ", x);
					x += ans[i];
				}
			}
			printf ("\n");
		}
	}
	return 0;
}

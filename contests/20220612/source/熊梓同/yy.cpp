#include <bits/stdc++.h>
using namespace std;
int T, n, m, ans, book[23];
bool vis[23], g[23][23];

void init(){
	ans = 1e9 + 7;
	memset (book, 0, sizeof book);
	memset (vis, 0, sizeof vis);
	memset (g, 0, sizeof g);
}

void dfs (int x, int cnt, int step) {
	if (step == n * 2) {
		if (g[1][x] == 1) {
			book[1] ++;
			cnt += 1;
			if (book[1] > 1) cnt --;
		}
		ans = min (ans, cnt);
		cout << ans << endl;
		return;
	}
	if (cnt >= ans) {
		return;
	}
	if (x <= n) {
		for (int i = n + 1; i <= n * 2; i ++) {
			if (vis[i]) continue;
			vis[i] = 1;
			if (g[i][x] == 1) {
				book[x] ++;
				cnt ++;
				if (book[x] > 1) cnt --;
			}
			dfs (i, cnt, step + 1);
			vis[i] = 0;
			if (g[i][x] == 1) {
				book[x] --;
				if (book[x] == 0) cnt --;
			}
		}
	}
	else {
		for (int i = 1; i <= n; i ++) {
			if (vis[i]) continue;
			vis[i] = 1;
			if (g[i][x] == 1) {
				book[i] ++;
				cnt += 1;
				if (book[i] > 1) cnt --;
			}
			dfs (i, cnt, step + 1);
			vis[i] = 0;
			if (g[i][x] == 1) {
				book[i] --;
				if (book[i] == 0) cnt --;
			}
		}
	}
}
int main () {
	freopen ("yy.in", "r", stdin);
	freopen ("yy.out", "w", stdout);
	int T;
	scanf ("%d", &T);
	while (T --) {
		scanf ("%d %d", &n, &m);
		init ();
		for (int i = 1; i <= m; i ++) {
			int x, y;
			scanf ("%d %d", &x, &y);
			g[x][y + n] = 1;
			g[y + n][x] = 1;
		}
		
//		for (int i = 1; i <= n; i ++) {
//			for (int j = 1; j <= n; j ++) {
//				cout << g[i][j] << " ";
//			}
//			cout << endl;
//		}
		vis[1] = 1;
		dfs (1, 0, 1);
		cout << ans << endl;
	}
	return 0; 
}
//2 
//2 1 
//1 1 
//3 4 
//1 1 
//1 2 
//1	3 
//2	1


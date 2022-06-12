#include <bits/stdc++.h>
using namespace std;

int T, n, m;
char a[30][30];
int sumh[30], sums[30];

int main() {
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout); 
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) cin >> a[i][j];
		}
		int maxn = 0;
		while (1) {
			memset(sumh, 0, sizeof sumh);
			memset(sums, 0, sizeof sums);
			
			int ok = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (a[i][j] == '.') ok = 1;
					else {
						ok = 0;
						break;
					}
				}
				if (ok == 0) break;
			}
			if (ok == 1) break;
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= m; j++) {
//					cout << a[i][j];
//				}
//				puts("");
//			}
//			puts("");
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (a[i][j] == '*') sumh[i]++;
				}
			}
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					if (a[j][i] == '*') sums[i]++;
				} 
			}
		
			int res = 0, idi = 0, idj = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if ((sumh[i] + sums[j] - (a[i][j] == '*') ) >= res) {
						res = (sumh[i] + sums[j] - (a[i][j] == '*'));
						idi = i, idj = j;
					}
				}
			}
			for (int j = 1; j <= m; j++) a[idi][j] = '.';
			for (int i = 1; i <= n; i++) a[i][idj] = '.';
			maxn++;
			
 		}
 		cout << maxn << endl;
	}
}

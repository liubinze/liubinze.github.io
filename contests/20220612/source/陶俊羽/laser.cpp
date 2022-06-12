#include <bits/stdc++.h>

using namespace std;

int T, n, m;
char ch[503][503];
char cs[2] = {'-', '|'};

int main() {
		freopen("laser.in", "r", stdin);
	freopen("laser.out", "w", stdout);
	srand((int)time(NULL));
	scanf("%d", &T);
	while (T --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++ i) {
			scanf("%s", ch[i] + 1);
			for (int j = 1; j <= m; ++ j) {
				if (ch[i][j] == 's') ch[i][j] = cs[rand() % 2];
			}
		}
		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= m; ++ j) {
				cout << ch[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}

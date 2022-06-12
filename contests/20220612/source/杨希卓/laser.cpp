#include <cstdio>
#include <iostream>
using namespace std;

int n, m, tot;
char s[505][505];
bool vis[505][505], mark[505][505];

inline bool check(int sta) {
	int now = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) vis[i][j] = false;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mark[i][j]) {
				if (sta >> now - 1 & 1) s[i][j] = '|';
				else s[i][j] = '-';
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '-') {
				for (int k = j - 1; k; k--) {
					if (s[i][k] == '#') break;
					vis[i][k] = true;
				}
				for (int k = j + 1; k <= m; k++) {
					if (s[i][k] == '#') break;
					vis[i][k] = true;
				}
			}
			if (s[i][j] == '|') {
				for (int k = i - 1; k; k--) {
					if (s[k][j] == '#') break;
					vis[k][j] = true;
				}
				for (int k = i + 1; k <= n; k++) {
					if (s[k][j] == '#') break;
					vis[k][j] = true;
				}
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '.' && !vis[i][j]) return false;
	puts("Yes");
	for (int i = 1; i <= n; i++, puts(""))
		for (int j = 1; j <= m; j++) putchar(s[i][j]);
	return true;
}

int main() {
	freopen("laser.in", "r", stdin);
	freopen("laser.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
		tot = 0;
		bool fl = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) mark[i][j] = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				if (s[i][j] == 'S') {
					bool fl1 = true, fl2 = true;
					for (int k = j - 1; k; k--) {
						if (s[i][k] == '#') break;
						if (s[i][k] == 'S' || s[i][k] == '-' || s[i][k] == '|') {fl1 = false; break;}
					}
					for (int k = j + 1; k <= m; k++) {
						if (s[i][k] == '#') break;
						if (s[i][k] == 'S' || s[i][k] == '-' || s[i][k] == '|') {fl1 = false; break;}
					}
					for (int k = i - 1; k; k--) {
						if (s[k][j] == '#') break;
						if (s[k][j] == 'S' || s[k][j] == '-' || s[k][j] == '|') {fl2 = false; break;}
					}
					for (int k = i + 1; k <= n; k++) {
						if (s[k][j] == '#') break;
						if (s[k][j] == 'S' || s[k][j] == '-' || s[k][j] == '|') {fl2 = false; break;}
					}
					if (!fl1 && !fl2) {fl = false; break;}
					if (!fl1) s[i][j] = '|';
					if (!fl2) s[i][j] = '-';
					if (fl1 && fl2) tot++, mark[i][j] = true;
				}
			if (!fl) break;
		}
		if (!fl) {puts("No"); continue;}
		fl = false;
		for (int i = 0; i < 1 << tot; i++)
			if (check(i)) {fl = true; break;}
		if (!fl) puts("No");
	}
	return 0;
}

#include <stdio.h>
#include <cstring>
using namespace std;
const int N = 505;

int T, n, m, tot;
char mp[N][N], mp2[N][N];

struct las {
	int x, y;
};
las l[N];

bool check(int sta) {
	memcpy(mp, mp2, sizeof(mp2));
	for (int i = 1; i <= tot; i++)
		if (sta >> (i - 1) & 1) {
			for (int j = l[i].y - 1; j; j--) {
				if (mp[l[i].x][j] == 'S') return false;
				if (mp[l[i].x][j] == '#') break;
				mp[l[i].x][j] = 'B';
			}
			for (int j = l[i].y + 1; j <= m; j++) {
				if (mp[l[i].x][j] == 'S') return false;
				if (mp[l[i].x][j] == '#') break;
				mp[l[i].x][j] = 'B';
			}
		} else {
			for (int j = l[i].x - 1; j; j--) {
				if (mp[j][l[i].y] == 'S') return false;
				if (mp[j][l[i].y] == '#') break;
				mp[j][l[i].y] = 'B';
			} 
			for (int j = l[i].x + 1; j <= n; j++) {
				if (mp[j][l[i].y] == 'S') return false;
				if (mp[j][l[i].y] == '#') break;
				mp[j][l[i].y] = 'B';
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mp[i][j] == '.') return false;
	return true;
}

int main() {
	freopen("laser.in", "r", stdin);
	freopen("laser.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		bool flag = false;
		tot = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)	
				if (mp[i][j] == 'S') l[++tot].x = i, l[tot].y = j;
		if (tot <= 10) {
			memcpy(mp2, mp, sizeof(mp2));
			for (int sta = 0; sta < (1 << tot); sta++) {
				if (!check(sta)) continue;
				flag = true;
				puts("YES");
				for (int i = 1; i <= tot; i++)
					if (sta >> (i - 1) & 1) mp2[l[i].x][l[i].y] = '-';
					else mp2[l[i].x][l[i].y] = '|';
				for (int i = 1; i <= n; i++, puts(""))
					for (int j = 1; j <= m; j++)
						putchar(mp2[i][j]);
				break;
			}
			if (!flag) puts("NO");
			continue;
		}
		bool getans = false;
		for (int i = 1; i <= tot; i++) {
			bool flag1 = false, flag2 = false;
			if (n == 1) flag2 = true;
			if (m == 1) flag1 = true;
			for (int k = l[i].y - 1; k; k--) {
				if (mp[l[i].x][k] == 'S' || mp[l[i].x][k] == '-' || mp[l[i].x][k] == '|') {
					flag1 = true;
					break;
				}
				if (mp[l[i].x][k] == '#') break;
			}
			if (!flag1) {
				for (int k = l[i].y + 1; k <= m; k++) {
					if (mp[l[i].x][k] == 'S' || mp[l[i].x][k] == '-' || mp[l[i].x][k] == '|') {
						flag1 = true;
						break;
					}
					if (mp[l[i].x][k] == '#') break;
				}
			}
			for (int k = l[i].x - 1; k; k--) {
				if (mp[k][l[i].y] == 'S' || mp[k][l[i].y] == '-' || mp[k][l[i].y] == '|') {
					flag2 = true;
					break;
				}
				if (mp[k][l[i].y] == '#') break;
			}
			if (!flag2) {
				for (int k = l[i].x + 1; k <= n; k++) {
					if (mp[k][l[i].y] == 'S' || mp[k][l[i].y] == '-' || mp[k][l[i].y] == '|') {
						flag2 = true;
						break;
					}
					if (mp[k][l[i].y] == '#') break;
				}
			}
//			printf("%d %d %d %d\n", flag1, flag2, l[i].x, l[i].y);
			if (flag1 && flag2) {
				getans = true;
				puts("NO");
				break;
			}
			if (flag1) mp[l[i].x][l[i].y] = '|';
			if (flag2) mp[l[i].x][l[i].y] = '-';
		}
		for (int i = 1; i <= n && !getans; i++)
			for (int j = 1; j <= m && !getans; j++) {
				if (mp[i][j] != '.') continue;
				bool flag1 = false, flag2 = false, done = false;
				for (int k = j - 1; k; k--)
					if (mp[i][k] == '-') {
						done = true;
						break;
					} else if (mp[i][k] == 'S') {
						mp[i][k] = '-';
						done = true;
						break;
					} else if (mp[i][k] == '#') break;
				if (done) continue;
				for (int k = j + 1; k; k++)
					if (mp[i][k] == '-') {
						done = true;
						break;
					} else if (mp[i][k] == 'S') {
						done = true;
						mp[i][k] = '-';
						break;
					} else if (mp[i][k] == '#') break;
				if (done) continue;
				for (int k = i - 1; k; k--)
					if (mp[k][j] == '|') {
						done = true;
						break;
					} else if (mp[k][j] == 'S') {
						mp[k][j] = '|';
						done = true;
						break;
					} else if (mp[i][k] == '#') break;
				if (done) continue;
				for (int k = i + 1; k <= n; k++)
					if (mp[k][j] == '|') {
						done = true;
						break;
					} else if (mp[k][j] == 'S') {
						mp[k][j] = '|';
						done = true;
						break;
					} else if (mp[i][k] == '#') break;
				if (!done) {
					puts("NO");
					getans = true;
					break;
				}
			}
		if (!getans) {
			puts("YES");
			for (int i = 1; i <= n; i++, puts(""))
				for (int j = 1; j <= m; j++) {
					if (mp[i][j] == 'S') mp[i][j] = '-';
					putchar(mp[i][j]);
				}
		}
	}
	return 0;
}


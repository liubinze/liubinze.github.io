#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

int n, K;
char s[105][15], t[105][15];

inline int id(int x, int y) {return (x - 1) * 10 + y;}

int fa[1005], siz[1005];
inline void init(int n) {
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
}
inline int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
inline void merge(int u, int v) {
	int fx = find(u), fy = find(v);
	if (fx != fy) fa[fx] = fy, siz[fy] += siz[fx];
}

inline void drop() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 10; j++) s[i][j] = '0';
	for (int i = 1; i <= 10; i++) {
		int k = n;
		for (int j = n; j; j--)
			if (t[j][i] != '0') s[k--][i] = t[j][i];
	}
}

inline bool check() {
	init(n * 10);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 10; j++)
			for (int k = 0; k < 2; k++) {
				int tx = i + dx[k], ty = j + dy[k];
				if (tx <= n && ty <= 10 && s[i][j] == s[tx][ty]) merge(id(i, j), id(tx, ty));
			}
	bool flag = false;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 10; j++) t[i][j] = '0';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 10; j++) {
			if (s[i][j] == '0') continue;
			int fx = find(id(i, j));
			if (siz[fx] >= K) t[i][j] = '0', flag = true;
			else t[i][j] = s[i][j];
		}
	return flag;
}

inline void work() {
	while (1) {
		bool fl = check();
		if (!fl) break;
		drop();
	}
}

int main() {
	freopen("mooyo.in", "r", stdin);
	freopen("mooyo.out", "w", stdout);
	scanf("%d %d", &n, &K);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	work();
	for (int i = 1; i <= n; i++) printf("%s\n", s[i] + 1);
	return 0;
}

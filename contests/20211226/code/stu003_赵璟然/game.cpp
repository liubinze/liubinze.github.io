#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
#define make make_pair
#define pii pair<int, int>
#define ll long long
using namespace std;
const int N = 35, M = 35;
const int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1};
const char ahh[5] = {'N', 'U', 'R', 'D', 'L'};

int n, m, sx, sy, tx, ty, fk;
char mp[N][M];
pii to[N][M][5];
bool mark[N][M][5];

struct node {
	int x, y, k;
};
queue<node> q;

node from[N][M][5];

bool bfs() {
	while (!q.empty()) {
		node x = q.front();
		q.pop();
		//printf("%d\n", q.size());
		for (int i = 1; i <= 4; i++) {
			if (i + x.k == 4) continue;
			//int nx = x.x + dx[i], ny = x.y + dy[i];
			int nx = to[x.x][x.y][i].first, ny = to[x.x][x.y][i].second;
			if (nx == -1) continue;
			if (nx == tx && ny == ty) {
				from[tx][ty][i] = (node) {x.x, x.y, i};
				fk = i;
				return true;
			}
			if (mark[nx][ny][i]) continue;
			mark[nx][ny][i] = true;
			from[nx][ny][i] = (node) {x.x, x.y, i};
			q.push((node) {nx, ny, i});
			printf("ahh : %d %d\n", nx, ny);
		}
	}
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (mp[i][j] == '#') continue;
			if (mp[i][j] == 'S') sx = i, sy = j;
			if (mp[i][j] == 'T') tx = i, ty = j;
			int x = i, y = j;
			for (int k = 1; k <= 4; k++) {
				x += dx[k], y += dy[k];
				if (mp[x][y] != '#' && mp[x][y] != 'S') to[i][j][k] = make(x, y);
				if (x > n || x < 1 || y > m || y < 1) to[i][j][k] = make(-1, -1);
			}
		}
	for (int i = 1; i <= 4; i++) q.push((node) {sx, sy, i}), mark[sx][sy][i] = true;
	puts("ready");
	printf("%d %d %d %d\n", to[sx][sy][1].first, to[sx][sy][1].second, to[sx][sy][2].first, to[sx][sy][2].second);
	bool flag = bfs();
	if (!flag) puts("NO");
	else {
		puts("YES");
		int x = tx, y = ty, k = fk;
		while (x != sx || y != sy) {
			printf("%c", ahh[from[x][y][k].k]);
			x = from[x][y][k].x, y = from[x][y][k].y, k = from[x][y][k].k;
		}
	}
	return 0;
}


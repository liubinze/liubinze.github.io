#include <stdio.h>
#include <map>
#include <cstring>
#include <queue>
#define pii pair<int, int>
#define make make_pair
using namespace std;
const int N = 1e3 + 5;
const int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1};

int n, k;
char mp[N][N];
bool mark[N][N];
queue<pii> q, q1, q2;

void update() {
	for (int i = 1; i <= 10; i++) {
		int lst = n;
		while (mp[lst][i] != '0') lst--;
		if (lst == 0) continue;
		for (int j = lst - 1; j >= 1; j--) 
			if (mp[j][i] != '0') 
				mp[lst][i] = mp[j][i], mp[j][i] = '0', lst--;
	}
}

void print() {
	for (int i = 1; i <= n; i++) printf("%s\n", mp[i] + 1);
	puts("");
}

bool bfs() {
	bool flag = false;
	while (!q.empty()) q.pop();
	memset(mark, false, sizeof(mark));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 10; j++) {
			if (mark[i][j] || mp[i][j] == '0') continue;
			bool flag1 = false;
			int cnt = 1;
			q1.push(make(i, j));
			//printf("title : %d %d %d\n", i, j, mp[i][j] - '0');
			mark[i][j] = true;
			while (!q2.empty()) q2.pop();
			q2.push(make(i, j));
			while (!q1.empty()) {
				pii x = q1.front();
				q1.pop();
				for (int p = 1; p <= 4; p++) {
					int tx = x.first + dx[p], ty = x.second + dy[p];
					if (tx < 1 || tx > n || ty < 1 || ty > 10 || mp[tx][ty] != mp[x.first][x.second] || mark[tx][ty]) continue;
					cnt++;
					mark[tx][ty] = true;
					if (cnt >= k) flag1 = true;
					q1.push(make(tx, ty)), q2.push(make(tx, ty));
					//printf("%d %d %d\n", tx, ty, cnt);
				}
			}
			//puts("");
			if (flag1) {
				flag = true;
				while (!q2.empty()) {
					mp[q2.front().first][q2.front().second] = '0';
					//printf("%d %d\n", q2.front().first, q2.front().second);
					q2.pop();
				}
			}
		}
	return flag;
}

int main() {
	freopen("mooyo.in", "r", stdin);
	freopen("mooyo.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
	while (bfs()) {
		//print();
		update();	
		//print();
	}
	print();
	return 0;
}
/*
3 0
1111111111
1100000000
0000000000
*/

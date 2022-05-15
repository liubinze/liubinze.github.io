#include <bits/stdc++.h>

using namespace std;

long long b[41];
int T;
int n, k;

queue<int> q;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	b[0] = 1;
	for (int i = 1; i <= 37; i ++) b[i] = b[i - 1] * 2;
	scanf("%d", &T);
	while (T --) {
		scanf("%d %d", &n, &k);
		if (!(k & 1) && k) printf("NO\n");
		else if (k == 0) printf("YES\n0\n");
		else {
			while (!q.empty()) q.pop();
			int pos = 0, pos_ = 0, m = (n >> 1), nn = upper_bound(b, b + 37, n) - b - 1;
			printf("YES\n%d\n", nn + 1);
			for (int i = 1, j = 1; i <= m; i <<= 1, ++ j) {
				if (!((k >> j) & 1)) q.push(i);
				else {
					pos_ = i;
					while (!q.empty()) {
						printf("%d ", (pos + pos_) - q.front() + 1);
						pos_ -= q.front();
						q.pop();
					}
					printf("%d ", pos + 1);
					pos += i;
				}
			}
			pos_ = (int)(pow(2, nn));
			while (!q.empty()) {
				printf("%d ", (pos + pos_) - q.front() + 1);
				pos_ -= q.front();
				q.pop();
			}
			printf("%d\n", pos + 1);
		}
	}
	return 0;
}

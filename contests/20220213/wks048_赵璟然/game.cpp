#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
const int N = 1e6 + 5;
const int lim = 1e9;

int T;
int n, k, tot;
int a[N];
queue<int> q;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &T);
	for (int temp = 2; temp <= lim; temp <<= 1) a[++tot] = temp - 1;
	while (T--) {
		scanf("%d %d", &n, &k);
		if (k == 0) {
			puts("YES\n0");
			continue;
		}
		if (k % 2 == 0) {
			puts("NO");
			continue;
		}
		while (!q.empty()) q.pop();
		bool flag = false;
		for (int st = 0, temp = 1; st <= n; temp <<= 1, st++) {
			for (int j = st + 1; j <= tot; j++)
				if (a[j] - a[st] == k) {
					int name = temp, ans = 1;
					flag = true;
					while (ans < k) {
						q.push(ans);
						ans += name;
						name <<= 1;
					}
				}
			if (flag) break;
		}
		if (!flag) puts("NO");
		else {
			printf("YES\n%d\n", q.size());
			while (!q.empty()) {
				printf("%d ", q.front());
				q.pop();
			}
			puts("");
		}
	}
	return 0;
}


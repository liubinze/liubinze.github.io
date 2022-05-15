#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, K, tot = 0, cnt = 0, power = 1, tmp;
		scanf("%d %d", &n, &K);
		tmp = n - K;
		if (!K) {puts("YES\n0"); continue;}
		while (tot < K) {
			tot += power;
			cnt++;
			power <<= 1;
		}
		if (tot == K) {
			puts("YES");
			printf("%d\n", cnt);
			int pos = 1, power = 1;
			while (pos <= K) {
				printf("%d ", pos);
				pos += power;
				power <<= 1;
			}
			puts("");
			continue;
		}
		tot = cnt = 0;
		power = 1;
		while (tot < tmp) {
			tot += power;
			cnt++;
			power <<= 1;
		}
		if (tot != tmp) {puts("NO"); continue;}
		tot = 0;
		while (tot < n) {
			tot += power;
			cnt++;
			power <<= 1;
		}
		if (tot == n) {
			puts("YES");
			printf("%d\n", cnt);
			int pos = K + 1, power = 1;
			while (pos <= n) {
				printf("%d ", pos);
				pos += power;
				power <<= 1;
			}
			pos = 1;
			while (pos <= n) {
				printf("%d ", pos);
				pos += power;
				power <<= 1;
			}
			puts("");
			continue;
		}
		puts("NO");
	}
	return 0;
}

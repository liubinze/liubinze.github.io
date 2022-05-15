#include <bits/stdc++.h>

using namespace std;



int ans[107], len;
int T, n, k;




int main () {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	for (register long long i = 1; i <= 1e9; i *= 2) {
		ans[++ len] = i - 1;
	}
	scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &n, &k);
		for (register int i = 1; i <= len; i ++) {
			if (ans[i] == k) {
				printf("YES\n");
				printf("%d\n", i - 1);
				for (register int j = 1; j < i; j ++)
					printf("%d ", ans[j] + 1);
				if (i > 1)
					printf("\n");
				goto r;
			}
		}
		printf("NO\n");
	r:	;
	}
	return 0;
}

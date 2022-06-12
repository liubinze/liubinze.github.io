#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 625;
const int inf = 0x3f3f3f3f;

int T, n, m, ans;
char mp[25][25];
bool mark1[N], mark2[N];

int check(int a, int b) {
	int cnt1 = 0, cnt2 = 0;
	memset(mark1, false, sizeof(mark1));
	memset(mark2, false, sizeof(mark2));
	for (int i = 1; i <= n; i++)
		if (a >> (i - 1) & 1) mark1[i] = true, cnt1++;
	for (int i = 1; i <= m; i++)
		if (b >> (i - 1) & 1) mark2[i] = true, cnt2++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mp[i][j] == '*' && !mark1[i] && !mark2[j]) return inf;
	return max(cnt1, cnt2);
}

int main() {
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		ans = inf;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
		for (int i = 0; i <= (1 << n); i++)
			for (int j = 0; j <= (1 << m); j++) 
				ans = min(ans, check(i, j));
		printf("%d\n", ans);
	}
	return 0;
}

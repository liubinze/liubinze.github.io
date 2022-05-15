#include <iostream>
const int N = 1e2;
int t;
int n, m;
int ans[N + 5], idx;
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &t);
	while (t -- )
	{
		scanf("%d%d", &n, &m);
		if (!m)
		{
			puts("YES");
			puts("0");
			continue;
		}
		if (n & 1)
		{
			int cnt = 0, id = 1, tmp = 1;
			while (n > (tmp << 1)) tmp <<= 1;
			while (tmp)
			{
				ans[ ++ idx] = id;
				id += tmp;
				n -= tmp;
				if (n < 0)
				{
					id += n;
					n = -n;
					cnt += n;
				}
				tmp >>= 1;
			}
			if (m < cnt) puts("NO");
			else
			{
				printf("%d\n", idx);
				for (int i = idx; i >= 1; i -- ) printf("%d ", ans[i]);
				puts("");
			}
		}
		else puts("NO");
	}
	return 0;
}

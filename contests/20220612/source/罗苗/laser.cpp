#include <iostream>
#include <cstring>
#include <vector>
const int N = 5e2;
int t;
int n, m;
char c[N + 5][N + 5];
int f[N + 5][N + 5];
int link[2 * N * N + 5];
int id[N * N + 5];
bool vis[2 * N * N + 5];
int a[N + 5][N + 5];
int idx;
std :: vector<int> e1[N + 5], e2[N + 5];
struct node
{
	int v;
	int id;
} ;
std :: vector<node> g[N + 5];
int find(int u)
{
    for (auto i : g[u])
    {
        if (vis[i.v]) continue;
        vis[i.v] = 1;
        if (!link[i.v] || find(link[i.v]))
		{
			link[i.v] = u;
			id[i.v] = i.id;
			return 1;
		}
    }
    return 0;
}
bool work1(int i, int j)
{
	if (e1[j].size() == 0)
	{
		e1[j].push_back(i);
		return 1;
	}
	int t = e1[j][e1[j].size() - 1];
	bool flg = 0;
	for (int k = t; k <= i; k ++ )
		if (c[k][j] == '#')
		{
			flg = 1;
			break;
		}
	if (flg)
	{
		if (e1[j].size() > 1)
			for (auto k : e1[j])
			{
				if (f[k][j] != -1) return 0;
				f[k][j] = 0;
				c[i][j] = '#';
			}
		e1[j].clear();
	}
	e1[j].push_back(i);
	return 1;
}
bool work2(int i, int j)
{
	if (e2[i].size() == 0)
	{
		e2[i].push_back(j);
		return 1;
	}
	int t = e2[i][e2[i].size() - 1];
	bool flg = 0;
	for (int k = t; k <= j; k ++ )
		if (c[i][k] == '#')
		{
			flg = 1;
			break;
		}
	if (flg)
	{
		if (e2[i].size() > 1)
			for (auto k : e2[i])
			{
				if (f[i][k] != -1) return 0;
				f[i][k] = 1;
				c[i][j] = '#';
			}
		e2[i].clear();
	}
	e2[i].push_back(j);
	return 1;
}
void work3(int i, int j)
{
	if (f[i][j] == 0)
	{
		int k = j - 1;
		while (1 <= k && c[i][k] != '#') a[i][k -- ] = 0;
		k = j + 1;
		while (k <= m && c[i][k] != '#') a[i][k ++ ] = 0;
	}
	else
	{
		int k = i - 1;
		while (1 <= k && c[k][j] != '#') a[k -- ][j] = 0;
		k = i + 1;
		while (k <= n && c[k][j] != '#') a[k ++ ][j] = 0;
	}
}
void work4(int i, int j)
{
	idx ++ ;
	int k = i - 1;
	while (1 <= k && c[k][j] != '#') 
	{
		if (c[k][j] == 'S')
			g[n * m + idx].push_back({k * m + j, 1});
		k -- ;
	}
	k = i + 1;
	while (k <= n && c[k][j] != '#')
	{
		if (c[k][j] == 'S')
			g[n * m + idx].push_back({k * m + j, 1});
		k ++ ;
	}
	k = j - 1;
	while (1 <= k && c[i][k] != '#')
	{
		if (c[i][k] == 'S')
			g[n * m + idx].push_back({i * m + k, 0});
		k -- ;
	}
	k = j + 1;
	while (k <= m && c[i][k] != '#')
	{
		if (c[i][k] == 'S')
			g[n * m + idx].push_back({i * m + k, 0});
		k ++ ;
	}
}
int main()
{
	freopen("laser.in", "r", stdin);
	freopen("laser.out", "w", stdout);
	scanf("%d", &t);
	while (t -- )
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i ++ ) scanf("\n%s", c[i] + 1);
		idx = 0;
		std :: memset(f, -1, sizeof f);
		std :: memset(a, -1, sizeof a);
		std :: memset(link, 0, sizeof link);
		for (int i = n * m + 1; i <= 2 * n * m; i ++ ) g[i].clear();
		for (int i = 1; i <= n; i ++ ) e2[i].clear();
		for (int i = 1; i <= m; i ++ ) e1[i].clear();
		bool flg = 1;
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				if (c[i][j] == 'S')
				{
					a[i][j] = 0;
					if (!work1(i, j))
					{
						flg = 0;
						break;
					}
					if (!work2(i, j))
					{
						flg = 0;
						break;
					}
				}
				else if (c[i][j] == '.') a[i][j] = 1;
		for (int i = 1; i <= n; i ++ )
			if (e2[i].size() > 1)
				for (auto j : e2[i])
				{
					if (f[i][j] != -1)
					{
						flg = 0;
						break;
					}
					f[i][j] = 1;
					c[i][j] = '#';
				}
		for (int j = 1; j <= m; j ++ )
			if (e1[j].size() > 1)
				for (auto i : e2[j])
				{
					if (f[i][j] != -1)
					{
						flg = 0;
						break;
					}
					f[i][j] = 0;
					c[i][j] = '#';
				}
		if (!flg)
		{
			puts("No");
			continue;
		}
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				if (f[i][j] != -1)
					work3(i, j);
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= m; j ++ )
				if (a[i][j] == 1)
					work4(i, j);
		int cnt = 0;
		for (int i = n * m + 1; i <= n * m + idx; i ++ )
		{
			std :: memset(vis, 0, sizeof vis);
			cnt += find(i);
		}
		if (cnt < idx) puts("No");
		else
		{
			puts("Yes");
			for (int i = 1; i <= n; i ++ )
			{
				for (int j = 1; j <= m; j ++ )
					if (f[i][j] == 1)
						printf("|");
					else if (f[i][j] == 0)
						printf("-");
					else if (c[i][j] == 'S')
						printf("%c", (id[i * m + j]) ? '|' : '-');
					else printf("%c", c[i][j]);
				puts("");
			}
		}
	}
	return 0;
}

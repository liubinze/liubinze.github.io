#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long

int n, m;
namespace Subtask1 {
	struct Line {
		int u, v, w;
		inline bool operator < (const Line a) const {return w > a.w;}
	} e[200005];
	int fa[200005], sze[200005];
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	
	void solve() {
		for (int i = 1; i <= n; ++ i) fa[i] = i, sze[i] = 1;
		for (int i = 1; i <= m; ++ i)
			scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
		std::sort(e + 1, e + m + 1);
		int ans = 0ll;
		for (int i = 1; i <= m; ++ i) {
			int x = find(e[i].u), y = find(e[i].v);
			ans += sze[x] * sze[y] * e[i].w;
			sze[x] += sze[y], fa[y] = x;
		}
		printf("%lld", ans);
	}
}

/*namespace Subtask2 {
	struct Edge {int to, nxt, w;} e[200005];
	struct Line {
		int u, v, w;
		inline bool operator < (const Line a) const {return w > a.w;}
	} edge[100005];
	int fa[100005], head[100005], p[100005], a[100005], sze[100005];
	int len, cnt, tot, n, m, ed, ans;
	bool Incircle[100005], vis[100005];
	std::vector<int> vec[100005];
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	inline void AddEdge(int u, int v, int w) {
		e[++ tot].to = v, e[tot].w = w, e[tot].nxt = head[u];
	}
	
	inline void merge(int u, int v) {
		
	}
	void dfs(int u, int fa) {
		if (u == ed) {Incircle[ed] = true; p[cnt = 1] = ed; return;}
		for (int i = head[u]; i; i = e[i].nxt)
			if (e[i].to != fa) {
				dfs(e[i].to, u);
				if (Incircle[e[i].to])
					Incircle[u] = true, a[cnt] = e[i].w, p[++ cnt] = u;
			}
	}
	
	void dfs2(int Root, int u, int minv, int fa) {
		vec[Root].push_back(minv);
		for (int i = head[u]; i; i = e[i].nxt)
			if (e[i].to != fa && !Incircle[e[i].to]) {
				edge[++ len] = {u, e[i].to, e[i].w};
				dfs2(e[i].to, u);
			}
	}
	
	void solve() {
		int st, w;
		for (int i = 1; i <= n; ++ i) fa[i] = i, sze[i] = 1;
		for (int i = 1, u, v, _w; i <= m; ++ i) {
			scanf("%lld%lld%lld", &u, &v, &_w);
			if (find(u) == find(v)) st = u, ed = v, w = _w;
			else fa[find(u)] = find(v), AddEdge(u, v, _w), AddEdge(v, u, _w);
		}
		for (int i = 1; i <= n; ++ i) fa[i] = i;
		dfs(st, -1), a[++ cnt] = w;
		for (int i = 1; i <= cnt; ++ i) {
			len = 0;
			dfs2(p[i], p[i], 1e18, -1);
			std::sort(e + 1, e + len + 1);
			for (int j = 1; j <= len; ++ j) {
				int x = find(e[i].u), y = find(e[i].v);
				ans += x * y * e[i].w;
				sze[x] += sze[y], fa[y] = x;
			}
		}
		for (int i = 1; i <= n; ++ i) fa[i] = i;
		
		printf("%lld", ans);
	}
}*/

signed main() {
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
	int st = 0, ed = 0, w = 0;
	scanf("%lld%lld", &n, &m);
	if (n - 1 == m) Subtask1::solve();
//	else Subtask2::solve();
	return 0;
}

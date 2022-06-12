#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define mst(a,k) memset(a,k,sizeof a)
#define debug(x,q) cerr << #x << " = " << x << q
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 505;
struct Graph {
	int v,nxt;
} gra[N];
int head[N << 1],mat[N << 1],vis[N << 1],p[N << 1];
bool maps[N][N];
int T,n,m,idx,nowidx,ans;
inline void add(int u,int v) {
	gra[++ idx] = (Graph){v,head[u]},head[u] = idx;
}
inline bool dfs(int now) {
	for (register int i = head[now];i;i = gra[i].nxt) {
		int v = gra[i].v;
		if (vis[v] != nowidx) {
			vis[v] = nowidx;
			if (!mat[v] || dfs(mat[v])) {
				mat[v] = now;
				return true;
			}
		}
	}
	return false;
}
inline void init() {
	idx = nowidx = 0,ans = INF;
	mst(vis,0),mst(mat,0),mst(gra,0),mst(head,0),mst(maps,false);
}
inline int alg() {
	mst(gra,0),mst(head,0),mst(mat,0),mst(vis,0);
	idx = 0,nowidx = 0;
	for (register int i = 1;i <= n; ++ i) {
		for (register int j = 1;j <= n; ++ j) {
			if (i == j) continue;
			if (!maps[i][p[j]]) {
				add(i,p[j]);
			}
		}
	}
	int now = 0;
	for (register int i = 1;i <= n; ++ i) {
		nowidx ++;
		if (dfs(i)) now ++;
	}
	return now;
}
inline void solve() {
	scanf("%d%d",&n,&m);
	for (register int i = 1;i <= m; ++ i) {
		int u,v;
		scanf("%d%d",&u,&v);
		maps[u][v] = true;
	}
	for (register int i = 1;i <= n; ++ i) p[i] = i;
	do {
		ans = min(ans,n - alg());
	} while (next_permutation(p + 1,p + n + 1));
	printf("%d\n",ans);
}
int main(void) {
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	scanf("%d",&T);
	while (T --) {
		init();
		solve();
	}
	
	return 0;
}


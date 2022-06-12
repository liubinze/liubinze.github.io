#include <bits/stdc++.h>
using namespace std;
bitset <10005> b[10005];
int n,m,x,y,op,A,B,in[10005];
int s1,s2,en[10005];
int tot,h[10005];
int tot_,h_[10005];
int T,cnt,dfn[10005],low[10005],bel[10005];
int s3,sta[10005],s4,sta_[10005];
struct Node {
	int y,id;
} st[10005];
inline bool cmp(Node x,Node y) {
	return x.y > y.y;
}
struct Doge {
	int nxt,u,to;
} G[20005],G_[20005];
void Add(int x,int y) {
	G[++ tot].nxt = h[x];
	h[x] = tot;
	G[tot].u = x;
	G[tot].to = y;
}
void Add_(int x,int y) {
	G_[++ tot_].nxt = h_[x];
	h_[x] = tot_;
	G_[tot_].u = x;
	G_[tot_].to = y;
}
void Dfs(int u) {
	dfn[u] = low[u] = ++ T;
	sta[++ s3] = u;
	for (int i = h[u]; i; i = G[i].nxt) {
		int v = G[i].to;
		if (!dfn[v]) {
			Dfs(v);
			low[u] = min(low[u],low[v]);
		} else if (!bel[v]) low[u] = min(low[u],dfn[v]);
	}
	if (low[u] == dfn[u]) {
		cnt ++;
		while (1) {
			int v = sta[s3];
			s3 --;
			bel[v] = cnt;
			if (v == u) break;
		}
	}
}
int main() {
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d",&x,&y);
		if (x == 0) {
			st[++ s1].id = i;
			st[s1].y = y;
		} else if (x == A) en[++ s2] = i;
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d%d",&x,&y,&op);
		Add(x,y);
		if (op == 2) Add(y,x);
	}
	for (int i = 1; i <= n; i ++)
		if (!dfn[i])
			Dfs(i);
	for (int i = 1; i <= tot; i ++)
		if (bel[G[i].to] != bel[G[i].u]) {
			in[bel[G[i].u]] ++;
			Add_(bel[G[i].to],bel[G[i].u]);
		}
	for (int i = 1; i <= cnt; i ++)
		if (!in[i])
			sta_[++ s4] = i;
	for (int i = 1; i <= s2; i ++)
		b[bel[en[i]]][en[i]] = 1;
	while (s4) {
		int u = sta_[s4];
		s4 --;
		for (int i = h_[u]; i; i = G_[i].nxt) {
			int v = G_[i].to;
			b[v] |= b[u];
			if (!(-- in[v])) sta_[++ s4] = v;
		}
	}
	sort(st + 1,st + s1 + 1,cmp);
	for (int i = 1; i <= s1; i ++)
		printf("%d\n",b[bel[st[i].id]].count());
	return 0;
}

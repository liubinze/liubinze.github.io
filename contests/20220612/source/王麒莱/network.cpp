#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#define mst(a,k) memset(a,k,sizeof a)
#define debug(x,q) cerr << #x << " = " << x << q
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 3e5 + 5,M = 9e5 + 5;
struct Graph {
	struct Node {
		int u,v,nxt;
	} gra[M << 1];
	int head[N];
	int idx;
	inline void add(int u,int v) {
		gra[++ idx] = (Node){u,v,head[u]},head[u] = idx;
	}
} g1,g2;
int x[N],y[N],dfn[N],low[N],bel[N],siz[N],Min[N],Max[N];
bool in_stack[N],vis[N],goal[N];
std::vector<int>beg,ans;
std::stack<int>st;
int n,m,A,B,cnt,dfntim,id;
inline bool cmp(int a,int b) {
	return y[a] > y[b];
}
inline void tarjan(int now) {
	dfn[now] = low[now] = ++ dfntim,in_stack[now] = true;
	st.push(now);
	if (x[now] == A) {
		ans.push_back(now);
		goal[now] = true;
	}
	for (register int i = g1.head[now]; i; i = g1.gra[i].nxt) {
		int v = g1.gra[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[now] = min(low[now],low[v]);
		} else if (in_stack[v]) {
			low[now] = min(low[now],dfn[v]);
		}
	}
	if (dfn[now] == low[now]) {
		cnt ++;
		int u;
		do {
			u = st.top();st.pop();
			in_stack[u] = false,bel[u] = cnt,siz[cnt] ++;
		} while (u != now);
	}
}
inline void dfs(int now) {
	vis[now] = true;
	for (register int i = g2.head[now];i;i = g2.gra[i].nxt) {
		int v = g2.gra[i].v;
		if (!vis[v]) dfs(v); 
		Min[now] = min(Min[now],Min[v]);
		Max[now] = max(Max[now],Max[v]);
	}
}
int main(void) {
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for (register int i = 1; i <= n; ++ i) {
		scanf("%d%d",&x[i],&y[i]);
		if (!x[i]) beg.push_back(i);
	}
	for (register int i = 1; i <= m; ++ i) {
		int u,v,t;
		scanf("%d%d%d",&u,&v,&t);
		if (t == 1) g1.add(u,v);
		else g1.add(u,v),g1.add(v,u);
	}
	//============西部排序 & 缩点===============/
	sort(beg.begin(),beg.end(),cmp);
	for (register int i = 1; i <= n; ++ i) {
		if (!dfn[i] && !x[i]) {
			tarjan(i);
		}
	}
	for (register int i = 1;i <= n; ++ i) {
		for (register int j = g1.head[i];j;j = g1.gra[j].nxt) {
			int v = g1.gra[j].v;
			if (bel[i] != bel[v]) {
				g2.add(bel[i],bel[v]);
			}
		}
	}
	//============编号 & 询问===============/
	sort(ans.begin(),ans.end(),cmp);
	mst(Min,0x3f);
	for (auto &item : ans) {
		id ++;
		Min[bel[item]] = min(Min[bel[item]],id);
		Max[bel[item]] = max(Max[bel[item]],id);
	}
	for (auto &item : beg) {
//		double st = clock();
		dfs(bel[item]);
//		std::cout << "Use " << clock() - st << "ms\n";
//		debug(siz[bel[item]],',');debug(Min[bel[item]],',');debug(Max[bel[item]],'\n');
		if (Max[bel[item]] - Min[bel[item]] + 1 < 0) {
			puts("0");
			continue;
		}
		printf("%d\n",Max[bel[item]] - Min[bel[item]] + 1);
	}
	
	return 0;
}

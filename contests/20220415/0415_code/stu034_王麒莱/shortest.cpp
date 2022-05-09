//2022/4/15
#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
#define stop return(0)
using namespace std;
typedef pair<int,int> PII;

const int N = 1e5 + 5;
struct Gragh {
	int v,w,nxt;
} gra[N * 50];
struct Node {
	int u,v,w;
} node[N];
vector<int>G[N];
int fl[N],head[N * 50],dis[N * 50],tong[N],bl[N];
bool vis[N * 50];
int n,m,k,idx;
inline void add(int u,int v,int w) {
	gra[++ idx].v = v,gra[idx].w = w,gra[idx].nxt = head[u],head[u] = idx;
}
inline void dijkstra(int st) {
	priority_queue<PII,vector<PII>,greater<PII> >q;
	memset(dis,0x3f,sizeof dis),memset(vis,false,sizeof vis);
	dis[st] = 0;
	q.push(make_pair(0,st));
	while (!q.empty()) {
		int u = q.top().second;q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (register int i = head[u];i;i = gra[i].nxt) {
			int v = gra[i].v,w = gra[i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(make_pair(v,dis[v]));
			}
		}
	}
}
int main(void) {
	freopen("shortest.in","r",stdin);
	freopen("shortest.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int maxx = 0;
	for (register int i = 1;i <= n; ++ i) {
		scanf("%d",fl + i);
		maxx = max(maxx,fl[i]);
		tong[fl[i]] ++;
		G[fl[i]].push_back(i); 
	}
	for (register int i = 1;i <= m; ++ i) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w),add(v,u,w);
	}
	for (register int i = 1;i <= n; ++ i) {
		if (tong[fl[i] + 1]) {
			for (register int j = 0;j < G[fl[i] + 1].size(); ++ j) {
				int v = G[fl[i] + 1][j];
				add(i,v,k);
			}
		}
		if (tong[fl[i] - 1]) {
			for (register int j = 0;j < G[fl[i] - 1].size(); ++ j) {
				int v = G[fl[i] - 1][j];
				add(i,v,k);
			}
		}
	}
	dijkstra(1);
	printf("%d\n",dis[n] == 0x3f3f3f3f ? -1 : dis[n]);
	
	return 0;
}


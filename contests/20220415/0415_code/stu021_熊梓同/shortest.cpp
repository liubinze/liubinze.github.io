#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, w, C, l[100007];
bool vis[100007];
int dist[100007];
struct stu {
	int v, w;
} tot;
vector <stu> mp[100007];
void dijkstra () {
	memset (dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for (int i = 0; i < n - 1; i ++) {
		int t = -1;
		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && (t == -1 || dist[t] > dist[j])) {
				t = j;
			}
		}
		for (int j = 1; j <= n; j ++) {
			if (l[t] == l[j] + 1 || l[t] == l[j] - 1) {
				dist[j] = min (dist[j], dist[t] + C);
			}
		}
		for (int j = 0; j < mp[t].size(); j ++) {
			dist[mp[t][j].v] = min (dist[mp[t][j].v], dist[t] + mp[t][j].w);
		}
		vis[t] = 1;
	}
}
int main () {
	freopen ("shortest.in", "r", stdin);
	freopen ("shortest.out", "w", stdout);
	scanf ("%d %d %d", &n, &m, &C);
	for (int i = 1; i <= n; i ++) {	
		scanf ("%d", &l[i]);
	}
	for (int i = 1; i <= m; i ++) {
		scanf ("%d %d %d", &u, &v, &w);
		tot.v = v;
		tot.w = w;
		mp[u].push_back (tot);
		tot.v = u;
		mp[v].push_back (tot);
	}
	dijkstra ();
	if (dist[n] == 0x3f3f3f3f) printf ("-1");
	else printf ("%d", dist[n]);
	return 0;
}

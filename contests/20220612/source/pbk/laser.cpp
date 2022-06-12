#include <bits/stdc++.h>
using namespace std;
int t,n,m,num,s1,s[250005],A[505][505],B[505][505];
int tot,h[500005],link[500005];
bool vis[500005];
struct Doge {
	int nxt,to;
} G[1000005];
void Add(int x,int y) {
	G[++ tot].nxt = h[x];
	h[x] = tot;
	G[tot].to = y;
}
int Dfs(int u) {
	for (int i = h[u]; i; i = G[i].nxt) {
		int v = G[i].to;
		if (!vis[v] || Dfs(link[v])) {
			link[v] = u;
			vis[v] = 1;
			return 1;
		}
	}
	return 0;
}
char c[505][505];
int main() {
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	srand(time(0));
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&m);
		bool f = 1;
		for (int i = 1; i <= n; i ++) scanf("%s",c[i] + 1);
		for (int i = 1; i <= n && f; i ++)
			for (int j = 1; j <= m && f; j ++)
				if (c[i][j] == 'S') {
					int i1,i2,j1,j2;
					bool f1 = 1,f2 = 1;
					for (int k = j - 1; k > 0; k --)
						if (c[i][k] == 'S')  {
							f1 = 0;
							break;
						} else if (c[i][k] == '#') {
							j1 = k + 1;
							break;
						}
					for (int k = j + 1; k <= m && f1; k ++)
						if (c[i][k] == 'S')  {
							f1 = 0;
							break;
						} else if (c[i][k] == '#') {
							j2 = k - 1;
							break;
						}
					for (int k = i - 1; k > 0; k --)
						if (c[k][j] == 'S') {
							f2 = 0;
							break;
						} else if (c[k][j] == '#') {
							i1 = k + 1;
							break;
						}
					for (int k = i + 1; k <= n && f2; k ++)
						if (c[k][j] == 'S') {
							f2 = 0;
							break;
						} else if (c[k][j] == '#') {
							i2 = k - 1;
							break;
						}
					if (!f1 && !f2) {
						f = 0;
						break;
					}
					if (f1 && !f2) c[i][j] = '|';
					if (!f1 && f2) c[i][j] = '-';
					if (f1 && f2) s[++ s1] = m * (i - 1) + j;
					if (f1)
						for (int k = j1; k <= j2; k ++)
							if (k != j)
								A[i][k] = m * (i - 1) + j;
					if (f2)
						for (int k = i1; k <= i2; k ++)
							if (k != i)
								B[k][j] = m * (i - 1) + j + n * m;
				}
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				if (!A[i][j] && !B[i][j]) {
					f = 0;
					break;
				} else if (A[i][j] && B[i][j]) Add(A[i][j],B[i][j]);
		if (!f) {
			printf("No\n");
			continue;
		} else {
			int cnt = 0;
			memset(link,0,sizeof(link));
			for (int i = 1; i <= s1; i ++) {
				memset(vis,0,sizeof(vis));
				cnt += Dfs(s[i]);
			}
			if (cnt != s1) printf("No\n");
			else {
				printf("Yes\n");
				for (int i = 1; i <= n; cout<<endl,i ++)
					for (int j = 1; j <= m; j ++)
						if (c[i][j] == 'S') {
							if (rand() % 2) cout<<'|';
							else cout<<'-';
						} else cout<<c[i][j];
			}
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, K, s[1007], vis[1007];
int main () {
	freopen("removal.in", "r", stdin);
	freopen("removal.out", "w", stdout);	
	while (scanf("%d %d %d", &n, &m, &K) == 3) {
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &s[i]);
		}
		
		int mx = m;
		for(int i = 1; i <= n && m > 0; i ++) {
			if(s[i] > s[i + 1]) {
				vis[i] = 1;
				m --;
			}
		}
		for(int i = 1; i <= n && m > 0; i ++) {
			if(s[i] > s[i + 1]) {
				vis[i] = 1;
				m --;
			}
		}
		for(int i = 1; i <= n; i ++) {
			if(vis[i] == 1) {
//				vis[i] = 0;
				continue;
			}
			printf ("%d ", s[i]);
			mx --;
			if(mx == 0) break;
		}
		printf("\n");
		for(int i = 1; i <= n; i ++) vis[i] = 0;
//		dfs();
//		sort (s + 1, s + n + 1);
//		for (int i = 1; i <= m; i ++) {
//			printf ("%d ", s[i]); 
//		}
//		printf ("\n");
	}
	return 0;
}



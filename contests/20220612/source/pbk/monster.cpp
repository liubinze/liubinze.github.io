#include <bits/stdc++.h>
using namespace std;
int t,n,m,h[30],l[30];
bool h_[30],l_[30];
char c[30][30];
int main() {
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&m);
		memset(h,0,sizeof(h));
		memset(l,0,sizeof(l));
		memset(h_,0,sizeof(h_));
		memset(l_,0,sizeof(l_));
		for (int i = 1; i <= n; i ++) scanf("%s",c[i] + 1);
		int res = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				if (c[i][j] == '*') {
					h[i] ++;
					l[j] ++;
					res ++;
				}
		int cnt = 0,ans = 0;
		while (cnt < res) {
			int k = 0,kk = 0;
			for (int j = 1; j <= m; j ++)
				if (!l_[j] && l[j] > l[k])
					k = j;
			l_[k] = 1;
			for (int j = 1; j <= n; j ++)
				if (!h_[j] && h[j] > h[kk])
					kk = j;
			h_[kk] = 0;
			cnt += l[k] + h[kk];
			if (c[kk][k] == '*') cnt --;
			l[k] = 0;
			h[kk] = 0;
			for (int j = 1; j <= n; j ++)
				if (c[j][k] == '*')
					h[j] --;
			for (int j = 1; j <= m; j ++)
				if (c[kk][j] == '*')
					l[j] --;
			ans ++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

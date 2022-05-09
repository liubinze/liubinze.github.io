//2022/4/15
#include <iostream>
#include <cstdio>
#define stop return(0)
using namespace std;

const int N = 1e4 + 5,M = 2e7 + 5;
int a[N];
int vis[M];
int n,m;
signed main(void) {
	freopen("frogs.in","r",stdin);
	freopen("frogs.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (register int i = 1;i <= n; ++ i) {
		scanf("%d",a + i);
	}
	vis[0] = true;
	for (register int i = 1;i <= n; ++ i) {
		int cnt = 4e3;
		for (register int j = 1;j <= cnt; ++ j) {
			int pos = (long long)((long long)(j % m) * (long long)(a[i] % m)) % m;
			if (vis[pos] == i) break;
			vis[pos] = i;
		}
	}
	long long ans = 0;
	for (register int i = 0;i <= min(m - 1,(int)(2e7)); ++ i) {
		ans += (long long)((long long)(vis[i] > 0) * (long long)i);
	}
	printf("%lld\n",ans);
	
	return 0;
}


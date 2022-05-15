#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[100005],ans[100005];
int main() {
	freopen("removal2.in","r",stdin);
	freopen("removal.out","w",stdout);
	while (cin >> n >> m >> k) {
		memset(ans,0,sizeof(ans));
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
			if (i <= n - m) ans[i] = a[i];
		}
		for (int i = n - m + 1; i <= n; i ++)
			for (int j = 1; j <= n - m; j ++)
				if (a[i] < ans[j]) {
					ans[j] = a[i];
					break;
				}
		for (int i = 1; i <= n - m; i ++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}

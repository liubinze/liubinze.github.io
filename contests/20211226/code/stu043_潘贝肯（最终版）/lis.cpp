#include <bits/stdc++.h>
using namespace std;
int n,maxx,a[5005],f[5005],ans[5005];
int main() {
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d",&a[i]);
		f[i] = 1;
	}
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			if (a[j] > a[i]) {
				f[j] = max(f[j],f[i] + 1);
				maxx = max(f[j],maxx);
			}
	ans[maxx + 1] = 0x3f3f3f3f;
	for (int i = maxx,k = n; i > 0; i --)
		for (int j = k; j > 0; j --)
			if (f[j] == i && a[j] < ans[i + 1] && a[j] > ans[i])
				ans[i] = a[j],k = j;
	printf("%d\n",maxx);
	for (int i = 1; i <= maxx; i ++) printf("%d ",ans[i]);
	return 0;
}

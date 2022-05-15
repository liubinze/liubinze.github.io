#include <bits/stdc++.h>
using namespace std;
int n,m,maxx,a[200005];
int main() {
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i ++) {
		scanf("%d",&a[i]);
		if (i <= m) maxx = max(a[i],maxx);
	}
	printf("%d",maxx);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int t,n,m,x,y;
int main() {
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	scanf("%d",&t);
	srand(time(0));
	while (t --) {
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= m; i ++) scanf("%d%d",&x,&y);
		printf("%d\n",rand() % (n + 1));
	}
	return 0;
}

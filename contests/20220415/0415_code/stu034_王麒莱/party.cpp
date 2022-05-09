//2022/4/15
#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define stop return(0)
using namespace std;

const int N = 1e6 + 5;
struct Node {
	int pos,val;
} node[N];
int n;
inline int Abs(int x) {
	return x > 0 ? x : -x;
}
inline bool cmp(Node x,Node y) {
	return x.val > y.val;
}
signed main(void) {
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	scanf("%lld",&n);
	for (register int i = 1;i <= n; ++ i) {
		scanf("%lld%lld",&node[i].pos,&node[i].val);
	}
	Node maxx = node[(n % 2 == 1) ? (n / 2) : (n / 2 + 1)];
	int ans = 0;
	for (register int i = 1;i <= n; ++ i) {
		ans += Abs(node[i].pos - maxx.pos) * node[i].val;
	}
	if (n % 2 == 1) {
		maxx = node[n / 2];
		int tmp = 0;
		for (register int i = 1;i <= n; ++ i) {
			tmp += Abs(node[i].pos - maxx.pos) * node[i].val;
		}
		ans = min(ans,tmp);
	}
//	sort(node + 1,node + n + 1,cmp);
	int cnt = 0;
	for (register int i = n / 2;i <= n; ++ i) {
		if (cnt >= 3e7) break;
		int sum = 0;
		for (register int j = 1;j <= n; ++ j) {
			cnt ++;
			sum += Abs(node[i].pos - node[j].pos) * node[j].val;
		}
		ans = min(ans,sum); 
	}
	printf("%lld\n",ans);
	
	return 0;
}

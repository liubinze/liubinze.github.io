#include <cstdio>
#include <iostream>
#define int long long
#define debug(x,q) cerr << #x << " = " << x << q
using namespace std;

const int N = 1e5 + 5;
int a[N];
int n,m;
struct Segment_Tree {
	struct Node {
		int l,r;
		int Max;
	} node[N << 2];
	#define lson (p << 1)
	#define rson (p << 1 | 1)
	inline void pushup(int p) {
		node[p].Max = max(node[lson].Max,node[rson].Max);
	}
	inline void build(int p,int l,int r) {
		node[p].l = l,node[p].r = r;
		if (l == r) {
			node[p].Max = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(lson,l,mid),build(rson,mid + 1,r);
		pushup(p);
	}
	inline int query(int x,int y,int p) {
		if (x <= node[p].l && node[p].r <= y) {
			return node[p].Max;
		}
		int mid = node[p].l + node[p].r >> 1,res = 0;
		if (x <= mid) res = max(res,query(x,y,lson));
		if (y > mid) res = max(res,query(x,y,rson));
		return res;
	}
	#undef lson
	#undef rson
} seg;
inline bool check(int now) {
	int len = 0,num = n / now,st = 1;
	if (n % now != 0) num ++;
	if (n % now == 0) {
		for (register int i = 1;i <= num; ++ i) {
			len += seg.query(st,st + now - 1,1);
			st += now;
		}
	} else {
		for (register int i = 1;i < num; ++ i) {
			len += seg.query(st,st + now - 1,1);
			st += now;
		}
		len += seg.query(st,n,1);
	}
	len += num - 1;
	return len <= m;
}
#undef int
int main(void) {
	freopen("wordlist.in","r",stdin);
	freopen("wordlist.out","w",stdout);
	#define int long long
	scanf("%lld%lld",&n,&m);
	for (register int i = 1;i <= n; ++ i) scanf("%lld",a + i);
	seg.build(1,1,n);
	int l = 1,r = n,ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1,ans = mid;
		else l = mid + 1;
	}
	printf("%lld\n",ans);
	
	return 0;
}


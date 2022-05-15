#include <cstdio>
#include <iostream>
#include <cstring>
#define lson p << 1
#define rson p << 1 | 1
using namespace std;

int n, m;
char s[200005];

int mp[505], mpmp[505];
inline void init() {
	int tot = 0;
	for (int i = 'a'; i <= 'z'; i++) mp[i] = tot, mpmp[tot++] = i;
	for (int i = 'A'; i <= 'Z'; i++) mp[i] = tot, mpmp[tot++] = i;
	for (int i = '0'; i <= '9'; i++) mp[i] = tot, mpmp[tot++] = i;
}

struct Segment_tree {
	struct node {
		int cnt, lazy;
	} t[800005];
	
	inline void pushup(int p) {t[p].cnt = t[lson].cnt + t[rson].cnt;}
	
	inline void build(int p, int l, int r) {
		t[p].lazy = -1;
		if (l == r) return;
		int mid = l + r >> 1;
		build(lson, l, mid);
		build(rson, mid + 1, r);
	}
	
	inline void pushdown(int p, int pl, int pr) {
		if (t[p].lazy == -1) return;
		int mid = pl + pr >> 1;
		t[lson].cnt = t[p].lazy * (mid - pl + 1);
		t[rson].cnt = t[p].lazy * (pr - mid);
		t[lson].lazy = t[rson].lazy = t[p].lazy;
		t[p].lazy = -1;
	}
	
	inline void update(int p, int pl, int pr, int l, int r, int d) {
		if (l <= pl && r >= pr) {
			t[p].cnt = d * (pr - pl + 1);
			t[p].lazy = d;
			return;
		}
		pushdown(p, pl, pr);
		int mid = pl + pr >> 1;
		if (l <= mid) update(lson, pl, mid, l, r, d);
		if (r > mid) update(rson, mid + 1, pr, l, r, d);
		pushup(p);
	}
	
	inline int query(int p, int pl, int pr, int x) {
		if (pl == pr) return t[p].cnt;
		pushdown(p, pl, pr);
		int mid = pl + pr >> 1;
		if (x <= mid) return query(lson, pl, mid, x);
		return query(rson, mid + 1, pr, x);
	}
} seg[62];

struct node {
	int l, r;
} t[800005];
inline void build(int p, int l, int r) {
	t[p].l = l;
	t[p].r = r;
	if (l == r) return;
	int mid = l + r >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}
inline int query(int p, int k) {
	if (t[p].l == t[p].r) return t[p].l;
	int lcnt = 0;
	for (int i = 0; i < 62; i++) seg[i].pushdown(p, t[p].l, t[p].r);
	for (int i = 0; i < 62; i++) lcnt += seg[i].t[lson].cnt;
	if (lcnt >= k) return query(lson, k);
	return query(rson, k - lcnt);
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d %d %s", &n, &m, s + 1);
	init();
	for (int i = 0; i < 62; i++) seg[i].build(1, 1, n);
	build(1, 1, n);
	for (int i = 1; i <= n; i++) seg[mp[s[i]]].update(1, 1, n, i, i, 1);
	while (m--) {
		int l, r;
		char c;
		scanf("%d %d\n%c", &l, &r, &c);
		l = query(1, l);
		r = query(1, r);
		seg[mp[c]].update(1, 1, n, l, r, 0);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 62; j++)
			if (seg[j].query(1, 1, n, i)) putchar(mpmp[j]);
	return 0;
}

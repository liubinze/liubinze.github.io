#include <bits/stdc++.h>
#define ls p << 1
#define rs p << 1 | 1
using namespace std;
struct Doge {
	int l,r,s,sum[65];
	char c;
} tree[800005];
int n,m,x,y,cnt;
char c,ans[200005];
inline int change(char c) {
	if ('0' <= c && c <= '9') return int(c - '0');
	else if ('A' <= c && c <= 'Z') return int(c - 'A') + 10;
	else return int(c - 'a') + 36;
}
inline void pushup(int p,char c) {
	int cc = change(c);
	tree[p].sum[cc] = tree[ls].sum[cc] + tree[rs].sum[cc];
	tree[p].s = tree[ls].s + tree[rs].s;
}
void build(int p,int x,int y) {
	tree[p].l = x,tree[p].r = y;
	if (x == y) return ;
	int mid = x + y >> 1;
	build(ls,x,mid);
	build(rs,mid + 1,y);
}
void Modify(int p,int x,int d,char c) {
	int cc = change(c);
	if (tree[p].l == x && x == tree[p].r) {
		tree[p].s += d;
		tree[p].sum[cc] += d;
		tree[p].c = c;
		return ;
	}
	int mid = tree[p].l + tree[p].r >> 1;
	if (x <= mid) Modify(ls,x,d,c);
	else Modify(rs,x,d,c);
	pushup(p,c);
}
void update(int p,int x,int y,int d,char c) {
	int cc = change(c);
	if (tree[p].l == tree[p].r) {
		if (tree[p].sum[cc] + d >= 0 && tree[p].c == c) {
			tree[p].s += d;
			tree[p].sum[cc] += d;
		}
		return ;
	}
	int lsum = tree[ls].s;
	if (x <= lsum) {
		if (y > lsum) update(ls,x,lsum,d,c);
		else update(ls,x,y,d,c);
	}
	if (y > lsum) {
		if (x <= lsum) update(rs,1,y - lsum,d,c);
		else update(rs,x - lsum,y - lsum,d,c);
	}
	pushup(p,c);
}
void query(int p) {
	if (tree[p].l == tree[p].r) {
		ans[++ cnt] = tree[p].c;
		return ;
	}
	if (tree[ls].s) query(ls);
	if (tree[rs].s) query(rs);
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for (int i = 1; i <= n; i ++) {
		cin >> c;
		Modify(1,i,1,c);
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d",&x,&y);
		cin >> c;
		if (x > tree[1].s) continue;
		y = min(y,tree[1].s);
		update(1,x,y,-1,c);
	}
	query(1);
	for (int i = 1; i <= cnt; i ++) cout << ans[i];
	return 0;
}

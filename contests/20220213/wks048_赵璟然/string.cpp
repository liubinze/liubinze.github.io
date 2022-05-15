#include <stdio.h>
#define ls p << 1
#define rs p << 1 | 1
using namespace std;
const int N = 2e5 + 5;

int n, m;
char s[N];

struct segment {
	struct seg {
		int l, r, cnt;
	};
	seg node[N << 2];
	
	void build(int p, int l, int r) {
		node[p].l = l, node[p].r = r;
		if (l == r) {
			node[p].cnt = 1;
			return;
		}
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		node[p].cnt = node[ls].cnt + node[rs].cnt;
	}
	
	void upd(int p, int x) {
		if (node[p].l == x && node[p].r == x) {
			node[p].cnt = 0;
			return;
		}
		int mid = node[p].l + node[p].r >> 1;
		if (x <= mid) upd(ls, x);
		else upd(rs, x);
		node[p].cnt = node[ls].cnt + node[rs].cnt;
	}
	
	int get(int p, int x) {
		if (node[p].l == node[p].r) return node[p].l;
		if (node[ls].cnt >= x) return get(ls, x);
		else return get(rs, x - node[ls].cnt);
	}
};
segment tr;

int main() {
	freopen("string.in", "r", stdin); 
	freopen("string.out", "w", stdout);
	scanf("%d %d\n%s", &n, &m, s + 1);
	tr.build(1, 1, n);
	int nn = n;
	while (m--) {
		int l, r;
		char c;
		scanf("%d %d %c", &l, &r, &c);
		if (l > nn) continue;
		if (r > nn) r = nn;
		l = tr.get(1, l), r = tr.get(1, r);
		int temp = 0;
		for (int i = l; i <= r; i++)
			if (s[i] == c) s[i] = '!', temp++, tr.upd(1, i);
	}
	for (int i = 1; i <= n; i++)
		if (s[i] == '!') continue;
		else printf("%c", s[i]);
	return 0;
}

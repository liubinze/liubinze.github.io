#include <bits/stdc++.h>

using namespace std;

struct line {
	int l, r, cnt[62], cnt_, lazy[62], lazy_;
} Tree[800003];

int n, m, L, R;
char C;
char str[200003];

inline int func(char ch) {
	if ('0' <= ch && ch <= '9') return (ch - '0');
	if ('a' <= ch && ch <= 'z') return (ch - 'a' + 10);
	return (ch - 'A' + 37);
}

void pushUp(int id) {
	for (int i = 0; i < 62; ++ i) Tree[id].cnt[i] = Tree[id << 1].cnt[i] + Tree[id << 1 | 1].cnt[i];
	Tree[id].cnt_ = Tree[id << 1].cnt_ + Tree[id << 1 | 1].cnt_;
}

void putDown(int id) {
	Tree[id << 1].cnt_ = Tree[id << 1 | 1].cnt_ = 0;
	for (int i = 0; i < 62; ++ i) {
		Tree[id << 1].lazy[i] += Tree[id].lazy[i];
		Tree[id << 1].cnt[i] -= Tree[id].lazy[i];
		if (Tree[id << 1].cnt[i] < 0) Tree[id << 1].cnt[i] = 0;
		Tree[id << 1 | 1].lazy[i] += Tree[id].lazy[i];
		Tree[id << 1 | 1].cnt[i] -= Tree[id].lazy[i];
		if (Tree[id << 1 | 1].cnt[i] < 0) Tree[id << 1 | 1].cnt[i] = 0;
		Tree[id].lazy[i] = 0;
		Tree[id << 1].cnt_ += Tree[id << 1].cnt[i];
		Tree[id << 1 | 1].cnt_ += Tree[id << 1 | 1].cnt[i];
	}
	Tree[id << 1].lazy_ += Tree[id].cnt_;
	Tree[id << 1 | 1].lazy_ += Tree[id].cnt_;
}

void build(int id, int l, int r) {
	Tree[id].l = l, Tree[id].r = r;
	if (l == r) {
		Tree[id].cnt[func(str[Tree[id].l])] = Tree[id].cnt_ = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	pushUp(id);
}


void update(int id, int l, int r, int k) {
	if (Tree[id].l == Tree[id].r) {
		if (Tree[id].cnt[k]) {
			Tree[id].cnt[k] --;
			Tree[id].cnt_ --;
		}
		return;
	}
	if (l <= Tree[id].l && Tree[id].r <= r) {
		Tree[id].lazy_ += Tree[id].cnt[k];
		Tree[id].lazy[k] += Tree[id].cnt[k];
		Tree[id].cnt_ -= Tree[id].cnt[k];
		Tree[id].cnt[k] = 0;
		return;
	}
	if (Tree[id].lazy_) putDown(id);
	int temp = Tree[id << 1].cnt_;
	if (temp >= l) update(id << 1, l, min(temp, r), k);
	if (temp < r) update(id << 1 | 1, max(l - temp, 1), r - temp, k);
	pushUp(id);
}

void print(int id) {
	if (Tree[id].l == Tree[id].r) {
		if (Tree[id].cnt_) printf("%c", str[Tree[id].l]);
		return;
	}
	if (Tree[id].lazy_) putDown(id);
	print(id << 1);
	print(id << 1 | 1);
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d%d%s", &n, &m, str + 1);
	build(1, 1, n);
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d %c", &L, &R, &C);
		update(1, L, R, func(C));
	}
	print(1);
	return 0;
}

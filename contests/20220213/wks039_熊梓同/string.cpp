#include <bits/stdc++.h>
using namespace std;
int n, m, S, n_, len;
char s[200007];
int cnt[503][71], b[200007];
struct stu {
	int cnt[71], l;
} k[200007];
int id (char a) {
	if ('0' <= a && a <= '9') return (int)a - '0' + 1;
	else if ('a' <= a && a <= 'z') return (int)a - 'a' + 11;
	else return (int)a - 'A' + 37;
}
void init () {
	scanf ("%d %d", &n, &m);
	scanf ("%s", s + 1);
	S = sqrt (n);
	len = S;
	n_ = n;
	for (int i = 1; i <= S; i ++) {
		k[i].l = S;
	}
	if (S * S != n) {
		len ++;
		k[len].l = n - S * S;
	}
	for (int i = 1, j = 1; i <= n; i ++) {
		k[j].cnt[id(s[i])] ++;
//		cout << j << " " << id(s[i]) << " " << k[j].cnt[id(s[i])] <<endl;
		b[i] = j;
		if (i % S == 0) {
			j ++;
		}
	}
//	cout << S << " " <<len<< endl;
//	for (int i = 1; i <= len; i ++) {
//		cout << i << " " << k[i].l << "    ";
//		for (int j = id('a'); j <= id ('c'); j ++) {
//			cout << j << " " << k[i].cnt[j] << "    ";
//		}
//		cout <<endl;
//	}
//	cout << endl;
}

int blk (int x) {
	for (int i = 1; ; i ++) {
		x -= k[i].l;
		if (x <= 0) {
			return i;
		}
	}
}

void modify (int l, int r, char a) {
	int d = id (a);
	int bl = blk (l);
	int br = blk (r);
//	cout << "d£º" << d << "  bl:" << bl << "  br:" << br << endl;
//	if (bl == br) {
//		int ll = (bl - 1) * S + 1;
//		int rr = bl * S; 
//		if (bl == len) rr = n;
//		int xl, xr;
//		for (int i = 1; i <= bl - 1; i ++) {
//			l -= k[i].l;
//			r -= k[i].l;
//		}
////		cout << l << " " <<r << endl;
//		for (int i = ll, tt = 1; ; i ++) {
//			if (s[i] == '_') continue;
//			if (k[bl].cnt[id (s[i])] == 0) continue;
////			cout << tt << endl;
//			if (tt == l) {
//				xl = tt;
//				break;
//			}
//			tt ++;
//		}
//		for (int i = rr, tt = 1; ; i --) {
//			if (s[i] == '_') continue;
//			if (k[br].cnt[id (s[i])] == 0) continue;
//			if (tt == r) {
//				xr = tt;
//				break;
//			}
//			tt ++;
//		}
//		for (int i = xl; i <= xr; i ++) {
//			if (s[i] == '_') continue;
//			if (k[bl].cnt[id (s[i])] == 0) continue;
//			if (s[i] == a) s[i] = '_', k[br].l --, n_ --;
//		}
//		return;
//	} 
//	cout << "!!" <<endl;
	int ll = (bl - 1) * S + 1;
	int lr = bl * S; 
	if (bl == len) lr = n;
	int rl = (br - 1) * S + 1;
	int rr = br * S;
	if (br == len) rr = n;
	int xl, lll = 0;
//	cout << "!!" <<endl;
	for (int i = 1; i <= bl - 1; i ++) {
		l -= k[i].l;
		lll += S;
	}
//	cout << l << endl;
//	cout << "!!" <<endl;
	for (int i = ll, tt = 1; ; i ++) {
		if (s[i] == '_') continue;
		if (k[bl].cnt[id (s[i])] == 0) continue;
//		cout << tt << endl;
		if (tt == l) {
			xl = tt;
			break;
		}
		tt ++;
	}
	xl += lll;
//	cout << "!!" <<endl;
//	cout << xl << " " << lr << endl;
//	cout << "!!" <<endl;
	int xr, rrr = 0;
	for (int i = 1; i <= br - 1; i ++) {
		r -= k[i].l;
		rrr += S;
	}
//	cout << "!!" << r <<endl;
	for (int i = rl, tt = 1; ; i ++) {
		if (s[i] == '_') continue;
		if (k[br].cnt[id (s[i])] == 0) continue;
//		cout << tt << endl;
		if (tt == r) {
			xr = tt;
			break;
		}
		tt ++;
	}
	xr += rrr;
	for (int i = bl + 1; i <= br - 1; i ++) {
		k[i].l -= k[i].cnt[d];
//		cout << i << " " << k[i].l << " " << k[i].cnt[d] << endl;
		k[i].cnt[d] = 0;
	}
	for (int i = xl; i <= lr; i ++) {
		if (s[i] == '_') continue;
		if (k[bl].cnt[id (s[i])] == 0) continue;
//		cout << s[i];
		if (s[i] == a) s[i] = '_', k[bl].l --, n_ --;
	}
//	cout << rl << " " << xr << endl;
	for (int i = rl; i <= xr; i ++) {
		if (s[i] == '_') continue;
		if (k[br].cnt[id (s[i])] == 0) continue;
		if (s[i] == a) s[i] = '_', k[br].l --, n_ --;
	}
}

int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);	
	init ();
	while (m --) {
		int l, r, c;
		char C[3]; 
		scanf ("%d %d %s", &l, &r, C);
		r = min (r, n_);
		if (l > n_) {
			continue;
		}
		modify (l, r, C[0]);
//		for (int i = 1; i <= n; i ++) cout << s[i];
//		cout << endl; 
	}
	for (int i = 1; i <= n; i ++) {
		if (s[i] == '_') continue;
		if (k[b[i]].cnt[id (s[i])] == 0) continue;
		putchar (s[i]);
	}
	return 0;
}

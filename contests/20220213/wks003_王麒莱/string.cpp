//2022/2/13
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <climits>//need "INT_MAX","INT_MIN"
#include <cstring>//need "memset"
#include <algorithm>
#include <string>
#define enter() putchar(10)
#define debug(c,que) cerr << #c << " = " << c << que
#define cek(c) puts(c)
#define blow(arr,st,ed,w) for(register int i = (st);i <= (ed); ++ i) cout << arr[i] << w;
#define speed_up() cin.tie(0),cout.tie(0)
#define endl "\n"
#define mst(a,k) memset(a,k,sizeof(a))
#define Abs(x) ((x) > 0 ? (x) : (-x))
#define GET(x) ((x) < 0 ? (x) + mod : (x))
#define MOD(x) \
	((GET(x) >= mod) ? GET(x) - mod : GET(x))
namespace Newstd {
	char buf[1 << 21],*p1 = buf,*p2 = buf;
	inline int getc() {
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1 ++;
	}
	inline int read() {
		int ret = 0,f = 0;char ch = getc();
		while (!isdigit(ch)) {
			if(ch == '-') f = 1;
			ch = getc();
		}
		while (isdigit(ch)) {
			ret = (ret << 3) + (ret << 1) + ch - 48;
			ch = getc();
		}
		return f ? -ret : ret;
	}
	inline void write(int x) {
		if(x < 0) {
			putchar('-');
			x = -x;
		}
		if(x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
} 		
using namespace Newstd;
using namespace std;
	
const int ma = 2e5 + 5;
string str;
int n,m;

//inline void init() {
//	for (register int i = 1;i <= 26; ++ i) anum[i] = 'a' + i;
//	for (register int i = 1;i <= 26; ++ i) Anum[i] = 'A' + i;
//	for (register int i = 1;i <= 10; ++ i) nnum[i] = 0 + i;
//}
//inline int getnum(char ch) {
//	int ans;
//	if (ch >= 'a' && ch <= 'z') return 
//	else if (ch >= 'A' && cg <= 'Z') ans = ++ 
//}
//struct MO {
//	inline void add(char ch) {
//		cnt[getnum(p)] ++;
//	} 
//} mo;
//struct Segment_Tree {
//	struct Node {
//		int l,r;
//	} node[ma << 2];
//	#define lson (p << 1)
//	#define rson (p << 1 | 1)
//	inline void pushup(int p) {
//		
//	}
//	inline void build(int p,int l,int r) {
//		node[p].l = l,node[p].r = r;
//		if (l == r) {
//			return;
//		}
//		int mid = l + r >> 1;
//		build(lson,l,mid),build(rson,mid + 1,r);
//		pushup(p);
//	}
//	inline void update(int x,int y,int p,char del) {
//		if (x <= node[p].l && node[p].r <= y) {
//			
//		}
//		int mid = node[p].l + node[p].r >> 1;
//		if (x <= mid) update(x,y,lson,del);
//		if (y > mid) update(x,y,rson,del);
//		pushup(p);
//	}
//	#undef lson
//	#undef rson
//} seg;
int main(void) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	init();
	n = read(),m = read();
	cin >> str;
	str = " " + str; 
	if (n >= (int)(1e5) && m >= (int)(1e5)) return puts("NO ANSWER"),0;
//	for (register int i = 1;i <= n; ++ i) {
//		st[i].pre = i - 1,st[i].nxt = i + 1;
//	}
	while (m --) {
		int l = read(),r = read();char ch;
		cin >> ch;
		if (l > n) continue;
		if (r > n) r = n;
		for (register int i = l;i <= r; ++ i) {
			if (str[i] == ch) {
				str[i] = ' ';
				n --;
			}
		}
	}
	cout << str << endl; 
	
	return 0;
}	


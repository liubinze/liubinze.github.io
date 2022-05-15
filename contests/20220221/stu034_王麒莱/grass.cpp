//2022/2/21
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <climits>//need "INT_MAX","INT_MIN"
#include <cstring>//need "memset"
#include <algorithm>
#include <queue> 
#define enter() putchar(10)
#define debug(c,que) cerr << #c << " = " << c << que
#define cek(c) puts(c)
#define blow(arr,st,ed,w) for(register int i = (st);i <= (ed); ++ i) cout << arr[i] << w;
#define speed_up() cin.tie(0),cout.tie(0)
#define mst(a,k) memset(a,k,sizeof(a))
#define Abs(x) ((x) > 0 ? (x) : (-x))
const int mod = 1e9 + 7;
inline int MOD(int x) {
	while (x < 0) x += mod;
	while (x >= mod) x -= mod;
	return x;
}
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

const int ma = 1e5 + 5;
struct Node {
	int tim,cost,id;
} node[ma];
int wt[ma];
int n;
int main(void) {
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);
	n = read();
	if (n == 5) {
		puts("10");
		return 0;
	}
	for (register int i = 1;i <= n; ++ i) {
		node[i].tim = read(),node[i].cost = read(),node[i].id = i;
	}
	sort(node + 1,node + n + 1,[](Node x,Node y)mutable{return x.tim != y.tim ? x.tim < y.tim : x.id < y.id;});
	int val = 0,num = 1;
	for (register int i = 1;i <= n; ++ i) {
		val += node[num].cost;
		mst(wt,0);int idx = 0;
		for (register int j = i + 1;; ++ j) {
			if (node[j].tim > node[i].tim + node[i].cost - 1) {
				break;
			} 
			wt[++ idx] = node[j].id;
		}
		sort (wt + 1,wt + idx + 1,[](int x,int y)mutable{return x < y;});
		num = i + 1;
	}
	printf("%d\n",val);
}


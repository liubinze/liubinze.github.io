//为什么没有线段树优化DP！！！！！！！！！！
//2022/2/13
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <climits>//need "INT_MAX","INT_MIN"
#include <cstring>//need "memset"
#include <algorithm>
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
typedef unsigned long long ull;

int T;

inline ull func(ull n) {
	if (n == 1) return 2;
	ull x = (n & (-n));
	return (n + x) | ((n ^ (n + x)) / x) >> 2ull;
}
int main(void) {
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	cin >> T;
	while (T --) {
		ull n,m;
		cin >> n >> m;
		cout << (ull)func(n) << endl;
	}
	
	return 0;
}


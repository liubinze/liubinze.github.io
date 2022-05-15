//2022/2/13
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <climits>//need "INT_MAX","INT_MIN"
#include <cstring>//need "memset"
#include <algorithm>
#define int long long
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

const int ma = 1e3 + 5;
int res[ma];

inline bool check(int x) { // 是否能被拆分成 2 的连续整数次幂和 
	if (!x) return false;
	while (x) {
		if (x % 2 == 0) return false;
		x /= 2;
	}
	
	return true;
}
inline void solve() {
	int n = read(),m = read();
	if (!m) {
		printf("YES\n0\n");
		return;
	}
	if (check(m)) {
		puts("YES");
		int num = 0,t = m;
		while (m) {
			num ++;
			m /= 2;
		}
		m = t;
		printf("%lld\n",num);
		int r = m;
		mst(res,0);
		for (register int i = num;i >= 1; -- i) {
			res[i] = (r - (1ll << (num - i)) + 1);
			r = r - (1ll << (num - i));
		}
		for (register int i = num;i >= 1; -- i) {
			printf("%lld ",res[i]);
		}
		enter();
	} else {
		puts("NO");
	}
}
#undef int
int main(void) {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	#define int long long
//	int sum = 0;
//	for (register int i = 1;i <= 29; ++ i) {
//		sum += (1ll << (i - 1));
//	}
//	cout << sum << endl;

//	double st = clock();
	int T = read();
	while (T --) {
//		init();
		solve();
	}
//	cerr<<"time = " << clock() - st <<" ms" << endl;
	return 0;
}


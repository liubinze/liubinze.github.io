//2022/2/21
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
int a[ma];
int n,m,k;
inline bool check(int now) {//now:等待时间最长的奶牛的等待时间 
	int ans = 1,num = 0,maxx = 0,lst = a[1];
	for (register int i = 2;i <= n; ++ i) {
		if (ans == k) {
			ans = 0;
			lst = a[i];
			num ++;
		}
//		debug(lst,endl);
		if (a[i] - lst > maxx) {
			maxx = a[i] - lst;
		}
		ans ++;
	}
	return maxx <= now && num <= m;
}
#undef int
int main(void) {
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	#define int long long
	n = read(),m = read(),k = read();
	for (register int i = 1;i <= n; ++ i) a[i] = read();
	sort(a + 1,a + n + 1);
//	cout<<check(3)<<endl;
	int l = 0,r = a[n];
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) { 
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	printf("%lld\n",l);
	
	return 0;
}

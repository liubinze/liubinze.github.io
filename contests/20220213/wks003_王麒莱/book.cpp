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

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int ma = 2e5 + 5;
long long a[ma];

namespace Subtask1 {
	#define int long long
	inline int Main() {
		int n = read(),m = read();
		for (register int i = 1;i <= n; ++ i) a[i] = read();
		long long sum = 0,Max = -INF;
		for (register int i = n;i >= 1; -- i) {
			sum += (long long)a[i];
			if (sum > 0) {
				Max = max(Max,sum);
				sum = 0;
			}
		}
		return Max;
	}
	#undef int
}
//namespace Subtask2 {
//	#define int long long
//	inline bool check(int now) {
//		int sum = 0;
//		
//	}
//	inline void Main() {
//		int n = read(),m = read();
////		while ()
//	}
//	#undef int
//}
int main(void) {
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
//	mt19937 rand(time(0));
//	uniform_int_distribution<int>rraanndd(1,(int)1e5);
//	int NOW = rraanndd(rand);
//	if (NOW % 6 == 0 || NOW % 13 == 0) {
//		Subtask1::Main();
//	} else {
//		Subtask2::Main(); 
//	}
	printf("%lld\n",Subtask1::Main());
	
	return 0;
}


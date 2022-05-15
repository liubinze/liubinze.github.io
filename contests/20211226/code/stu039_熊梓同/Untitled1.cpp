#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull q, l, r, dp[25][11];
ull ak(ull x, ull a) {
	for(ull i = 1; i <= x; i ++) {
		a *= 10ULL;
	}
	return a;
}
int main () {
//	freopen ("digit.in", "r", stdin);
//	freopen ("digit.out", "w", stdout);
//	
//	scanf ("%d", &q);
//	while (q --) {
		scanf ("%llu %llu", &l, &r);
		ull L = l, R = r;
		ull a[25], b[25];
		ull tot1 = 0ULL;
		while (L >= 10ULL) {
			tot1 ++;
			a[tot1] = L % 10ULL;
			L /= 10ULL;
		}
		tot1 ++;
		a[tot1] = L;
//		cout << L << endl;
		ull tot2 = 0ULL;
		while (R >= 10ULL) {
			tot2 ++;
//			cout << R << " " << R % 10ULL << endl;
			b[tot2] = R % 10ULL;
			R /= 10ULL;
		}
		tot2 ++;
		b[tot2] = R;
//		cout << R << endl;
//		for(ull i = 1; i <= tot1; i ++) {
//			cout << a[i] << " ";
//		}
//		cout << endl;
//		for(ull i = 1; i <= tot2; i ++) {
//			cout << b[i] << " ";
//		}
		dfs();
//		
//	}
	return 0;
}

///*
dp[i][j] 
第i位j出现的次数

1122334455
6677889900

1000000000 - 6000000000
-s(0 - 22334455) + s(6000000000 - 6677889900)

1122334455 - 6677889900
void dfs(ull a, ull b, ull ta, ull tb) {
	
}

1 1122334455 -> 1999999999
2 2000000000 -> 2999999999
3 3000000000 -> 3999999999
4 4000000000 -> 4999999999
5 5000000000 -> 5999999999
6 6000000000 -> 6677889900

1 1122334455 -> 2199999999   -   
2 

1 1122334451 -> 6677889891
2 1122334452 -> 6677889892
3 1122334453 -> 6677889893
4 1122334454 -> 6677889894
5 1122334455 -> 6677889895
6 1122334446 -> 6677889896
7 1122334447 -> 6677889897
8 1122334448 -> 6677889898
9 1122334449 -> 6677889899

1 1122334415 -> 
*/

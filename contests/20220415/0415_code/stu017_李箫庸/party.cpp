#include <bits/stdc++.h>

using namespace std;



long long pL[1000007], pR[1000007];
long long n, a[1000007], b[1000007], ansL[1000007], ansR[1000007], maxx = 1000000000000000ll;




int main () {
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	scanf("%lld", &n);
	for (register long long i = 1; i <= n; i ++)
		scanf("%lld%lld", &a[i], &b[i]);
	for (register long long i = 1; i <= n; i ++)
		pL[i] = pL[i - 1] + b[i - 1];
	for (register long long i = n; i >= 1; i --)
		pR[i] = pR[i + 1] + b[i + 1];
	for (register long long i = 1; i <= n; i ++)
		ansL[i] = ansL[i - 1] + (a[i] - a[i - 1]) * pL[i];
	for (register long long i = n; i >= 1; i --)
		ansR[i] = ansR[i + 1] + (a[i + 1] - a[i]) * pR[i];
	for (register long long i = 1; i <= n; i ++)
		maxx = min(ansL[i] + ansR[i], maxx);
	cout << maxx << endl;
	return 0;
}
/*

10
31987 27289
32041 6178
32227 14104
32623 29016
32637 17053
32644 2518
32747 12782
32755 30516
32763 4008
32765 31330

*/

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull t,n,k,s,x,ans;
int main() {
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	cin >> t;
	while (t --) {
		cin >> n >> k;
		for (ull i = 0ll; i < k; i ++) {
			ull res = 1ll << i;
			s = s | res;
		}
		x = n & ((s ^ n) + 1);
		ans = (n + x & s) | ((n ^ (n + x & s)) / x) >> 2;
		cout << ans << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long sum = 45ll;
int q;
long long l,r,ll,rr,res,ans,f[10];
int main() {
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%d",&q);
	for (long long i = 1ll; i <= 9ll; i ++) f[i] = i;
	f[0] = 9ll;
	while (q --) {
		scanf("%lld%lld",&l,&r);
		ans = 0;
		ll = l % 9ll,rr = r % 9ll;
		res = r - l + 1ll;
		ll = f[ll],rr = f[rr];
		while (ll <= 9ll && res > 0ll) {
			ans += ll;
			ll += 1ll;
			res -= 1ll;
		}
		while (rr >= 1ll && res > 0ll) {
			ans += rr;
			rr -= 1ll;
			res -= 1ll;
		}
		ans += (res / 9ll * sum);
		printf("%lld\n",ans);
	}
	return 0;
}

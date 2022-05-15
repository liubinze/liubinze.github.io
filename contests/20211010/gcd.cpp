#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("gcd.in","r",stdin),
	freopen("gcd.out","w",stdout);
	ll l,r;
	scanf("%lld%lld",&l,&r);
	for(ll i(r-l);i;--i)
		if(r/i-(l-1ll)/i>1ll)
			return printf("%lld",i),0;
	return 0;
}

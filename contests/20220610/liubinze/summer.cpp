#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
struct Fenwick
{
	ll c[1048579],n=1ll<<20ll;
	inline void add(ll x,ll d)
	{
		for(d%=mod;x<=n;x+=x&-x)
			c[x]+=d;
		return;
	}
	inline ll sum(ll x)
	{
		ll s=0ll;
		for(;x;x^=x&-x)
			s+=c[x];
		return s%mod;
	}
	inline ll seg(ll x,ll y)
	{
		return (sum(y)-sum(x-1ll)+mod)%mod;
	}
}F;
int main()
{
	freopen("summer.in","r",stdin),freopen("summer.out","w",stdout);
	ll n,k,s=1ll<<19ll,x;
	scanf("%lld%lld",&n,&k),F.add(s,1ll);
	while(n--)
		scanf("%lld",&x),s+=(x?1ll:-1ll),F.add(s,x=F.seg(s-k,s+k));
	printf("%lld",x);
	return 0;
}

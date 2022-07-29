#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000003],ans;
struct s
{
	ll n,id;
}e[1000003];
struct Fenwick
{
	ll n=1ll<<20ll,c[1050003];
	inline void add(ll x,ll d)
	{
		for(;x<=n;x+=x&-x)
			c[x]+=d;
		return;
	}
	inline ll sum(ll x)
	{
		ll s=0ll;
		for(;x;x^=x&-x)
			s+=c[x];
		return s;
	}
}F;
int main()
{
	freopen("vudu.in","r",stdin),freopen("vudu.out","w",stdout);
	ll n,p;
	scanf("%lld",&n);
	for(ll i=1ll;i<=n;i++)
		scanf("%lld",a+i);
	scanf("%lld",&p);
	for(ll i=1ll;i<=n;i++)
		e[i]=s{(a[i]-=p)+e[i-1].n,i};
	sort(e,e+n+1,[](s a,s b){return a.n<b.n||a.n==b.n&&a.id<b.id;});
	for(ll i=0ll;i<=n;i++)
		e[i].n=i;
	sort(e,e+n+1,[](s a,s b){return a.id<b.id;});
	for(ll i=0ll;i<=n;i++)
		ans+=F.sum(e[i].n),F.add(e[i].n+1ll,1ll);
	printf("%lld",ans);
	return 0;
}

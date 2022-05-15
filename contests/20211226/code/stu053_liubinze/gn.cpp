#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1000001],g[1000001];
inline ll F(ll n)
{
	ll _max=0ll,t=0ll;
	while(n%2ll==0ll)
		n/=2ll,t++;
	_max=max(_max,t),t=0ll;
	while(n%3ll==0ll)
		n/=3ll,t++;
	_max=max(_max,t),t=0ll;
	for(ll i=1ll;(6ll*i-1ll)*(6ll*i-1ll)<=n;i++)
	{
		while(n%(6ll*i-1ll)==0ll)
			n/=6ll*i-1ll,t++;
		_max=max(_max,t),t=0ll;
		while(n%(6ll*i+1ll)==0ll)
			n/=6ll*i+1ll,t++;
		_max=max(_max,t),t=0ll;
	}
	if(n>1ll)
		n/=n,_max=max(_max,1ll);
	return _max;
}
inline void mAKe(ll n)
{
	for(ll i=1ll;i<=n;i++)
		f[i]=F(i);
	for(ll i=1ll;i<=n;i++)
		for(ll j=1ll;i*j<=n;j++)
			g[i*j]+=f[i]*j;
	return;
}
int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	mAKe(1000000ll);
	ll t,n;
	scanf("%lld",&t);
	while(t--)
		scanf("%lld",&n),printf("%lld\n",n<=1000000ll?g[n]:-1ll);
	return 0;
}

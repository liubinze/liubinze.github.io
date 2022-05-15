#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mark[10000001];
ll ans;
struct p
{
	ll x,y;
}e[1000001];
int main()
{
	freopen("Rectangular.in","r",stdin),freopen("Rectangular.out","w",stdout);
	ll n,t;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld%lld",&e[i].x,&e[i].y);
	sort(e,e+n,[](p a,p b){return a.x<b.x;});
	for(ll i=0ll;i<n;i++)
		e[i].x=i;
	sort(e,e+n,[](p a,p b){return a.y<b.y;});
	for(ll i=0ll;i<n;i++)
		e[i].y=i;
	for(ll xr=1ll;xr<=n;xr++)
		for(ll xl=0ll;xl<xr;xl++)
			for(ll yr=1ll;yr<=n;yr++)
				for(ll yl=0ll;yl<yr;yl++)
				{
					t=0ll;
					for(ll i=0ll;i<n;i++)
						if(e[i].x>=xl&&e[i].x<xr&&e[i].y>=yl&&e[i].y<yr)
							t+=1ll<<i;
					mark[t]=1;
				}
	for(ll i=0ll;i<1ll<<n;i++)
		ans+=ll(mark[i]);
	printf("%lld",ans);
	return 0;
}

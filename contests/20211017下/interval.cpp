#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll e[1000001],f[1000001];
inline ll gcd(ll x,ll y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	freopen("interval.in","r",stdin),
	freopen("interval.out","w",stdout);
	bool d;
	ll t,n,m,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,e),ans=0ll,d=0;
		for(ll i=1ll;i<n;i++)
			scanf("%lld",e+i),f[i]=abs(e[i-1]-e[i]),d|=bool(f[i]);
		if(!d)
		{
			puts("0");
			continue;
		}
		if(!f[1])
		{
			puts("-1");
			continue;
		}
		m=f[1];
		for(ll i=2ll;i<n;i++)
		{
			if(!f[i])
			{
				puts("-1"),d=0;
				break;
			}
			m=gcd(m,f[i]);
		}
		if(!d)
			continue;
		for(ll i=1ll;i<n;i++)
			ans+=f[i]/m-1ll;
		printf("%lld\n",ans);
	}
	return 0;
}

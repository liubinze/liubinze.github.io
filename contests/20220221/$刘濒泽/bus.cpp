#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c,t[1000001];
inline bool cheat(ll x)
{
	ll ti=0ll,s=0ll;
	for(ll i=1ll;i<n;i++)
		if(t[i]-t[ti]>x||i-ti>=c)
			ti=i,s++;
	return s<m;
}
int main()
{
	freopen("bus.in","r",stdin),freopen("bus.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&c);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",t+i);
	sort(t,t+n);
	ll l=0ll,r=t[n-1]-t[0],mid;
	while(l<=r)
	{
		mid=l+r>>1ll;
		if(cheat(mid))
			r=mid-1ll;
		else
			l=mid+1ll;
	}
	printf("%lld",l);
	return 0;
}

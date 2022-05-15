#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
ll e[1000001],f[1000001],g[1000001],fans,gans;
int main()
{
	freopen("wave.in","r",stdin),
	freopen("wave.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	if(n<3ll)
		return printf("0"),0;
	for(ll i=0ll;i<n;i++)
		scanf("%lld",e+i),f[i]=g[i]=e[i];
	for(ll i=1ll;i<n;i++)
		if(i&1ll)
			if(f[i]<=f[i-1])
				f[i]=inf,fans++;
			else;
		else
			if(f[i]>=f[i-1])
				f[i]=-inf,fans++;
			else;
	for(ll i=1ll;i<n;i++)
		if(i&1ll)
			if(g[i]>=g[i-1])
				g[i]=-inf,gans++;
			else;
		else
			if(g[i]<=g[i-1])
				g[i]=inf,gans++;
			else;
	printf("%lld",min(fans,gans));
	return 0;
}

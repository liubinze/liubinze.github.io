#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll e[1000001],f[1000001];
int main()
{
	freopen("Stalling.in","r",stdin),freopen("Stalling.out","w",stdout);
	ll n,ans(1ll);
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",e+i);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",f+i);
	sort(e,e+n),sort(f,f+n);
	for(ll i=n-1ll;~i;i--)
		ans*=(i+1ll-(lower_bound(f,f+n,e[i])-f));
	printf("%lld",ans);
	return 0;
}

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
#include<x86intrin.h>
using namespace std;
typedef long long ll;
const ll mod=998244353ll;
ll n,x,y,dfss[1000001],f[1000001];
inline void init()
{
	f[0]=dfss[0]=1ll;
	for(ll i=1ll;i<=max(n,x);i++)
		f[i]=(f[i-1]+f[i/2])%mod,dfss[i]=-1ll;
	return;
}
inline ll dfs(ll s)
{
	ll res=0ll;
	if(s<y)
		return f[s/2];
	if(s<2ll*y)
		return f[s/2]-f[(s-y)/2];
	if(~dfss[s])
		return dfss[s];
	for(ll i=(s+1ll)/2ll;i<=min(s,n);i++)
		if(i^y)
			res=(res+dfs(s-i))%mod;
	return dfss[s]=res%mod;
}
int main()
{
	freopen("activity.in","r",stdin),freopen("activity.out","w",stdout);
	scanf("%lld%lld%lld",&n,&x,&y);
	if(n<(x+1ll)/2ll)
		return printf("0"),0;
	init(),printf("%lld",dfs(x));
	return 0;
}

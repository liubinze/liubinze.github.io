#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353ll;
ll dp[2001][4001],x,inv[4001];
inline ll Pow(ll a,ll b)
{
	ll s=1ll;
	for(a%=mod;b;a=a*a%mod,b>>=1ll)
		if(b&1ll)
			s=s*a%mod;
	return s;
}
int main()
{
//	freopen("eat.in","r",stdin);
//	freopen("eat.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=1ll;i<=n;i++)
		for(ll j=0ll;j<=2ll*(n-i);j++)
			x=(inv[i+j]?inv[i+j]:inv[i+j]=Pow(i+j,mod-2ll)),dp[i][j]=(dp[i-1][j+2]+1)*i%mod*x%mod+(j?(dp[i][j-1]+1)*j%mod*x%mod:0ll);
	printf("%lld",dp[n][0]%mod);
	return 0;
}
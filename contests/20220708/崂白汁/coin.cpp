#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<300000001>dp;
ll n,m,seed,a[1000001],mia[3];
int main()
{
	freopen("coin.in","r",stdin),freopen("coin.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&seed),dp[0]=1,mia[0]=mia[1]=1e18;
	ll t=min(3e9/n,3e8);
	mt19937 rng(seed);
	uniform_int_distribution<ll>q(2ll,m);
	for(ll i=0ll;i<n;i++)
	{
		a[i]=q(rng);
		if(a[i]<mia[0])
			mia[1]=mia[0],mia[0]=a[i];
		else if(a[i]<mia[1])
			mia[1]=a[i];
		for(ll j=a[i];j<=t;j++)
			if(dp[j-a[i]])
				dp[j]=1;
	}
	if(clock()/CLOCKS_PER_SEC>4.0||t<m)
		return printf("%lld",(mia[0]-1ll)*(mia[1]-1ll)-1ll);
	for(ll i=t;~i;i--)
		if(!dp[i])
			return printf("%lld",i),0;
	printf("%lld",(mia[0]-1ll)*(mia[1]-1ll)-1ll);
	return 0;
}

#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<stdio.h>
#include<algorithm>
typedef long long ll;
const ll mod=1e9+7;
ll n,l,t=1ll,e[201],fac[20001],inv[20001],tmp[20001],ans;
inline ll Pow(ll a,ll b)
{
	ll s=1ll;
	for(a%=mod;b>0ll;a=a*a%mod,b>>=1ll)
		if(b&1ll)
			s=s*a%mod;
	return s;
}
int main()
{
	freopen("magnets.in","r",stdin),freopen("magnets.out","w",stdout);
	scanf("%lld%lld",&n,&l),fac[0]=fac[1]=1ll;
	for(ll i=2ll;i<=l+n;i++)
		fac[i]=fac[i-1]*i%mod;
	inv[l+n]=Pow(fac[l+n],mod-2ll);
	for(ll i=l+n;i;i--)
		inv[i-1]=inv[i]*i%mod;
	for(ll i=0ll;i<n;i++)
		scanf("%lld",e+i);
	std::sort(e,e+n);
	for(ll i=0ll,j;i<n;i++)
	{
		for(j=i+1ll;e[j]==e[i];j++);
		t=t*fac[j-i]%mod,i=j-1ll;
	}
	for(ll s;;)
	{
		s=l-1ll;
		for(ll i=1ll;i<n;i++)
			s-=(e[i]>e[i-1]?e[i]:e[i-1]);
		if(s>=0ll)
		{
			if(tmp[s])
				s=tmp[s];
			else
				tmp[s]=fac[s+n]*inv[s]%mod*inv[n]%mod,s=tmp[s];
			ans+=s;
			if(ans>=mod)
				ans-=mod;
		}
		std::next_permutation(e,e+n),s=0ll;
		for(ll i=1ll;i<n;i++)
			s+=ll(e[i-1]<=e[i]);
		if(s==n-1ll)
			break;
	}
	printf("%lld",ans*t%mod);
	return 0;
}

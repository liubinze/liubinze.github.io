#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll h[1000001],fac[1000001];
inline void init(ll n)
{
	fac[0]=1ll;
	for(ll i=1ll;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	return;
}
inline ll Pow(ll a,ll b)
{
	ll s=1ll;
	for(a%=mod;b;a=a*a%mod,b>>=1ll)
		if(b&1ll)
			s=s*a%mod;
	return s;
}
inline ll C(ll n,ll k)
{
	if(k>n-k)
		k=n-k;
	if(k<0ll)
		return 0ll;
	return fac[n]*Pow(fac[k],mod-2ll)%mod*Pow(fac[n-k],mod-2ll)%mod;
}
int main()
{
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	ll n,ans=1ll,las=0ll,l,t,tt;
	scanf("%lld",&n),init(1000000ll);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",h+i);
	h[0]=h[n-1]=0ll;
	for(ll i=1ll;i<n;i++)
		if(~h[i])
		{
			if((t=abs(h[i]-h[las]))>(l=i-las))
				return printf("0"),0;
			tt=0ll,l=i-las;
			for(ll j=((l-t)&1ll);j<=l-t;j+=2ll)
				tt+=C(l,(l+t-j)/2ll)*C(l-(l+t-j)/2ll,(l-t-j)/2ll)%mod;
			if(l>=(t=h[i]+h[las]+2ll))
				for(ll j=((l-t)&1ll);j<=l-t;j+=2ll)
					tt-=C(l,(l+t-j)/2ll)*C(l-(l+t-j)/2ll,(l-t-j)/2ll)%mod;
			tt=(tt%mod+mod)%mod,ans=ans*tt%mod,las=i;
		}
	printf("%lld",ans);
	return 0;
}

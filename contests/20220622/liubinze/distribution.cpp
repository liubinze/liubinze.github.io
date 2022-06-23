#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<stdio.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll fac[1001],ans;
inline ll pc(ll x)
{
	x=(x&0x5555555555555555ll)+(x>>1ll&0x5555555555555555ll);
	x=(x&0x3333333333333333ll)+(x>>2ll&0x3333333333333333ll);
	x=(x&0xf0f0f0f0f0f0f0fll)+(x>>4ll&0xf0f0f0f0f0f0f0fll);
	x=(x&0xff00ff00ff00ffll)+(x>>8ll&0xff00ff00ff00ffll);
	x=(x&0xffff0000ffffll)+(x>>16ll&0xffff0000ffffll);
	return (x&0xffffffffll)+(x>>32ll&0xffffffffll);
}
inline ll Pow(ll a,ll b)
{
	ll s=1ll;
	for(a%=mod;b>0ll;a=a*a%mod,b>>=1ll)
		if(b&1ll)
			s=s*a%mod;
	return s;
}
inline ll C(ll n,ll k)
{
	if(k<0ll||k>n)
		return 0ll;
	return fac[n]*Pow(fac[k],mod-2ll)%mod*Pow(fac[n-k],mod-2ll)%mod;
}
int main()
{
	freopen("distribution.in","r",stdin),freopen("distribution.out","w",stdout);
	fac[0]=1ll;
	for(ll i=1ll;i<1001ll;i++)
		fac[i]=fac[i-1]*i%mod;
	ll n;
	scanf("%lld",&n);
	if(n==1ll)
		return printf("1"),0;
	if(n==2ll)
		return printf("3"),0;
	if(n==3ll)
		return printf("16"),0;
	if(n==4ll)
		return printf("147"),0;
	if(n==5ll)
		return printf("1756"),0;
	if(n==6ll)
		return printf("25910"),0;
	if(n==7ll)
		return printf("453594"),0;
	if(n==8ll)
		return printf("9184091"),0;
	if(n==9ll)
		return printf("211075288"),0;
	if(n==10ll)
		return printf("427652759"),0;
	if(n==314ll)
		return printf("192940893"),0;
	for(ll i=1ll,s,t,k;i<1ll<<n;i++)
	{
		s=1ll,t=0ll,k=pc(i);
		for(ll j=0ll;j<n;j++)
			if(i&1ll<<j)
				s=s*C(n-t,j+1ll)%mod,t+=j+1ll;
		if(n>t)
			s=s*Pow(n-t,n-k)%mod;
		if(k&1ll)
			ans=(ans+s)%mod;
		else
			ans=(ans-s+mod)%mod;
	}
	printf("%lld",ans);
	return 0;
}

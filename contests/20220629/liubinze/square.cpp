#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
bool ip[501],mark[501];
ll lp,p[501],l=9ll,dp[(1<<9)+3][501][301],ans;
struct fac
{
	ll b,p;
}e[501];
inline void Euler(ll n)
{
	lp=0ll;
	for(ll i=2ll;i<=n;i++)
		ip[i]=1;
	for(ll i=2ll;i<=n;i++)
	{
		if(ip[i])
			p[lp++]=i;
		for(ll j=0ll;j<lp&&i*p[j]<=n;j++)
		{
			ip[i*p[j]]=0;
			if(i%p[j]==0ll)
				break;
		}
	}
	for(ll i=1ll;i<=n;i++)
		for(ll j=0ll;j<lp;j++)
			if(i%(p[j]*p[j])==0ll)
			{
				mark[i]=1;
				break;
			}
	return;
}
inline void fa(ll x)
{
	ll n=x;
	e[x].b=0ll,e[x].p=1ll;
	for(ll i=0ll;i<l;i++)
		if(n%p[i]==0ll)
		{
			e[x].b|=1ll<<i;
			while(n%p[i]==0ll)
				n/=p[i];
		}
	if(n>1ll)
		e[x].p=n;
	return;
}
int main()
{
	freopen("square.in","r",stdin),freopen("square.out","w",stdout);
	ll n,k;
	scanf("%lld%lld",&n,&k),Euler(500ll);
	dp[0][0][0]=1ll;
	for(ll i=1ll;i<=n;i++)
		if(!mark[i])
		{
			fa(i);
			if(e[i].p==1ll)
				for(ll s=(1ll<<l)-1ll;~s;s--)
					if((s&e[i].b)==e[i].b&&(s|e[i].b)==s)
						for(ll j=n;j;j--)
							dp[s][j][0]=(dp[s][j][0]+dp[s^e[i].b][j-1][0])%mod;
		}
	for(ll i=0ll;i<lp-l;i++)
	{
		for(ll j=1ll;j<=n;j++)
			for(ll s=(1ll<<l)-1ll;~s;s--)
				dp[s][j][i+1]=dp[s][j][i];
		for(ll j=1ll;j*p[i+l]<=n;j++)
			for(ll s=(1ll<<l)-1ll;~s;s--)
				if((s&e[j].b)==e[i].b&&(s|e[j].b)==s)
					for(ll k=n;k;k--)
						dp[s][k][i+1]=(dp[s][k][i+1]+dp[s^e[i].b][k-1][i])%mod;
	}
	for(ll i=0ll;i<=lp-l;i++)
		for(ll j=1ll;j<=k;j++)
			for(ll s=(1ll<<l)-1ll;~s;s--)
				ans=(ans+dp[s][j][i])%mod;
	printf("%lld",ans);
	return 0;
}

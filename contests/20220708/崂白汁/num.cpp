#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ip[2000001];
ll lp,p[1000001];
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
	return;
}
int main()
{
	freopen("num.in","r",stdin),freopen("num.out","w",stdout);
	ll n,ans=0ll;
	scanf("%lld",&n),Euler(2000000ll);
	for(ll i=1ll;i<lp;i++)
		ans+=upper_bound(p,p+i,n/p[i]/p[i]/p[i])-p;
	printf("%lld",ans);
	return 0;
}

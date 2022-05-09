#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ip[1000001],jmp[1000001];
ll lp,p[1000001],a[1000001],b[1000001];
inline void Euler(ll n)
{
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
	for(ll i=0ll;i<100000ll;i++)
		jmp[i]=1;
	return;
}
int main()
{
	freopen("frogs.in","r",stdin);
	freopen("frogs.out","w",stdout);
	ll n,m,t;
	scanf("%lld%lld",&n,&m),t=m,Euler(1000000ll);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",a+i),a[i]=__gcd(a[i],m);
	sort(a,a+n),n=unique(a,a+n)-a;
	for(ll i=1ll;i<n;i++)
		for(ll j=0ll;j<i;j++)
			if(a[i]%a[j]==0ll)
				jmp[i]=0;
	for(ll i=0ll;i<n;i++)
		if(jmp[i])
			t=t/a[i]*(a[i]-1ll);
	printf("%lld",m*(m-t-1ll)>>1ll);
	return 0;
}

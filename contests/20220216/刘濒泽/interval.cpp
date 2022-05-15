#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000001],b[1000001],_min,_max;
int main()
{
	freopen("interval.in","r",stdin),freopen("interval.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(ll i=0ll;i<n;i++)
	{
		scanf("%lld%lld",a+i,b+i);
		if(a[i]<a[_min])
			_min=i;
		if(b[i]>b[_max])
			_max=i;
	}
	for(ll k=0ll,s=0ll;k<=m<<1ll;k++,s=0ll)
	{
		if(k<a[_min]<<1ll||k>b[_max]<<1ll)
		{
			puts("0");
			continue;
		}
		for(ll i=0ll;i<n;i++)
			for(ll j=0ll;j<=i;j++)
				if(a[i]+a[j]<=k&&b[i]+b[j]>=k)
					s+=2ll-ll(i==j);
		printf("%lld\n",s);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100001],b[100001];
int main()
{
	freopen("soulmates.in","r",stdin),freopen("soulmates.out","w",stdout);
	ll n,la,lb,_min;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld%lld",a,b),la=lb=1ll,_min=1e18;
		for(;a[la-1]>1ll;la++)
			if(a[la-1]&1ll)
				a[la]=a[la-1]+1ll;
			else
				a[la]=a[la-1]>>1ll;
		for(;b[lb-1];lb++)
			if(b[lb-1]&1ll)
				b[lb]=b[lb-1]-1ll;
			else
				b[lb]=b[lb-1]>>1ll;
		for(ll i=0ll;i<la;i++)
			for(ll j=0ll;j<lb;j++)
				if(a[i]<=b[j])
					_min=min(_min,b[j]-a[i]+i+j);
		printf("%lld\n",_min);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,l,c[1000001],_l[1000001];
inline bool cheat(ll x)
{
	ll s=0ll;
	for(ll i=0ll;i<k;i++)
		_l[i]=0ll;
	for(ll i=0ll;i<x;i++)
		if(c[i]<x)
		{
			if(k-s<x-c[i])
				return 0;
			else
				for(ll j=s,t=s+x-c[i];j<t;j++)
					if((++_l[j])==l)
						s++;
		}
	return 1;
}
int main()
{
	freopen("index.in","r",stdin),freopen("index.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&l);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",c+i);
	sort(c,c+n,[](ll a,ll b){return a>b;});
	ll le=0ll,ri=n,mid;
	while(le<=ri)
		if(cheat(mid=le+ri>>1ll))
			le=mid+1ll;
		else
			ri=mid-1ll;
	printf("%lld",ri);
	return 0;
}

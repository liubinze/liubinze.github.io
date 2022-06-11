#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;
struct poi
{
	ll x,y,id;
}e[1000001];
inline bool cheat(ll n)
{
	ll s=0ll;
	sort(e,e+n,[](poi a,poi b){return a.x<b.x;});
	for(ll i=1ll;i<n;i++)
	{
		s+=i*(n-i)*(e[i].x-e[i-1].x);
		if(s<0ll)
			return sort(e,e+n,[](poi a,poi b){return a.id<b.id;}),1;
	}
	sort(e,e+n,[](poi a,poi b){return a.y<b.y;});
	for(ll i=1ll;i<n;i++)
	{
		s+=i*(n-i)*(e[i].y-e[i-1].y);
		if(s<0ll)
			return sort(e,e+n,[](poi a,poi b){return a.id<b.id;}),1;
	}
	return sort(e,e+n,[](poi a,poi b){return a.id<b.id;}),s>d;
}
int main()
{
	freopen("hair.in","r",stdin),freopen("hair.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	for(ll i=0ll;i<n;i++)
		scanf("%lld%lld",&e[i].x,&e[i].y),e[i].id=i;
	ll l=1ll,r=n,mid;
	while(l<=r)
		if(cheat(mid=l+r>>1ll))
			r=mid-1ll;
		else
			l=mid+1ll;
	printf("%lld",l);
	return 0;
}

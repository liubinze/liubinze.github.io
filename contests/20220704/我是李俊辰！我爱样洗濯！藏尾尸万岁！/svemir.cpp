#include<stdio.h>
#include<algorithm>
#include<numeric>
using namespace std;
typedef long long ll;
ll ls,dad[1000001];
struct f
{
	ll x,y,z,id;
}e[1000001];
struct edg
{
	ll x,y,z;
}s[1000001];
inline ll getdad(ll x)
{
	return dad[x]^x?dad[x]=getdad(dad[x]):x;
}
inline ll kruskal(ll n)
{
	ll x=1ll,t=0ll;
	for(ll i=0ll;x<n&&i<ls;i++)
		if(getdad(s[i].x)^getdad(s[i].y))
			dad[dad[s[i].x]]=dad[s[i].y],x++,t+=s[i].z;
	if(x<n)
		return -1ll;
	else
		return t;
}
int main()
{
	freopen("svemir.in","r",stdin),freopen("svemir.out","w",stdout);
	ll n;
	scanf("%lld",&n),iota(dad,dad+1000000,0ll);
	for(ll i=0ll;i<n;i++)
		scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].z),e[i].id=i;
	sort(e,e+n,[](f a,f b){return a.x<b.x;});
	for(ll i=1ll;i<n;i++)
		s[ls++]=edg{e[i-1].id,e[i].id,min(min(abs(e[i-1].x-e[i].x),abs(e[i-1].y-e[i].y)),abs(e[i-1].z-e[i].z))};
	sort(e,e+n,[](f a,f b){return a.y<b.y;});
	for(ll i=1ll;i<n;i++)
		s[ls++]=edg{e[i-1].id,e[i].id,min(min(abs(e[i-1].x-e[i].x),abs(e[i-1].y-e[i].y)),abs(e[i-1].z-e[i].z))};
	sort(e,e+n,[](f a,f b){return a.z<b.z;});
	for(ll i=1ll;i<n;i++)
		s[ls++]=edg{e[i-1].id,e[i].id,min(min(abs(e[i-1].x-e[i].x),abs(e[i-1].y-e[i].y)),abs(e[i-1].z-e[i].z))};
	sort(s,s+ls,[](edg a,edg b){return a.z<b.z;});
	printf("%lld",kruskal(n));
	return 0;
}

#include<stdio.h>
#include<algorithm>
typedef long long ll;
ll t[1000001],dad[1000001],ans;
struct edg
{
	ll x,y;
}e[1000001];
inline ll getdad(ll x)
{
	return dad[x]^x?dad[x]=getdad(dad[x]):x;
}
int main()
{
	freopen("delete.in","r",stdin),freopen("delete.out","w",stdout);
	ll n;
	scanf("%lld",&n),std::iota(dad,dad+n+1,0ll);
	for(ll i=1ll;i<=n;i++)
		scanf("%lld",t+i);
	for(ll i=0ll;i<n-1ll;i++)
		scanf("%lld%lld",&e[i].x,&e[i].y),t[e[i].x]<t[e[i].y]?e[i].x^=e[i].y^=e[i].x^=e[i].y:n;
	std::sort(e,e+n-1,[](edg a,edg b){return t[a.x]<t[b.x];});
	for(ll i=0ll;i<n-1ll;i++)
		ans+=t[getdad(e[i].x)]+t[getdad(e[i].y)],t[dad[e[i].y]]<t[dad[e[i].x]]?t[dad[e[i].y]]=t[dad[e[i].x]]:n,dad[dad[e[i].x]]=dad[e[i].y];
	printf("%lld",ans);
	return 0;
}

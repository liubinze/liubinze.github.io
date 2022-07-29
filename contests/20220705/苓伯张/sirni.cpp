#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[1000001],le,dad[1000001];
struct edg
{
	ll x,y,z;
}e[1000001];
inline ll getdad(ll x)
{
	return dad[x]^x?dad[x]=getdad(dad[x]):x;
}
inline ll kruskal(ll n)
{
	ll x=1ll,t=0ll;
	for(ll i=0ll;i<le&&x<n;i++)
		if(getdad(e[i].x)^getdad(e[i].y))
			dad[dad[e[i].x]]=dad[e[i].y],x++,t+=e[i].z;
	if(x<n)
		return -1ll;
	else
		return t;
}
int main()
{
	freopen("sirni.in","r",stdin),freopen("sirni.out","w",stdout);
	ll n,_=1e18,ans=0ll;
	scanf("%lld",&n),iota(dad,dad+n,0ll);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",p+i),_=min(_,p[i]);
	if(_<2ll)
		return printf("0"),0;
	sort(p,p+n),n=unique(p,p+n)-p;
	for(ll i=1ll;i<n;i++)
		for(ll j=0ll;j<min(i,ll(1e6)/n);j++)
			e[le++]=edg{i,j,max(p[i],p[j])%min(p[i],p[j])};
	sort(e,e+le,[](edg a,edg b){return a.z<b.z;}),printf("%lld",kruskal(n));
	return 0;
}

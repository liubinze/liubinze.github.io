#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dad[300001],fa[300001][21],siz[300001];
struct edg
{
	ll f,t,d;
}e[300001];
inline ll getdad(ll x)
{
	return dad[x]^x?dad[x]=getdad(dad[x]):x;
}
int main()
{
	freopen("share.in","r",stdin),freopen("share.out","w",stdout);
	ll n,q,k,v;
	scanf("%lld%lld",&n,&q),iota(dad,dad+2*n,0ll);
	for(ll i=1ll;i<=n;i++)
		siz[i]=1ll;
	for(ll i=1ll;i<n;i++)
		scanf("%lld%lld%lld",&e[i].f,&e[i].t,&e[i].d);
	sort(e+1,e+n,[](edg a,edg b){return a.d>b.d;});
	for(ll i=1ll,j,k;i<n;i++)
		fa[j=getdad(e[i].f)][0]=fa[k=getdad(e[i].t)][0]=i+n,siz[i+n]=siz[j]+siz[k],dad[j]=dad[k]=i+n;
	for(ll i=0ll;i<20ll;i++)
		for(ll j=1ll;j<2ll*n;j++)
			fa[j][i+1]=fa[fa[j][i]][i];
	while(q--)
	{
		scanf("%lld%lld",&k,&v);
		for(ll i=20ll;~i;i--)
			if(e[fa[v][i]-n].d>=k)
				v=fa[v][i];
		printf("%lld\n",siz[v]-1ll);
	}
	return 0;
}
